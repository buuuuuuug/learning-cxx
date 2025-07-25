/////////////////////////////////////////////////////////////////////////////
//// 第八章 危险的根源-堆内存-用新方法来解决
///  课程地址 http://cpp.show
///  夏曹俊老师微信  cppxcj
///  抖音   xiacaojun
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include "log_output.h"
#include <fstream>
class LogFileOutput:public LogOutput
{
public:
    /// <summary>
    /// 打开写入日志的文件
    /// </summary>
    /// <param name="file">文件路径</param>
    /// <returns>打开文件是否成功</returns>
    bool Open(const std::string& file);

    /// <summary>
    /// 日志输出
    /// @para log 格式化后的日志内容
    /// </summary>
    void Ouput(
        const std::string& log) override;
private:
    std::ofstream ofs_;

};

