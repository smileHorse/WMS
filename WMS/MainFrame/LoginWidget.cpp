/*!
* \file LoginWidget.cpp
* \date 2019/12/02 11:06
*
* \author Masf
*
* TODO: 登录窗体
*
* \note
*/

#include "LoginWidget.h"
#include "container/ContainerWidget.h"
#include "container/HeaderWidget.h"
#include "container/MainWidget.h"
#include "util/TextUtil.h"

#include <QtWidgets/QtWidgets>

CLoginWidget::CLoginWidget(QWidget* parent)
	: QWidget(parent)
{
	initWidget();
	createConnectes();
}

void CLoginWidget::initWidget()
{
	m_loginButton = new QPushButton(TextUtil::LOGIN);
	m_quitButton = new QPushButton(TextUtil::QUIT);
	m_configButton = new QPushButton(TextUtil::CONFIG);

	// 头部窗体
	QList<QWidget*> headerChilds;
	headerChilds << m_loginButton << m_quitButton << m_configButton;
	CHeaderWidget* headerWidget = new CHeaderWidget(headerChilds, this);
	headerWidget->setStyleSheet("background-image: url(:/images/bk-header.png)");

	// 主窗体
	CMainWidget* mainWidget = new CMainWidget(this);
	mainWidget->setStyleSheet("background-image: url(:/images/bk-login.png)");

	CContainerWidget* containerWidget = new CContainerWidget(mainWidget, headerWidget, 0, 0, this);
	QHBoxLayout* layout = new QHBoxLayout();
	layout->addWidget(containerWidget);
	setLayout(layout);
}

void CLoginWidget::createConnectes()
{
	connect(m_loginButton, SIGNAL(clicked()), this, SLOT(doLogin()));
}

void CLoginWidget::doLogin()
{
	emit loginSuccess();
}

