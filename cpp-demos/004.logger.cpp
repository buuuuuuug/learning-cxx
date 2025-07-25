/////////////////////////////////////////////////////////////////////////////
//// 第八章 危险的根源-堆内存-用新方法来解决
///  课程地址 http://cpp.show
///  夏曹俊老师微信  cppxcj
///  抖音   xiacaojun
/////////////////////////////////////////////////////////////////////////////

#include "logger.h"
void Logger::Write(
    XLog level,
    const std::string& log,
    const std::string& file,
    int line
)
{
    if (!formater_ || !output_)return;
    if (level <  log_level_)return;

    //日志级别枚举类型转为字符串
    std::string levelstr = "debug";
    switch (level) //switch只支持数字
    { //比if效率高
    case XLog::INFO:
        levelstr = "info";
        break;
    case XLog::ERROR:
        levelstr = "error";
        break;
    case XLog::FATAL:
        levelstr = "fatal";
        break;
    default:
        break;
    }
    //格式化日志
    auto str = formater_->Format(
        levelstr,
        log, file, line);
    output_->Ouput(str);

}