#include "MainFrame.h"
#include "HomeWidget.h"
#include "LoginWidget.h"
#include "util/IconUtil.h"
#include "util/TextUtil.h"

#include <QtWidgets/QtWidgets>

MainFrame::MainFrame(QWidget *parent)
	: QMainWindow(parent)
{
	initFrame();
	createConnectes();

	// 设置标题
	setWindowTitle(TextUtil::TITLE);
	setWindowIcon(QIcon(IconUtil::APP_ICON));

	// 最大化显示
	showMaximized();
}

void MainFrame::closeEvent(QCloseEvent *event)
{
	if (QMessageBox::warning(this, TextUtil::TITLE, TextUtil::CLOSE_CONFIRM,
		QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
		event->accept();
		return;
	}
	event->ignore();
}

void MainFrame::initFrame()
{
	/************************************************************************/
	/* 主框架包含两个页面，一个登录页面，一个主页页面                               
	/* 初始页面为登录页面；用户登录成功后进入主页页面；用户退出登录时进入登录页面
	/************************************************************************/
	m_loginWidget = new CLoginWidget(this);
	m_homeWidget = new CHomeWidget(this);

	m_stackedWidget = new QStackedWidget();
	m_stackedWidget->addWidget(m_loginWidget);
	m_stackedWidget->addWidget(m_homeWidget);
	m_stackedWidget->setCurrentIndex(0);
	setCentralWidget(m_stackedWidget);
}

void MainFrame::createConnectes()
{
	connect(m_loginWidget, SIGNAL(loginSuccess()), this, SLOT(doLoginSuccess()));
	connect(m_loginWidget, SIGNAL(quitApp()), this, SLOT(close()));
	connect(m_homeWidget, SIGNAL(logoutSuccess()), this, SLOT(doLogoutSuccess()));
}

void MainFrame::doLoginSuccess()
{
	m_stackedWidget->setCurrentIndex(1);
}

void MainFrame::doLogoutSuccess()
{
	m_stackedWidget->setCurrentIndex(0);
}
