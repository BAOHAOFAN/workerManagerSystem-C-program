#pragma once
#include<iostream>
using namespace std;

class worker {
public:
	//��ʾ������Ϣ
	virtual void showINFO() = 0;
	//��ʾ��λ����
	virtual string showDEPT() = 0;
	//����
	string m_Name;
	//���
	int m_ID;
	//��λ���
	int m_dept_ID;
};