#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
int main() {
	workerManager wm;
	int choice = 0;
	while (true) {
		wm.Show_Menu();
		cout << "����������ѡ��:"<<endl;
		cin >> choice;
		switch (choice) {
		case 0:wm.Exit_System();
			break;//�˳�ϵͳ
		case 1:wm.Add_Worker();
			break;//����ְ��
		case 2:wm.Show_Emp();
			break;//��ʾְ��
		case 3:wm.Delet_Emp();
			break;//ɾ��ְ��
		case 4:wm.Rivise_Emp();
			break;//�޸�ְ��
		case 5:wm.Check_Emp();
			break;//����ְ��
		case 6:wm.Resort_Emp();
			break;//����ְ��
		case 7:wm.Clear_File();
			break;//����ĵ�
		default:system("cls");
			break;
		}

	}

	system("pause");
	return 0;
}