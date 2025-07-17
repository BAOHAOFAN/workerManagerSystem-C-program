#include<iostream>
using namespace std;
#include"employee.h"
//构造函数
employee::employee(int id, string name, int d_id) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_dept_ID = d_id;
}
//显示信息
void employee::showINFO() {
	cout << "职工编号:  " << this->m_ID
		<< "\t职工姓名:  " << this->m_Name
		<< "\t职工岗位:  " << this->showDEPT()
		<< "\t职工职责:  完成经理给的任务" << endl;
}
//显示职工岗位
string employee::showDEPT() {
	return string("员工");
}
