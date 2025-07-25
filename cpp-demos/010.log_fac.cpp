/////////////////////////////////////////////////////////////////////////////
//// 第八章 危险的根源-堆内存-用新方法来解决
///  课程地址 http://cpp.show
///  夏曹俊老师微信  cppxcj
///  抖音   xiacaojun
/////////////////////////////////////////////////////////////////////////////

#include "log_fac.h"
#include "log_console_output.h"

#include "log_file_output.h"
#include "xlog_format.h"
#include "xconfig.h"
#define LOGFILE "log.txt"
#include <iostream>
using namespace std;
void LogFac::Init(
    const std::string& con_file)
{
    
    logger_.SetFormat(
        make_unique<XLogFormat>());

    XConfig conf;
    bool re = conf.Read(con_file);
    string log_type = "console";
    string log_file = LOGFILE;
    string log_level = "debug";
    if(re)
    {
        log_type = conf.Get("log_type");
        log_file = conf.Get("log_file");
        log_level = conf.Get("log_level");
    }

    if (log_level == "info")
    {
        logger_.SetLevel(XLog::INFO);
    }
    else if (log_level == "error")
    {
        logger_.SetLevel(XLog::ERROR);

    }
    else if (log_level == "fatal")
    {
        logger_.SetLevel(XLog::ERROR);
    }

    if (log_type == "file")
    {
        if (log_file.empty())
        {
            log_file = LOGFILE;
        }
        auto fout = 
            make_unique<LogFileOutput>();//new LogFileOutput();
        if (fout->Open(log_file))
        {
            cerr << "open file failed "
                << log_file << endl;
        }
        logger_.SetOutput(move(fout));
    }
    else
    {
        logger_.SetOutput(
            make_unique<LogConsoleOuput>()
            );
    }


   


}
