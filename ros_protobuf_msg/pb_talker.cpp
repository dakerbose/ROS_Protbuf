#include <ros/protobuffer_traits.h>
#include <ros/serialization_protobuffer.h>
#include "ros/ros.h"
#include "publish_info.pb.h"
#include <sensor_msgs/PointCloud2.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl_conversions/pcl_conversions.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "pb_talker");
  ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME,
                                 ros::console::levels::Debug);
  ros::NodeHandle n;

  ros::Publisher pub =
      n.advertise<Excavator::data::PublishInfo>("/Excavator_SY60C", 1000);
  ros::Publisher cloud_pub = 
      n.advertise<Excavator::data::PointCloud>("/livox_pointcloud", 1);

  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>);

  if (pcl::io::loadPCDFile<pcl::PointXYZI>("/work/0.pcd", *cloud) == -1) {
    ROS_ERROR("Failed to load PCD file!");
    return -1;
  }
  std::cout << "Number of points in cloud: " << cloud->size() << std::endl;
  sensor_msgs::PointCloud2 cloud_msg;
  pcl::toROSMsg(*cloud, cloud_msg);
  cloud_msg.header.frame_id = "livox_frame";  // 设置坐标系
  ros::Rate loop_rate(10);
  
  Excavator::data::PublishInfo proto_msg_info;
  proto_msg_info.set_topic_name("Excavator_SY60C");
  proto_msg_info.set_message_type("Excavator data");
  proto_msg_info.set_queue_size(10);
  proto_msg_info.set_is_latched(true);
  proto_msg_info.add_vector_test(3.25);
  proto_msg_info.add_vector_test(6.75);
  proto_msg_info.add_vector_test(7.5);
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
    pub.publish(proto_msg_info);
    std::cerr << "DebugMsg: " << proto_msg_info.DebugString() << std::endl;
    cloud_msg.header.stamp = ros::Time::now();
    cloud_pub.publish(proto_point_cloud);
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
