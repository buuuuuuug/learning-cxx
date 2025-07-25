// test_thread.cpp 
#include <iostream>
#include <thread>
using namespace std;

void TestThread(string str)
{
    //释放cpu占用时间 1秒 1s 100ms
    this_thread::sleep_for(100ms);
    cout << this_thread::get_id() << endl;
    cout << "call TestThread " << str << endl;
}

class Task
{
public:
    void Run()
    {
        cout << "Task::Run()" << endl;
    }
    void Start()
    {
        th_ = thread(&Task::Run, this);
    }
    void Wait() {
        if(th_.joinable())
            th_.join();
    }
private:
    thread th_;
};
int main() //主线程
{
    //获取线程的ID号
    cout <<"主线程："
        << this_thread::get_id() 
        << endl;
    //启动线程
    thread th1(
        [] {
            cout << this_thread::get_id() 
            <<"lamda thread\n";
        }
    );
    cout << "end begin thread" << endl;
    //th1.detach(); //释放管理权，影响不确定
    th1.join();//阻塞等待线程结束
    thread th2;
    th2 = thread(TestThread
        , "test string");

    th2.join();
    Task task;
    thread th3(&Task::Run, &task);
    th3.join();//等待线程结束
    task.Start();
    task.Wait();
}
