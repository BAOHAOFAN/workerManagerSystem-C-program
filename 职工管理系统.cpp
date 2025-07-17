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
		cout << "请输入您的选择:"<<endl;
		cin >> choice;
		switch (choice) {
		case 0:wm.Exit_System();
			break;//退出系统
		case 1:wm.Add_Worker();
			break;//增加职工
		case 2:wm.Show_Emp();
			break;//显示职工
		case 3:wm.Delet_Emp();
			break;//删除职工
		case 4:wm.Rivise_Emp();
			break;//修改职工
		case 5:wm.Check_Emp();
			break;//查找职工
		case 6:wm.Resort_Emp();
			break;//排序职工
		case 7:wm.Clear_File();
			break;//清空文档
		default:system("cls");
			break;
		}

	}

	system("pause");
	return 0;
}