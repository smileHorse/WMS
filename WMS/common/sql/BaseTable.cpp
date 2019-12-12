/*!
* \file WmsTable.h
* \date 2019/12/11 16:13
*
* \author Masf
*
* TODO: ���ݿ��
*
* \note
*/

#include "BaseTable.h"
#include "BaseDatabase.h"

CBaseTable::CBaseTable()
	: _pSession(0)
{
	// �����ӳ��л�ȡ�Ự����
	try
	{
		_pSession = CBaseDatabase::instance().getSessionPtr();
	}
	catch (DataException& ex)
	{
		cout << ex.displayText() << endl;
	}
}
