/////////////////////////////////////////////////////////////////////////////
//// 第八章 危险的根源-堆内存-用新方法来解决
///  课程地址 http://cpp.show
///  夏曹俊老师微信  cppxcj
///  抖音   xiacaojun
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
#include "log_format.h"
#include "log_output.h"
#include <memory>
/// <summary>
/// 聚合类 
/// 委托 LogFormat
///          LogOuput
/// </summary>
/// 
enum class XLog
{ //日志级别
    DEBUG,
    INFO,
    ERROR,
    FATAL
};
//XLog::DEBUG;
class Logger
{
public:
    //////////////////////////////////////////
   /// 格式化并写入日志
   /// @para level 日志级别
   /// @para log 日志内容
   /// @para file 源码文件路径
   /// @para line 代码行号
   ///
    void Write(
        XLog level,
        const std::string& log,
        const std::string& file,
        int line
    );
    void SetOutput(
        std::unique_ptr<LogOutput>  o)
    {
        output_ = move(o);
    }
    /*
    void SetOutput(
        LogOutput *o)
    {
        output_.reset(o);
    }*/
    void SetFormat(
        std::unique_ptr<LogFormat> f)
    {
        formater_ = move(f);
    }
    ~Logger() {
        //delete output_; 
        //output_ = nullptr;
        //delete formater_;
        //formater_ = nullptr;
    }
    void SetLevel(XLog level)
    {
        log_level_ = level;
    }
private:
    //LogOutput* output_{nullptr};
    //LogFormat *formater_{ nullptr };
    std::unique_ptr<LogOutput> output_;
    std::unique_ptr<LogFormat> formater_;
    //最低日志级别
    XLog log_level_{ XLog::DEBUG };
};

