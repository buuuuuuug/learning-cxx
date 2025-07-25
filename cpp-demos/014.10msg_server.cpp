// msg_server.cpp 
#include <iostream>
#include <map>
#include <functional>
#include <queue>
#include <thread>
using namespace std;
struct Msg
{
    string key;
    string data;
};
//1 消息注册
class MsgServer
{
public:
    using MsgCall = function<void(const Msg&)>;
    //////////////////////////////////////////////////////
    // 根据key关联函数对象
    // 注册消息处理回调
    ///@para key 消息的关键字，用于查找函数
    ///@para call 回调函数
    void Reg(string key, MsgCall call)
    {
        calls_[key] = call;
    }

    /// <summary>
    /// 转发消息
    /// </summary>
    void Distribute(const Msg& msg)
    {
        auto ptr = calls_.find(msg.key);
        if (ptr == calls_.end())return;
        ptr->second(msg);
        //calls_[msg.key](msg);
    }

    //存储用户发送的消息
    // 缓存msg
    void Send(const Msg& msg)
    {
        msgs_.push(msg);
    }

    /// <summary>
    /// 启动消息处理线程
    /// </summary>
    void Start()
    {
        th_ = thread(&MsgServer::Run, this);
    }
    /// <summary>
    /// 等待现场退出
    /// </summary>
    void Wait() { if (th_.joinable())th_.join(); }
    void Stop() { is_exit_ = true; }
private:
    //消息处理线程函数
    void Run()
    {
        cout << __FUNCSIG__ << endl;
        while (!is_exit_) //消息处理主循环
        {
            //读取消息队列数据
            if (msgs_.empty())continue;
            //取第一个数据
            Msg msg = msgs_.front();
            msgs_.pop();//清掉第一个数据
            Distribute(msg);
        }
    }
    //根据消息的key调用函数对象
    map<string, MsgCall> calls_;

    //消息缓存队列
    queue<Msg> msgs_;

    //处理缓存消息和转发的现场
    thread th_;

    //线程是否退出
    bool is_exit_{ false };


};
int main()
{
    MsgServer server;
    server.Reg("post", [](const Msg& msg) {
        cout << "reg post test post msg "
            <<msg.key<<":"
            << msg.data
            << endl;
        });
    Msg msg{ "post","test post data" };
    server.Send(msg);
    server.Send(msg);
    server.Start();
    this_thread::sleep_for(3s);
    server.Stop();
    server.Wait();

    //server.Distribute(msg);

}
