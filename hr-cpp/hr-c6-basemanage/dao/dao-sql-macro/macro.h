#pragma once
#ifndef _MACRO_H_
#define _MACRO_H_

// ���string�����ֶ�
// Ҫ�����ݿ��ֶα���������ֶ�һ��
#define SQLPARAMS_STRING_PUSH(SQL_field) \
if (query->SQL_field) { \
	sql << " AND `" #SQL_field "`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->SQL_field.getValue("")); \
}

// ���int�����ֶ�
// Ҫ�����ݿ��ֶα���������ֶ�һ��
#define SQLPARAMS_INT_PUSH(SQL_field)	\
if (query->SQL_field) { \
	sql << " AND `" #SQL_field "`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->SQL_field.getValue(0)); \
}

// ���double�����ֶ�
// Ҫ�����ݿ��ֶα���������ֶ�һ��
#define SQLPARAMS_FLOAT_PUSH(SQL_field)		\
if (query->SQL_field) { \
	sql << " AND `" #SQL_field "`=?"; \
	SQLPARAMS_PUSH(params, "d", double, query->SQL_field.getValue(0.0)); \
}

// �����������ֶ�
#define SQLPARAMS_UPDATE_PUSH(SQL_field)	\
sql << #SQL_field "=?,"

// ���������һ�������ֶ�
#define SQLPARAMS_UPDATE_PUSH_FINAL(SQL_field, fmt, WHERE_field)	\
sql << #SQL_field "=?";	\
sql << "WHERE "#WHERE_field "=?";	\
fmts << fmt;	\
fmts << "%s"

// ���INT���͸����ֶ�
#define SQLPARAMS_UPDATE_INT(SQL_field)		\
SQLPARAMS_UPDATE_PUSH(SQL_field);	\
fmts << "%i"

// ���FLOAT���͸����ֶ�
#define SQLPARAMS_UPDATE_FLOAT(SQL_field)	\
SQLPARAMS_UPDATE_PUSH(SQL_field);	\
fmts << "%d"

// ���String���͸����ֶ�
#define SQLPARAMS_UPDATE_STRING(SQL_field)		\
SQLPARAMS_UPDATE_PUSH(SQL_field);	\
fmts << "%s"




#endif // !_MACRO_H_