#pragma once

#include <QtWidgets/QMainWindow>

class CLoginWidget;
class CHomeWidget;
class QStackedWidget;

class MainFrame : public QMainWindow
{
	Q_OBJECT

public:
	MainFrame(QWidget *parent = Q_NULLPTR);

protected:
	virtual void closeEvent(QCloseEvent *event);

private:
	void initFrame();
	void createConnectes();

private slots:
	void doLoginSuccess();
	void doLogoutSuccess();

private:
	CLoginWidget* m_loginWidget;
	CHomeWidget* m_homeWidget;
	QStackedWidget* m_stackedWidget;
};
