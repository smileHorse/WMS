/*!
 * \file TextUtil.h
 * \date 2019/12/02 15:15
 *
 * \author Masf
 *
 * TODO: 包含了主界面中的所有文本信息
 *
 * \note
*/

#ifndef TEXTUTIL_H
#define TEXTUTIL_H

#include <QtCore/QString>

namespace TextUtil {
	// 程序标题
	const QString TITLE = QStringLiteral("纺织机管理系统");

	// 退出确认
	const QString CLOSE_CONFIRM = QStringLiteral("确定要退出当前应用程序吗?");

	// 登录页面
	const QString LOGIN = QStringLiteral("登录");
	const QString QUIT = QStringLiteral("关闭程序");
	const QString CONFIG = QStringLiteral("系统配置");
	const QString USERNAME = QStringLiteral("用户名");
	const QString PASSWORD = QStringLiteral("密码");
	const QString PASSWORDCHECK = QStringLiteral("记住密码");
	
	// 主页面
};

#endif
