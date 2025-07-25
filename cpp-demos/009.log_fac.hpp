/////////////////////////////////////////////////////////////////////////////
//// 第八章 危险的根源-堆内存-用新方法来解决
///  课程地址 http://cpp.show
///  夏曹俊老师微信  cppxcj
///  抖音   xiacaojun
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
#include "logger.h"
//logger工厂类
//维护logger生命周期
//构建logger
class LogFac
{
public:
    static LogFac& Instance()
    {
        static LogFac fac;
        return fac;
    }
    /// <summary>
    /// 初始化Logger对象
    /// log_type=console file
    /// log_file = log.txt
    /// log_level = debug
    /// </summary>
    /// <param name="con_file"></param>
    void Init(const std::string& con_file = "log.conf");
    Logger& logger() { return logger_; }
private:
    LogFac(){}
    Logger logger_;
};

#define XLOGOUT(l,s) LogFac::Instance().logger().Write(l, s , __FILE__, __LINE__)
#define LOGDEBUG(s)  XLOGOUT(XLog::DEBUG,s)
#define LOGINFO(s) XLOGOUT(XLog::INFO,s)
#define LOGERROR(s) XLOGOUT(XLog::ERROR,s)
#define LOGFATAL(s) XLOGOUT(XLog::FATAL,s)