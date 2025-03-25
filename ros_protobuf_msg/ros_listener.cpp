#include <chrono>
#include "ros/ros.h"
#include <pcl/io/pcd_io.h> 
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>

static bool save_trigger = true;

void chatterCallback(const sensor_msgs::PointCloud2::ConstPtr &msg) {
    if(save_trigger){
        try {
            save_trigger = false;
            pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZI>);
            pcl::fromROSMsg(*msg, *pcl_cloud);
            // 保存为二进制格式PCD文件
            const std::string filename = "/work/first_frame.pcd";
            if (pcl::io::savePCDFileBinary(filename, *pcl_cloud) == 0) {
                ROS_INFO_STREAM("Successfully saved point cloud to: " << filename);
            } else {
                ROS_ERROR("Failed to save PCD file!");
            }
            // 打印点云信息
            std::cout << "Received cloud: " 
                    << pcl_cloud->width << "x" << pcl_cloud->height 
                    << " (" << pcl_cloud->size() << " points)" << std::endl;
            } catch (const std::exception& e) {
            ROS_ERROR_STREAM("PCD Save Error: " << e.what());

        }

    }
}


int main(int argc, char **argv) {
  ros::init(argc, argv, "ros_listener");

  ros::NodeHandle n;

  // ros::Subscriber sub1 = n.subscribe("/Excavator_SY60C", 10, chatterCallback);
  ros::Subscriber sub2 = n.subscribe("/ros_cloud", 10, chatterCallback);

  ros::spin();

  return 0;
}
