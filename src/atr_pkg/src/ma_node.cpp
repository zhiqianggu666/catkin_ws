#include <ros/ros.h>
#include <std_msgs/String.h>
#include <qq_msgs/Carry.h>

//回调函数，类似中断函数，当一个新的消息包到达订阅者节点时，ros系统自动调用这个回调函数
//回调函数接用msg 接收类型为String的消息包。函数中可以对msg进行处理。
void chao_callback(qq_msgs::Carry msg)
{
    ROS_INFO(msg.grade.c_str());     //ctrl+shift+p输入error squiggles 选择禁用错误波形。在scode的setting
    ROS_WARN("%d星",msg.star);
    ROS_INFO(msg.data.c_str());

}

void yao_callback(std_msgs::String msg)
{
    ROS_WARN(msg.data.c_str());
}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    //文件初始化
    ros::init(argc,argv,"ma_node");

    //定义大管家
    ros::NodeHandle nh;

    //利用大管家创建 接收 话题工具sub 。创建了两个接收工具（节点）分别接收两个话题中的消息，并通过两个回调函数进行处理。
    ros::Subscriber sub = nh.subscribe("kaihei",10,chao_callback);
    ros::Subscriber sub2 =nh.subscribe("geigei_daiwo",10,yao_callback);
    while(ros::ok())
    {
        ros::spinOnce();
    }

    return 0;
}




