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
#include "util/IconUtil.h"
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
	m_quitButton = new QPushButton(TextUtil::QUIT);
	m_configButton = new QPushButton(TextUtil::CONFIG);

	// 头部窗体
	QList<QWidget*> headerChilds;
	headerChilds << m_quitButton << m_configButton;
	CHeaderWidget* headerWidget = new CHeaderWidget(headerChilds, this);
	headerWidget->setObjectName("headerWidget");
	headerWidget->setFixedHeight(120);

	// 主窗体
	QWidget* mainWidget = initMainWidget();

	CContainerWidget* containerWidget = new CContainerWidget(mainWidget, headerWidget, 0, 0, this);
	QHBoxLayout* layout = new QHBoxLayout();
	layout->setContentsMargins(QMargins(0, 0, 0, 0));
	layout->addWidget(containerWidget);
	setLayout(layout);
}

QWidget* CLoginWidget::initMainWidget()
{
	m_iconLabel = new QLabel();
	m_iconLabel->setMaximumHeight(130);
	m_iconLabel->setPixmap(QPixmap(IconUtil::APP_ICON));
	m_nameEdit = new QLineEdit();
	m_nameEdit->setFocus();
	m_passwordEdit = new QLineEdit();
	m_passwordEdit->setEchoMode(QLineEdit::Password);
	m_passwordCheckBox = new QCheckBox(TextUtil::PASSWORDCHECK);
	m_passwordCheckBox->setChecked(false);
	m_loginButton = new QPushButton(TextUtil::LOGIN);
	m_loginButton->setObjectName("loginButton");
	m_loginButton->setMinimumWidth(270);

	QGridLayout* gridLayout = new QGridLayout();
	gridLayout->addWidget(m_iconLabel, 0, 1);
	gridLayout->addWidget(new QLabel(TextUtil::USERNAME), 1, 0);
	gridLayout->addWidget(m_nameEdit, 1, 1, 1, 2);
	gridLayout->addWidget(new QLabel(TextUtil::PASSWORD), 2, 0);
	gridLayout->addWidget(m_passwordEdit, 2, 1, 1, 2);
	gridLayout->addWidget(m_passwordCheckBox, 3, 0, 1, 3, Qt::AlignHCenter);
	gridLayout->addWidget(m_loginButton, 4, 0, 1, 3, Qt::AlignHCenter);
	
	QWidget* formWidget = new QWidget(this);
	formWidget->setObjectName("formWidget");
	formWidget->setFixedSize(300, 400);
	formWidget->setLayout(gridLayout);

	QHBoxLayout* hLayout = new QHBoxLayout();
	hLayout->addStretch(1);
	hLayout->addWidget(formWidget);
	hLayout->addStretch(1);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addStretch(1);
	layout->addLayout(hLayout);
	layout->addStretch(1);
	CMainWidget* mainWidget = new CMainWidget(this);
	mainWidget->setObjectName("mainWidget");
	mainWidget->setLayout(layout);
	return mainWidget;
}

void CLoginWidget::createConnectes()
{
	connect(m_loginButton, SIGNAL(clicked()), this, SLOT(doLogin()));
	connect(m_quitButton, SIGNAL(clicked()), this, SLOT(doQuit()));
}

void CLoginWidget::doLogin()
{
	emit loginSuccess();
}

void CLoginWidget::doQuit()
{
	emit quitApp();
}

