# dev分支 主要用于测试平均处理时间，因为时间选择连续时间很不准确

附件的问题可能有点不准确 因为我作了覆盖emmmm
# 实验环境

``` shell
# 安装docker 建议学会自己搭建翻墙节点 docker安装要这个
sudo apt install curl
curl -fsSL https://test.docker.com -o test-docker.sh
sudo sh test-docker.sh
# 用户添加到组
sudo groupadd docker
sudo usermod -aG docker ${USER}
sudo systemctl restart docker
newgrp docker
docker ps 
# 路径找到.dockerfile文件
cd ~/work/ros_protobuf_msg/docker/build
# 构建docker环境
docker build --network host -t ros_protobuf:noetic  -f ros_x86.dockerfile .
# 构建好后 查看镜像
docker images
```

进行操作
```shell
# 所有操作都在docker下面 
# 进入docker环境 
./ros_docker_into.sh
# 如果不能进入就重启dokcer 
./ros_docker_run.sh

# docker环境默认的是/work
mkdir build
cd build 
cmake ..
make
```
# wireshark

any中筛选 tcp.port == 11311 || (tcp.port >= 10000 && tcp.port <= 60000)

![alt text](image.png)

重点查找11311后面的几个

查找发送结束时间后的
![alt text](image-1.png)
# 回环测试

## 测试了80MB点云的传输，记录结果在result中
```
roscore 
先运行rosrun excavator_extension ros_listener
再运行rosrun excavator_extension ros_talker
```
代码我是配置了的 只发送一次消息 不然单次测试很容易时间冲突 我不认为频繁发送可以省力 因为准确性差很多

ros1 2.00835 2.16760 196

ros2 3.18160 3.30238 228

ros3 3.16315 3.27160 265

ros4 5.12395 5.22556 199

ros5 3.24825 3.48520 276

ros6 11.21363 11.32553 237

ros7 3.12336 3.23602 223

ros8 3.19514 3.29618 163

ros9 3.20327 3.30311 158

ros10 4.49644  4.66242 326

pb1 6.94691 7.07962 300

pb2 5.05384 5.15728 251

pb3 4.88996 4.96795 148

pb4 8.09752 8.22150 304

pb5 4.71785 4.81114 229

pb6 4.70118 4.77881 272

pb7 7.50821 7.58300 148

pb8 5.04645 5.18486 258

pb9 4.78948 4.87683 176

pb10 4.82013 4.93025 261

## 测试了100MB点云的传输，记录结果在result中

pb1  7.10529    7.23870  397
pb2  6.94037    7.23917  158
pb3  5.63114    5.72884  185
pb4  7.88408    8.00677  570
pb5  5.24530    5.33362  263
pb6  3.92544    4.02210  321
pb7  5.52167    5.66265  181
pb8  7.45352    7.58596  348
pb9  5.32087    5.46609  263
pb10  8.51154   8.60890  293

ros1 3.59926    3.89391  685
ros2 3.17292    3.44502  171
ros3 3.44560    3.61279  271
ros4 3.27706    3.46795  687
ros5 10.14123   10.29734  257
ros6  9.54084   9.70584   508
ros7 2.64066    2.86236   484 
ros8 4.87881    5.04602   269
ros9  15.60074   15.83144  418
ros10 4.86510    5.19453   250