/*!
 * \file HomeWidget.h
 * \date 2019/12/02 11:07
 *
 * \author Masf
 *
 * TODO: Ö÷Ò³´°Ìå
 *
 * \note
*/

#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include <QtWidgets/QtWidgets>

class QPushButton;

class CHomeWidget : public QWidget
{
	Q_OBJECT

public:
	CHomeWidget(QWidget* parent = nullptr);

private:
	void initWidget();
	void createConnectes();

private slots:
	void doModifyPassword();
	void doLogout();

signals:
	void logoutSuccess();

private:
	QPushButton* m_modifyPasswordButton;
	QPushButton* m_logoutButton;
};
#endif