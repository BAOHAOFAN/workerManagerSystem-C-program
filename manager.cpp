#include<iostream>
using namespace std;
#include"manager.h"

//���캯��
manager::manager(int id, string name, int d_id) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_dept_ID = d_id;
}
//��ʾ��Ϣ
void manager::showINFO() {
	cout << "ְ�����:  " << this->m_ID
		<< "\tְ������:  " << this->m_Name
		<< "\tְ����λ:  " << this->showDEPT()
		<< "\tְ��ְ��:  ����ϰ��������" << endl;
}
//��ʾְ����λ
string manager::showDEPT() {
	return string("����");
}