/////////////////////////////////////////////////////////////////////////////
//// 第八章 危险的根源-堆内存-用新方法来解决
///  课程地址 http://cpp.show
///  夏曹俊老师微信  cppxcj
///  抖音   xiacaojun
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
//log_format.h

//////////////////////////////////////
/// LogFormat日志格式化接口类
class LogFormat
{
public:
    //////////////////////////////////////////
    /// 格式化日志转为字符串
    /// @para level 日志级别
    /// @para log 日志内容
    /// @para file 源码文件路径
    /// @para line 代码行号
    ///
    virtual std::string Format(
        const std::string& level,
        const std::string& log,
        const std::string& file,
        int line
    ) = 0;
};