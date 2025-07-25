// test_lambda.cpp 
#include <iostream>
#include <functional>
using namespace std;
class Data
{
public:
    void Test() { cout << __FUNCSIG__ << endl; }
    void Call(function<void()> func)
    {
        func();
    }
    void TestCall()
    {
        function<void()> func = [this] {
            Test();
            };
        func();
    }
};

void Test() { cout << __FUNCSIG__ << endl; }
int main()
{
    auto func1 = [] {cout << "test lambda!" << endl; };
    func1();
    [] {cout << "call test lambda!" << endl; }();
    auto func2 = [](int x, int y, string str) {
        cout << "lambda " << x << ":" << y << " " << str << endl;
        };
    func2(100,200,"test");
    auto func3 = [] {return 999; };
    cout << func3() << endl;
    auto func4 = []()->string {return "test return"; };
    auto str = func4();
    auto func5 = [](auto s) { cout << s << endl; };
    func5(1);
    func5("test");
    int x = 100;
    cout << x<< "  &x = " << &x << endl;
    [=] { //= 复制变量
        cout << x << "= &x = " << &x << endl;
        }();
    [&] { //& 引用变量
        cout << x << "& &x = " << &x << endl;
        }();
        int w = 100; 
        int h =  200;
        cout << "w = " << w << &w << endl;
        cout << "h = " << h << &h << endl;
        [=,&w] {
            cout << "w = " << w<<&w << endl;
            cout << "h = " << h << &h<< endl;
            }();

        //lambda 访问成员函数
        Data data;
        auto cfunc = [&data] {
            data.Test();
            };
        cfunc();
        data.TestCall();
        data.Call(Test);
        data.Call(cfunc);
        data.Call( [] { cout << "test call" << endl; } );






    //Data d;
    //func5(d);


}
