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
	void Show_Menu();//�˵�չʾ�Ĺ���
	void Exit_System();//�˳�����Ĺ���
	void Add_Worker();//���ְ���Ĺ���
	void Save();//�������ݵĺ���
	worker** m_array;
	int m_num;//ĿǰԱ������
	bool m_FileIsEmpty;//��־�ļ��Ƿ�Ϊ��
	int get_Num();//ͳ��ְ������
	void init_Emp();//��ʼ��ְ��
	void Show_Emp();//��ʾְ����Ϣ
	void Delet_Emp();//ɾ��ְ����Ϣ
	void Rivise_Emp();//�޸�ְ����Ϣ
	void Check_Emp();//����ְ����Ϣ
	void Resort_Emp();//����ְ����Ϣ
	void Clear_File();//����ļ���Ϣ
	~workerManager();
};