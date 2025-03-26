#include <ros/protobuffer_traits.h>
#include <ros/serialization_protobuffer.h>
#include "ros/ros.h"
#include "publish_info.pb.h"
#include <chrono>
#include <mutex>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool confirmed = false;

void confirmationCallback(const std_msgs::Bool::ConstPtr& msg) {
  if (msg->data) {
      std::lock_guard<std::mutex> lock(mtx);
      confirmed = true;
      cv.notify_one();  // 通知等待线程
      ROS_INFO("Received confirmation.");
  }
}

std::atomic<bool> confirmed(false);

void confirmationCallback(const std_msg::Bool::ConstPtr &msg){
  if(msg->data){
    confirmed = true;
  }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "pb_talker");
  ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME,
                                 ros::console::levels::Debug);
  ros::NodeHandle n;

  // ros::Publisher pub =
  //     n.advertise<Excavator::data::PublishInfo>("/Excavator_SY60C", 1000);
  ros::Publisher cloud_pub = 
      n.advertise<Excavator::data::PointCloud>("/pb_cloud", 1);
  ros::Subscriber confirm_sub = n.subscribe("/confirmation", 1, confirmationCallback);

  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>);

  if (pcl::io::loadPCDFile<pcl::PointXYZI>("/work/0.pcd", *cloud) == -1) {
    ROS_ERROR("Failed to load PCD file!");
    return -1;
  }
  std::cout << "Number of points in cloud: " << cloud->size() << std::endl;
  ros::Rate loop_rate(10);
  
  // Excavator::data::PublishInfo proto_msg_info;
  // proto_msg_info.set_topic_name("Excavator_SY60C");
  // proto_msg_info.set_message_type("Excavator data");
  // proto_msg_info.set_queue_size(10);
  // proto_msg_info.set_is_latched(true);
  // proto_msg_info.add_vector_test(3.25);
  // proto_msg_info.add_vector_test(6.75);
  // proto_msg_info.add_vector_test(7.5);
  ROS_INFO("Debug Excavtor sensor");
  Excavator::data::PointCloud proto_point_cloud;
  // Fill the Protobuf PointCloud message with points from PCL cloud
  for (const auto& point : cloud->points) {
    Excavator::data::Point* proto_point = proto_point_cloud.add_points();
    proto_point->set_x(point.x);
    proto_point->set_y(point.y);
    proto_point->set_z(point.z);
    proto_point->set_intensity(point.intensity);
  }
  int count = 0;

  while (ros::ok() && cloud_pub.getNumSubscribers() < 1) {
        ROS_INFO("Waiting for subscriber to connect...");
        ros::spinOnce();
        loop_rate.sleep();
  }

    // 首次发布
    cloud_pub.publish(proto_point_cloud);
    ROS_INFO("Published first message.");

    while (ros::ok()) {
        // 使用条件变量等待确认
        {
            std::unique_lock<std::mutex> lock(mtx);
            if (cv.wait_for(lock, std::chrono::seconds(1), [] { return confirmed; })) {
                ROS_INFO("Confirmation received.");
            } else {
                ROS_WARN("Timeout waiting for confirmation!");
            }
            confirmed = false;  // 重置确认标志
        }

        // 发布下一条消息
        cloud_pub.publish(proto_point_cloud);
        ROS_INFO("Published next message.");
        ros::spinOnce();  // 处理回调
        loop_rate.sleep();
    }

  return 0;
}
