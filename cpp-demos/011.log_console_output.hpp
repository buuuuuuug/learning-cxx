/////////////////////////////////////////////////////////////////////////////
//// 第八章 危险的根源-堆内存-用新方法来解决
///  课程地址 http://cpp.show
///  夏曹俊老师微信  cppxcj
///  抖音   xiacaojun
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include "log_output.h"
class LogConsoleOuput :
    public LogOutput
{
public:
    /// <summary>
    /// 日志输出
    /// @para log 格式化后的日志内容
    /// </summary>
    void Ouput(
        const std::string& log) override;
};

