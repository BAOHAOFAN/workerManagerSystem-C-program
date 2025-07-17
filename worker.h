#pragma once
#include<iostream>
using namespace std;

class worker {
public:
	//显示个人信息
	virtual void showINFO() = 0;
	//显示岗位名称
	virtual string showDEPT() = 0;
	//姓名
	string m_Name;
	//编号
	int m_ID;
	//岗位编号
	int m_dept_ID;
};