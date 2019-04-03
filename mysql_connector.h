/*
 * mysql_connector.h
 *
 *  Created on: Apr 3, 2019
 *      Author: wenhan
 */

#ifndef MYSQL_CONNECTOR_H_
#define MYSQL_CONNECTOR_H_

#include <mysql.h>
#include <string>

struct mysql_conn_info_t {
        std::string ip_addr;    // ip地址
        std::string db_name;    // 数据库名
        std::string username;       // 用户名
        std::string password;        // 密码
};

class MysqlConnector {
public:
        MysqlConnector();
        ~MysqlConnector();

public:
        /* 连接 */
        bool connect(const mysql_conn_info_t &conn_info);

        /* 执行sql命令 */
        MYSQL_RES* exec_sql_cmd(const char* sql_cmd);

        /* 单行执行结果 */
        MYSQL_ROW fetch_row(MYSQL_RES *res);

        /* 获取行数 */
        unsigned int get_row_count(MYSQL_RES *res);

        /* 获取列数 */
        unsigned int get_col_count(MYSQL_RES *res);

        /* 判断是否是结果尾部 */
        bool is_end(MYSQL_RES *res);

        /* 设置字符集编码 */
        bool set_charset(const char* charset);

        /* 获取当前状态 */
        const char* get_state();

        /* 获取错误信息 */
        const char* error();

        /* 释放结果集 */
        void free_res(MYSQL_RES *res);

        /* 断开连接 */
        void dis_connect();

protected:

        MYSQL *_conn_ptr;

        /* 目前未实现重连 */
        mysql_conn_info_t _conn_info;

};


#endif /* MYSQL_CONNECTOR_H_ */
