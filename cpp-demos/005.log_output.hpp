/////////////////////////////////////////////////////////////////////////////
//// 第八章 危险的根源-堆内存-用新方法来解决
///  课程地址 http://cpp.show
///  夏曹俊老师微信  cppxcj
///  抖音   xiacaojun
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
/// <summary>
/// 日志的输出接口，输出到设备
/// </summary>
class LogOutput
{
public:
    /// <summary>
    /// 日志输出
    /// @para log 格式化后的日志内容
    /// </summary>
    virtual void Ouput(
        const std::string& log) = 0;
};