﻿/*
 * Copyright (c) 2010,GridNT,Inc
 *All rights reserved.
 *
 * 文件名称：Logger.h
 * 摘要：日志头文件
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/initializer.h>

using namespace log4cplus;
using namespace std;

#include <string>

/*
* 类名称:CLogger
* 主要功能:
* 完成日期：2011-5-22
*
*/
class CLogger
{
public:
	//日志类型
	enum Log_Type
	{
		Log_DEBUG = 1, Log_INFO, Log_WARN, Log_ERROR, Log_FATAL
	};

	//日志记录方式
	enum Write_Mode
	{
		Mode_Display = 1, Mode_File, Mode_Both
	};


	static void RdbLog(enum CLogger::Log_Type type, const char* fmt, ...);

	static void RdbLog(string msg, enum Log_Type type = Log_INFO);

	static log4cplus::Logger init(string init_file = "");
	static void SetLogMode(bool mode = true);

protected:

	//获得日志操作对象
	static log4cplus::Logger GetLogger(void)
	{
		return my_logger;
	}

	static void WriteLog(string msg, enum Log_Type type);//写指定类型日志

	static log4cplus::Logger my_logger;//log4cplus对象
	static enum Write_Mode log_write_mode;//日志记录方式
};

void RdbLog(enum CLogger::Log_Type type, const char* fmt, ...);

#endif
