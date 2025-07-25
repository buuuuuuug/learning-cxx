// msg_server.cpp 
#include <iostream>
#include <map>
#include <functional>
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
private:
    //根据消息的key调用函数对象
    map<string, MsgCall> calls_;

};
int main()
{
    MsgServer server;
    server.Reg("post", [](const Msg& msg) {

        cout << "reg post test post msg" << endl;
        });
    server.Distribute({ "post","test post data" });

}
