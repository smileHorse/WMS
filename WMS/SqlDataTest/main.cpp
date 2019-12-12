
#include "log/logger.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/MySQL/Connector.h"
#include "sql/UserTable.h"
#include "sql/BaseDatabase.h"

#include <iostream>

using namespace std;
using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

log4cplus::Logger CLogger::my_logger = CLogger::init();

int main()
{	
	CUserTable userTable;

	// 插入记录
	//userTable.insertRecord();

	// 修改记录
	//userTable.updateRecord();

	// 删除记录

	// 查询记录
	userTable.selectAllRecords();


	Logger::shutdown();
	return 0;
}