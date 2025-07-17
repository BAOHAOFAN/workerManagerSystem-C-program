#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class manager :public worker {
public:
	//构造函数
	manager(int id, string name, int d_id);
	//显示个人信息
	virtual void showINFO();
	//显示岗位名称
	virtual string showDEPT();
};