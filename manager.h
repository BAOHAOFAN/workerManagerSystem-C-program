#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class manager :public worker {
public:
	//���캯��
	manager(int id, string name, int d_id);
	//��ʾ������Ϣ
	virtual void showINFO();
	//��ʾ��λ����
	virtual string showDEPT();
};