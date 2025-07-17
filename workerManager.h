#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

class workerManager
{
public:
	workerManager();
	void Show_Menu();//菜单展示的功能
	void Exit_System();//退出程序的功能
	void Add_Worker();//添加职工的功能
	void Save();//保存数据的函数
	worker** m_array;
	int m_num;//目前员工个数
	bool m_FileIsEmpty;//标志文件是否为空
	int get_Num();//统计职工人数
	void init_Emp();//初始化职工
	void Show_Emp();//显示职工信息
	void Delet_Emp();//删除职工信息
	void Rivise_Emp();//修改职工信息
	void Check_Emp();//查找职工信息
	void Resort_Emp();//排序职工信息
	void Clear_File();//清除文件信息
	~workerManager();
};