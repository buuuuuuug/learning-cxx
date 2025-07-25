/////////////////////////////////////////////////////////////////////////////
//// 第八章 危险的根源-堆内存-用新方法来解决
///  课程地址 http://cpp.show
///  夏曹俊老师微信  cppxcj
///  抖音   xiacaojun
/////////////////////////////////////////////////////////////////////////////

// test_class_xlog.cpp :
#include <iostream>
//#include "xlog_format.h"
//#include "log_console_output.h"
//#include "log_file_output.h"
//#include "logger.h"

#include "log_fac.h"
//#include "xconfig.h"
using namespace std;
//XLogFormat ->LogFormat
int main()
{
    //XConfig conf;
    //conf.Read("log.conf");
    //cout << conf.Get("log_file") << endl;
    LogFac::Instance().Init();

    LogFac::Instance().logger().Write(XLog::DEBUG
        , "test logger", __FILE__, __LINE__);
    LOGDEBUG("test LogFac debug");
    LOGINFO("test LogFac info");
    LOGERROR("test LogFac error");
    LOGFATAL("test LogFac fatal");

    /*
    {
        Logger logger;
        logger.SetFormat(
            new XLogFormat());
        //auto fout = new LogFileOutput();
        //fout->Open("log2.txt");
        logger.SetOutput(
            new LogConsoleOuput
        );
        logger.SetLevel(XLog::ERROR);
        logger.Write(XLog::DEBUG, 
            "test debug Logger", 
            __FILE__, __LINE__);
        logger.Write(XLog::INFO,
            "test info Logger",
            __FILE__, __LINE__);
        logger.Write(XLog::ERROR,
            "test error Logger",
            __FILE__, __LINE__);
        logger.Write(XLog::FATAL,
            "test fatal Logger",
            __FILE__, __LINE__);

    }
    return 0;

    LogFileOutput fout;
    fout.Open("log.txt");
    fout.Ouput("test file log");


    LogConsoleOuput con_out;
    con_out.Ouput("test LogConsoleOuput");

    XLogFormat xlog;
    auto str = xlog.Format("debug"
        , "test XLogFormat format"
        , __FILE__, __LINE__
    );
    cout << "str = " << str << endl;


    */
}