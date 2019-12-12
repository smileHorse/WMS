/*!
 * \file WmsDatabase.h
 * \date 2019/12/11 11:03
 *
 * \author Masf
 *
 * TODO: 数据库操作信息
 *
 * \note
*/

#ifndef BASEDATABASE_H
#define BASEDATABASE_H

#include "Poco/SharedPtr.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/SessionPool.h"

#include <string>

using namespace std;
using Poco::Data::Session;
using Poco::Data::SessionPool;

class CBaseDatabase
{
public:
	static CBaseDatabase& instance()
	{
		static CBaseDatabase database("");
		return database;
	}

private:
	CBaseDatabase(const string& connection);
	~CBaseDatabase();
	
public:
	// 设置连接字符串
	void setConnectString(const string& connection);

	// 获取会话
	Session getSession();
	Poco::SharedPtr<Session> getSessionPtr();

private:
	std::string _dbConnString;
	Poco::SharedPtr<SessionPool> _pSessionPool;
};

#endif