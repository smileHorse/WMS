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
	void createConnectes();

private slots:
	void doLogin();

signals:
	void loginSuccess();

private:
	QPushButton* m_loginButton;
	QPushButton* m_quitButton;
	QPushButton* m_configButton;
};
#endif