#include <ros/protobuffer_traits.h>
#include <ros/serialization_protobuffer.h>
#include <chrono>
#include "ros/ros.h"
#include <pcl/io/pcd_io.h> 
#include "publish_info.pb.h"
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
static uint8_t save_trigger = 0;
ros::Publisher confirm_pub;
// void chatterCallback(
//     const ros::MessageEvent<Excavator::data::PublishInfo> &msg) {
//   std::cerr << "I heard: " << msg.getMessage()->DebugString() << std::endl;
//   std::string def =
//       ros::message_traits::Definition<Excavator::data::PublishInfo>::value();
//   std::cout << "def: " << def << std::endl;
// }

void chatterCallbackLidar(const ros::MessageEvent<Excavator::data::PointCloud> &msg) {
  
  if(save_trigger++ < 10){ // 自己改就行
    // auto recv_time = std::chrono::high_resolution_clock::now().time_since_epoch();
    // uint64_t recv_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(recv_time).count();
    const Excavator::data::PointCloud* pointCloudMsg = msg.getMessage().get();
    // // uint64_t recv_time_ns = ros::TIme::now().toNSec();
    // uint64_t latency_ns = recv_time_ns - pointCloudMsg->send_time_ns();
  
    // ROS_INFO_STREAM("Message latency: " << latency_ns << " ns");
    // ROS_DEBUG_STREAM("Send time: " << pointCloudMsg->send_time_ns() 
    //                << " | Receive time: " << recv_time_ns);
    // save_trigger = false;
    
    pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZI>);
    // 转换Protobuf到PCL格式
    for (const auto& proto_point : pointCloudMsg->points()) {
      pcl::PointXYZI pcl_point;
      pcl_point.x = proto_point.x();
      pcl_point.y = proto_point.y();
      pcl_point.z = proto_point.z();
      pcl_point.intensity = proto_point.intensity();
      pcl_cloud->push_back(pcl_point);
    }
    pcl_cloud->width = pcl_cloud->size();
    pcl_cloud->height = 1;
    pcl_cloud->is_dense = true;

    try {
      // 保存为二进制格式PCD文件
      const std::string filename = "/work/first_frame.pcd";
      if (pcl::io::savePCDFileBinary(filename, *pcl_cloud) == 0) {
        ROS_INFO_STREAM("Successfully saved point cloud to: " << filename);
      } else {
        ROS_ERROR("Failed to save PCD file!");
      }
    } catch (const std::exception& e) {
      ROS_ERROR_STREAM("PCD Save Error: " << e.what());
    }
    // 打印消息的定义
    std::string def = ros::message_traits::Definition<Excavator::data::PointCloud>::value();
    std::cerr << "Message Definition: " << def << std::endl;

    // 打印前几个点的信息
    //std::cerr << "I heard: " << pointCloudMsg->points_size() << " points." << std::endl;

    const int num_points_to_print = 5;  // 设置要打印的点的数量
    for (int i = 0; i < 5; ++i) {
        const Excavator::data::Point& point = pointCloudMsg->points(i);
        std::cerr << "Point " << i << ": (" 
                  << point.x() << ", " 
                  << point.y() << ", " 
                  << point.z() << ", "
                  << point.intensity() << ")" << std::endl;
    }   
    std::msgs::Bool confirm_msg;
    confirm_msg.data = true;
    confirm_pub.publish(confirm_msg);
    ROS_INFO("Sent confirmation.");
  }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "pb_listener");

  ros::NodeHandle n;

  // ros::Subscriber sub1 = n.subscribe("/Excavator_SY60C", 10, chatterCallback);
  ros::Subscriber sub2 = n.subscribe("/pb_cloud", 10, chatterCallbackLidar);
  confirm_pub = n.advertise<std_msgs::Bool>("/confirmation", 1);
  ros::spin();

  return 0;
}
