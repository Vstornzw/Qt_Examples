1	C����ʹ��SQLite3���ݿ�--http://www.sqlite.org/download.html
	�ڱ��ļ��е� need file �ļ��������Ѿ����غ��ˣ�sqlite-dll-win64-x64-3310100.zipû�����ϣ�

2	cmd ��ָ����Ŀ¼�£����ǲ������Ŀ��Բο�https://zhidao.baidu.com/question/18450488.html��

3	https://www.cnblogs.com/wangluojisuan/archive/2013/11/06/3411266.html����sqlite3��غ�����ѧϰ��

���磺
int sqlite3_exec(sqlite3 *db, const char *sql, sqlite3_callback callback, void *,char **errmsg);

����:ִ��sql���

����:
db:���ݿ���
sql:sql���
callback:�ص�����,ÿ�ɹ�ִ��һ��sql����ִ��һ��callback����
void *:���ص��������Ĳ���
errmsg:������Ϣ
�ص������Ķ���:
typedef int(*sqlite3_callback)(void *, int, char **, char **);
����������һ������ָ��,




