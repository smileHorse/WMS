/*
 * Copyright (c) 2010,GridNT,Inc
 *All rights reserved.
 *
 * 文件名称：my_logger.cpp
 * 摘要：日志实现文件
 */

#include <stdio.h>
#include "logger.h"
#include <stdarg.h>

#include "log4cplus/consoleappender.h"
using namespace log4cplus::helpers;

//静态变量初始化
enum CLogger::Write_Mode CLogger::log_write_mode = CLogger::Mode_File;

log4cplus::Initializer initializer;

/******************************************************
 * 日志初始化
 * @return Logger 创建的日志管理实例
 ******************************************************/
Logger CLogger::init(string init_file)
{
	try
	{
		// 未指定配置文件时，输出到终端
		if (init_file.empty())
		{
			// step1 Instantiate an append object
			SharedObjectPtr<Appender> _append(new ConsoleAppender());
			_append->setName("append for test");
			
			// step2: Instantiate an layout object
			std::string pattern = "%D{%Y-%m-%d %H:%M:%S} - %m[%l]%n";
			
			// step3: Attach the layout object to the append object
			_append->setLayout(std::unique_ptr<Layout>(new PatternLayout(pattern)));
			
			// step4: Instantiate an logger object
			my_logger = Logger::getInstance(LOG4CPLUS_TEXT("log"));
			
			// step5: Attach the appender object to the logger
			my_logger.addAppender(_append);
			
			// step6: Set a priority for the logger
			my_logger.setLogLevel(ALL_LOG_LEVEL);
		}
		else
		{
			PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(init_file.c_str()));
			my_logger = Logger::getInstance(LOG4CPLUS_TEXT("log"));
		}	
	} 
	catch (...)
	{
		std::cout << "LOG Exception !!!" << std::endl;
		LOG4CPLUS_FATAL(my_logger, "CLogger 异常");
	}

	return my_logger;
}

/******************************************************
 * 设置日志记录模式
 * @mode int 日志记录模式
 * @return void
 ******************************************************/
void CLogger::SetLogMode(bool mode)
{
	if (mode)
		log_write_mode = Mode_Both;
	else
		log_write_mode = Mode_Display;
}

/******************************************************
 * 写“实时库”相关日志
 * @type enum CLogger::Log_Type 日志类型
 * @fmt const char*  日志内容
 * @return void
 ******************************************************/
void RdbLog(enum CLogger::Log_Type type, const char* fmt, ...)
{
	char chtmp[2048];

	va_list args;
	va_start(args, fmt);
	vsnprintf(chtmp, 2048, fmt, args);
	va_end(args);

	CLogger::RdbLog(chtmp, type);
}

/******************************************************
 * 写“Topo”相关日志
 * @type enum CLogger::Log_Type 日志类型
 * @fmt const char*  日志内容
 * @return void
 ******************************************************/
void CLogger::RdbLog(enum CLogger::Log_Type type, const char* fmt, ...)
{
	char chtmp[1024];

	va_list args;
	va_start(args, fmt);
	vsnprintf(chtmp, 1024, fmt, args);
	va_end(args);

	CLogger::RdbLog(chtmp, type);
}

/******************************************************
 * 写指定类型日志
 * @msg string 待写入的日志内容
 * ＠type enum Log_Type 待写入的日志类型
 * @return void
 ******************************************************/
void CLogger::RdbLog(string msg, enum Log_Type type)
{
	string info = "Rdb : " + msg;
	WriteLog(info, type);
}

/******************************************************
 * 写“实时库”相关日志
 * @msg string 待写入的日志内容
 * ＠type enum Log_Type 待写入的日志类型
 * @return void
 ******************************************************/
void CLogger::WriteLog(string msg, enum Log_Type type)
{
	//显示日志内容
	if ((log_write_mode == Mode_Display) || (log_write_mode == Mode_Both))
	{
		std::cout << msg << std::endl;
	}

	//记录日志内容
	if ((log_write_mode != Mode_File) && (log_write_mode != Mode_Both))
		return;
	switch (type)
	{
	case Log_DEBUG:
		{
        LOG4CPLUS_DEBUG(my_logger, msg.c_str());
		}
		break;
	case Log_INFO:
        LOG4CPLUS_INFO(my_logger, msg.c_str());
		break;
	case Log_WARN:
        LOG4CPLUS_WARN(my_logger, msg.c_str());
		break;
	case Log_ERROR:
        LOG4CPLUS_ERROR(my_logger, msg.c_str());
		break;
	case Log_FATAL:
        LOG4CPLUS_FATAL(my_logger, msg.c_str());
		break;
	default:
        LOG4CPLUS_INFO(my_logger, msg.c_str());
	}
}

