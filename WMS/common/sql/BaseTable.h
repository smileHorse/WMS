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

#ifndef BASETABLE_H
#define BASETABLE_H

#include "Poco/Data/Session.h"

#include <iostream>
using namespace std;

using namespace Poco::Data;
using namespace Poco::Data::Keywords;

class CBaseTable
{
public:
	CBaseTable();

protected:
	Poco::SharedPtr<Session> _pSession;
};
#endif
