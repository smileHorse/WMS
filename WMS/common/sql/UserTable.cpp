/*!
* \file UserTable.h
* \date 2019/12/11 11:18
*
* \author Masf
*
* TODO: ”√ªß±Ì
*
* \note
*/

#include "UserTable.h"
#include "log/logger.h"


CUserTable::CUserTable()
	: CBaseTable()
{

}

bool CUserTable::insertRecord()
{
	return true;
}

bool CUserTable::updateRecord()
{
	return true;
}

bool CUserTable::deleteRecord()
{
	return true;
}

bool CUserTable::selectAllRecords()
{
	if (!_pSession)
	{
		RdbLog(CLogger::Log_ERROR, "Session is null");
		return false;
	}

	try {
		int count = 0;
		*_pSession << "SELECT COUNT(*) from t_user", into(count), now;

		RdbLog(CLogger::Log_INFO, "data count: %d", count);
	}
	catch (Poco::Data::DataException& ex) {
		RdbLog(CLogger::Log_ERROR, ex.displayText().c_str());
		return false;
	}
	return true;
}
