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
#ifndef USERTABLE_H
#define USERTABLE_H

#include "BaseTable.h"

using Poco::Data::Session;

class CUserTable : CBaseTable
{
public:
	CUserTable();

	bool insertRecord();
	bool updateRecord();
	bool deleteRecord();
	bool selectAllRecords();
};

#endif