#include<iostream>
using namespace std;
#include"employee.h"
//���캯��
employee::employee(int id, string name, int d_id) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_dept_ID = d_id;
}
//��ʾ��Ϣ
void employee::showINFO() {
	cout << "ְ�����:  " << this->m_ID
		<< "\tְ������:  " << this->m_Name
		<< "\tְ����λ:  " << this->showDEPT()
		<< "\tְ��ְ��:  ��ɾ����������" << endl;
}
//��ʾְ����λ
string employee::showDEPT() {
	return string("Ա��");
}
