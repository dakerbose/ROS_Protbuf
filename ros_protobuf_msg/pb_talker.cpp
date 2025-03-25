#include <ros/protobuffer_traits.h>
#include <ros/serialization_protobuffer.h>
#include "ros/ros.h"
#include "publish_info.pb.h"
#include <chrono>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "pb_talker");
  ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME,
                                 ros::console::levels::Debug);
  ros::NodeHandle n;

  // ros::Publisher pub =
  //     n.advertise<Excavator::data::PublishInfo>("/Excavator_SY60C", 1000);
  ros::Publisher cloud_pub = 
      n.advertise<Excavator::data::PointCloud>("/pb_cloud", 1);

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
  while (ros::ok()) {
    // pub.publish(proto_msg_info);
    // std::cerr << "DebugMsg: " << proto_msg_info.DebugString() << std::endl;
    // static bool flag_time_pub = true;
    // if(flag_time_pub)
    // {
      // flag_time_pub = false;
      // auto send_time = std::chrono::high_resolution_clock::now().time_since_epoch();
      // uint64_t send_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(send_time).count();
      // proto_point_cloud.set_send_time_ns(send_time_ns);
      // ROS_INFO_STREAM("Publishing at: " << proto_point_cloud.send_time_ns());
    // }
    static bool flag = true;
    if(flag){
      flag = false;
      cloud_pub.publish(proto_point_cloud);
    }
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
