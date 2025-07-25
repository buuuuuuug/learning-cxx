/////////////////////////////////////////////////////////////////////////////
//// 第八章 危险的根源-堆内存-用新方法来解决
///  课程地址 http://cpp.show
///  夏曹俊老师微信  cppxcj
///  抖音   xiacaojun
/////////////////////////////////////////////////////////////////////////////

#include "log_file_output.h"

bool LogFileOutput::Open(
    const std::string& file)
{//追加写入
    ofs_.open(file,std::ios::app);
    if (ofs_.is_open())return true;
    return false;
}
void LogFileOutput::Ouput(
    const std::string& log)
{
    ofs_ << log << "\n";
}