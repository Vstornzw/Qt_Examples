# _*_ coding : UTF-8 _*_
# 开发团队   :   龙之队
# 开发人员   :   赵伟
# 开发时间   :   2019/12/20 21:44
# 文件名称   :   createfold.py.PY
# 开发工具   :   PyCharm

import os

def CreateFolder(path):
    #去除首位空格
    del_path_space = path.strip()
    #去除尾部'\'
    del_path_tail = del_path_space.rstrip('\\')
    #判读输入路径是否已存在
    isexists = os.path.exists(del_path_tail)
    if not isexists:
        os.makedirs(del_path_tail)
        return True
    else:
        return False
