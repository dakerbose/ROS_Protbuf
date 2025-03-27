#include "ros/ros.h"
#include <sensor_msgs/PointCloud2.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl_conversions/pcl_conversions.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "ros_talker");
  ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME,
                                 ros::console::levels::Debug);
  ros::NodeHandle n;

  // ros::Publisher pub =
  //     n.advertise<Excavator::data::PublishInfo>("/Excavator_SY60C", 1000);
  // ros::Publisher cloud_pub = 
  //     n.advertise<Excavator::data::PointCloud>("/ros_cloud", 1);
  ros::Publisher pub = 
      n.advertise<sensor_msgs::PointCloud2>("/ros_cloud", 1);

  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>);

  if (pcl::io::loadPCDFile<pcl::PointXYZI>("/work/80MB.pcd", *cloud) == -1) {
    ROS_ERROR("Failed to load PCD file!");
    return -1;
  }
  std::cout << "Number of points in cloud: " << cloud->size() << std::endl;
  sensor_msgs::PointCloud2 cloud_msg;
  pcl::toROSMsg(*cloud, cloud_msg);
  cloud_msg.header.frame_id = "livox_frame";  // 设置坐标系
  ros::Rate loop_rate(10);

  ROS_INFO("Debug Excavtor sensor");
  // Fill the Protobuf PointCloud message with points from PCL cloud
  int count = 0;
  while (ros::ok()) {
    // std::cerr << "DebugMsg: " << proto_msg_info.DebugString() << std::endl;
    cloud_msg.header.stamp = ros::Time::now();
    static bool flag = true;
    if(flag)
    {
      flag = false;
      pub.publish(cloud_msg);
    }
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
