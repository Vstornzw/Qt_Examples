1	C语言使用SQLite3数据库--http://www.sqlite.org/download.html
	在本文件夹的 need file 文件夹里面已经下载好了（sqlite-dll-win64-x64-3310100.zip没有用上）

2	cmd 到指定的目录下（若是不熟练的可以参考https://zhidao.baidu.com/question/18450488.html）

3	https://www.cnblogs.com/wangluojisuan/archive/2013/11/06/3411266.html（有sqlite3相关函数的学习）

例如：
int sqlite3_exec(sqlite3 *db, const char *sql, sqlite3_callback callback, void *,char **errmsg);

功能:执行sql语句

参数:
db:数据库句柄
sql:sql语句
callback:回调函数,每成功执行一次sql语句就执行一次callback函数
void *:给回调函数传的参数
errmsg:错误信息
回调函数的定义:
typedef int(*sqlite3_callback)(void *, int, char **, char **);
很明显这是一个函数指针,




