#include"workerManager.h"
workerManager::workerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->m_FileIsEmpty = true;
		this->m_num = 0;
		this->m_array = NULL;
		ifs.close();
		return;
	}
	//文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->m_FileIsEmpty = true;
		this->m_num = 0;
		this->m_array = NULL;
		ifs.close();
		return;
	}
	//文件存在且保留有数据
	int num = this->get_Num();
	cout << "职工人数为:  " << num<<endl;
	this->m_num = num;
	this->m_array = new worker * [this->m_num];
	this->init_Emp();
}
workerManager::~workerManager() {
	worker* del_Worker = NULL;
	for (int i = 0; i < this->m_num; i++) {
		del_Worker = this->m_array[i];
		delete del_Worker;
	}
	delete[] this->m_array;
}
void workerManager::Show_Menu() {
	cout << "欢迎使用职工管理系统" << endl;
	cout << "0.退出管理系统" << endl;
	cout << "1.添加职工信息" << endl;
	cout << "2.显示职工信息" << endl;
	cout << "3.删除离职职工" << endl;
	cout << "4.修改职工信息" << endl;
	cout << "5.查找职工信息" << endl;
	cout << "6.按照编号排序" << endl;
	cout << "7.清空所有文档" << endl;
	cout << endl;
}
void workerManager::Exit_System() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void workerManager::Add_Worker(){

	int addnum = 0;
	cout << "请输入要增加的员工个数:  " << endl;
	cin >> addnum;
	if (addnum > 0) {
		int new_num = this->m_num + addnum;
		worker** new_space = new worker * [new_num];
		for (int i = 0; i < this->m_num; i++) {
			new_space[i] = this->m_array[i];
		}
		for (int i = 0; i < addnum; i++) {
			int id;
			string name;
			int did;
			cout << "请对第"<<i+1<<"个员工进行信息输入" << endl;
			cout << "请输入员工编号:  ";
			cin >> id;
			cout << "请输入员工姓名:  ";
			cin >> name;
			cout << "请输入员工岗位编号:  "<<endl;
			cout << "1员工" << endl << "2经理" << endl << "3老板"<<endl;
			cin >> did;
			worker* Worker = NULL;
			switch (did)
			{
			case 1:Worker = new employee(id, name,1);
				break;
			case 2:Worker = new manager(id, name, 2);
				break;
			case 3:Worker = new boss(id, name, 3);
				break;
			default:cout << "输入有误"<<endl;
				break;
			}
			new_space[this->m_num + i] = Worker;
		}
		//更新职工指针数组
		delete[] this->m_array;
		m_array = new_space;
		this->m_num = new_num;
		this->m_FileIsEmpty = false;
		//提示成功添加
		cout << "成功添加" << addnum<<"新职工"<<endl;
		this->Save();
		system("pause");
		system("cls");
	}
	else {
		cout << "输入数据有误";
		system("pause");
		system("cls");
	}

}
void workerManager::Save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	//将每个人的数据写入文件
	for (int i = 0; i < this->m_num; i++) {
		ofs << this->m_array[i]->m_ID << " "
			<< this->m_array[i]->m_Name << " "
			<< this->m_array[i]->m_dept_ID << " " << endl;
	}
	ofs.close();
}
int workerManager::get_Num() {
	int num = 0;;
	int id;
	string name;
	int did;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	while (ifs >> id && ifs >> name && ifs >> did) {
		num++;
	}
	ifs.close();
	return num;
}
void workerManager::init_Emp() {
	int index = 0;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	while (ifs >> id && ifs >> name && ifs >> did) {
		worker* Worker = NULL;
		if (did == 1) {
			Worker = new employee(id, name, did);
		}
		else if (did == 2) {
			Worker = new manager(id, name, did);
		}
		else {
			Worker = new boss(id, name, did);
		}
		this->m_array[index] = Worker;
		index++;
	}
	ifs.close();
}
void workerManager::Show_Emp() {
	for (int i = 0; i < this->m_num; i++) {
		this->m_array[i]->showINFO();
	}
	system("pause");
	system("cls");
}
void workerManager::Delet_Emp() {
	int index;
	cout << "请输入要删除的编号  " << endl;
	cin >> index;
	if (index<0 || index>this->m_num) {
		cout << "输入有误" << endl;
		system("pause");
		system("cls");
		return;
	}
	worker* temp = this->m_array[index - 1];
	for (int i = index - 1; i < this->m_num-1;i++) {
		this->m_array[i] = this->m_array[i + 1];
	}
	delete temp;
	this->m_num -= 1;
	cout << "删除完成" << endl;
	this->Save();
	system("pause");
	system("cls");
}
void workerManager::Rivise_Emp() {
	int index;
	int new_id; string new_name; int new_did;
	cout << "请输入想修改第几个职员" << endl;
	cin >> index;
	if (index<0 || index>this->m_num) {
		cout << "输入有误" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "编号改为:  ";
	cin >> new_id;
	cout << "姓名改为:  ";
	cin >> new_name;
	cout << "职位编号改为:  "<<endl;
	cout << "1员工" << endl << "2经理" << endl << "3老板" << endl;
	cin >> new_did;
	this->m_array[index - 1]->m_ID = new_id;
	this->m_array[index - 1]->m_Name = new_name;
	this->m_array[index - 1]->m_dept_ID = new_did;
	cout << "修改完成" << endl;
	this->Save();
	system("pause");
	system("cls");
}
void workerManager::Check_Emp() {
	int checkindex; int i;
	cout << "请输入查找的编号: " << endl;
	cin >> checkindex;
	for (i = 0; i < this->m_num; i++) {
		if (this->m_array[i]->m_ID == checkindex) {
			cout << "该员工信息如下:" << endl;
			this->m_array[i]->showINFO();
		}
	}
	if (i == this->m_num) {
		cout << "未查找到" << endl;
	}
	system("pause");
	system("cls");
}
void workerManager::Resort_Emp() {
	int method;
	cout << "请选择排序方式:" << endl;
	cout << "1按编号升序" << endl;
	cout << "2按编号降序" << endl;
	cin >> method;
	if (method == 1) {
		for (int i = 0; i < this->m_num; i++) {
			for (int j = i; j < this->m_num; j++) {
				if (this->m_array[i]->m_ID < this->m_array[j]->m_ID) {
					worker* temp = this->m_array[i];
					this->m_array[i] = this->m_array[j];
					this->m_array[j] = temp;
				}
			}
		}
		cout << "按降序排序成功" << endl;
		this->Save();
		system("pause");
		system("cls");
	}
	else if (method == 2) {
		for (int i = 0; i < this->m_num; i++) {
			for (int j = i; j < this->m_num; j++) {
				if (this->m_array[i]->m_ID > this->m_array[j]->m_ID) {
					worker* temp = this->m_array[i];
					this->m_array[i] = this->m_array[j];
					this->m_array[j] = temp;
				}
			}
		}
		cout << "按升序排序成功" << endl;
		system("pause");
		system("cls");
	}
}
void workerManager::Clear_File() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	ofs.close();
	cout << "清理文件完毕" << endl;
	for (int i = 0; i<this->m_num; i++) {
		worker* delete_worker = this->m_array[i];
		delete delete_worker;
	}
	delete[] this->m_array;
	this->m_array = NULL;
	this->m_num = 0;
	this->m_FileIsEmpty = true;
	system("pause");
	system("cls");
}