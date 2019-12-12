/*!
* \file WmsTable.h
* \date 2019/12/11 16:13
*
* \author Masf
*
* TODO: 数据库表
*
* \note
*/

#include "BaseTable.h"
#include "BaseDatabase.h"

CBaseTable::CBaseTable()
	: _pSession(0)
{
	// 从连接池中获取会话对象
	try
	{
		_pSession = CBaseDatabase::instance().getSessionPtr();
	}
	catch (DataException& ex)
	{
		cout << ex.displayText() << endl;
	}
}
