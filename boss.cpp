#include<iostream>
using namespace std;
#include"boss.h"

//���캯��
boss::boss(int id, string name, int d_id) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_dept_ID = d_id;
}
//��ʾ��Ϣ
void boss::showINFO() {
	cout << "ְ�����:  " << this->m_ID
		<< "\tְ������:  " << this->m_Name
		<< "\tְ����λ:  " << this->showDEPT()
		<< "\tְ��ְ��:  ����Ա������������" << endl;
}
//��ʾְ����λ
string boss::showDEPT() {
	return string("�ϰ�");
}