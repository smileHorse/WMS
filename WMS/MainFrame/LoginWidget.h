/*!
 * \file LoginWidget.h
 * \date 2019/12/02 11:06
 *
 * \author Masf
 *
 * TODO: µÇÂ¼´°Ìå
 *
 * \note
*/
#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QtWidgets/QtWidgets>

class QPushButton;

class CLoginWidget : public QWidget
{
	Q_OBJECT

public:
	CLoginWidget(QWidget* parent = nullptr);

private:
	void initWidget();
	QWidget* initMainWidget();
	void createConnectes();

private slots:
	void doLogin();
	void doQuit();

signals:
	void loginSuccess();
	void quitApp();

private:
	QPushButton* m_quitButton;
	QPushButton* m_configButton;

	QLabel* m_iconLabel;
	QLineEdit* m_nameEdit;
	QLineEdit* m_passwordEdit;
	QCheckBox* m_passwordCheckBox;
	QPushButton* m_loginButton;
};
#endif