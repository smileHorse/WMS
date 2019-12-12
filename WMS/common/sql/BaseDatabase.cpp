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

#include "BaseDatabase.h"

#include "Poco/Data/Extraction.h"
#include "Poco/Data/MySQL/Connector.h"

#include <iostream>

using Poco::Data::DataException;
using Poco::Data::ConnectionFailedException;
using Poco::Data::SessionPoolExhaustedException;

#define MYSQL_USER "root"
#define MYSQL_PWD  "root"
#define MYSQL_HOST "127.0.0.1"
#define MYSQL_PORT 3306
#define MYSQL_DB   "khloom"

CBaseDatabase::CBaseDatabase(const string& connection)
	: _dbConnString(connection)
{
	if (_dbConnString.empty())
	{
		_dbConnString = "host=" MYSQL_HOST
			";user=" MYSQL_USER
			";password=" MYSQL_PWD
			";db=" MYSQL_DB
			";compress=true"
			";auto-reconnect=true"
			";secure-auth=true"
			";protocol=tcp";
	}

	// 注册连接器
	Poco::Data::MySQL::Connector::registerConnector();

	// 创建连接池
	_pSessionPool = new SessionPool(Poco::Data::MySQL::Connector::KEY, _dbConnString);
}

CBaseDatabase::~CBaseDatabase()
{

}

// 设置连接字符串
void CBaseDatabase::setConnectString(const string& connection)
{
	_dbConnString = connection;

	// 创建连接池
	_pSessionPool = new SessionPool(Poco::Data::MySQL::Connector::KEY, _dbConnString);
}

// 获取会话
Session CBaseDatabase::getSession()
{
	if (!_pSessionPool.isNull())
	{
		return _pSessionPool->get();
	}
	else
	{
		return Session(Poco::Data::MySQL::Connector::KEY, _dbConnString);
	}
}

Poco::SharedPtr<Session> CBaseDatabase::getSessionPtr()
{
	try
	{
		return Poco::SharedPtr<Session>(new Session(_pSessionPool->get()));
	}
	catch (DataException& ex)
	{
		cout << ex.displayText() << endl;
		return nullptr;
	}
}
