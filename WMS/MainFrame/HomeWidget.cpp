/*!
* \file HomeWidget.cpp
* \date 2019/12/02 11:07
*
* \author Masf
*
* TODO: ��ҳ����
*
* \note
*/

#include "HomeWidget.h"

#include <QtWidgets/QtWidgets>

CHomeWidget::CHomeWidget(QWidget* parent /*= nullptr*/)
	: QWidget(parent)
{
	initWidget();
	createConnectes();
}

void CHomeWidget::initWidget()
{
	m_logoutButton = new QPushButton("Logout");

	QHBoxLayout* layout = new QHBoxLayout();
	layout->addWidget(new QLabel(QStringLiteral("��ҳҳ��")));
	layout->addWidget(m_logoutButton);
	setLayout(layout);
}

void CHomeWidget::createConnectes()
{
	connect(m_logoutButton, SIGNAL(clicked()), this, SLOT(doLogout()));
}

void CHomeWidget::doModifyPassword()
{

}

void CHomeWidget::doLogout()
{
	emit logoutSuccess();
}
