/*!
* \file MainWidget.cpp
*
* \author Masf
* \date ʮһ�� 2019
*
* ��Ҫ��������
*/

#include "MainWidget.h"

CMainWidget::CMainWidget(QWidget* parent /*= nullptr*/)
	: QWidget(parent)
{

}

void CMainWidget::paintEvent(QPaintEvent * event)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
