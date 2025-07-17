#include"workerManager.h"
workerManager::workerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ļ�������
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		this->m_FileIsEmpty = true;
		this->m_num = 0;
		this->m_array = NULL;
		ifs.close();
		return;
	}
	//�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		this->m_FileIsEmpty = true;
		this->m_num = 0;
		this->m_array = NULL;
		ifs.close();
		return;
	}
	//�ļ������ұ���������
	int num = this->get_Num();
	cout << "ְ������Ϊ:  " << num<<endl;
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
	cout << "��ӭʹ��ְ������ϵͳ" << endl;
	cout << "0.�˳�����ϵͳ" << endl;
	cout << "1.���ְ����Ϣ" << endl;
	cout << "2.��ʾְ����Ϣ" << endl;
	cout << "3.ɾ����ְְ��" << endl;
	cout << "4.�޸�ְ����Ϣ" << endl;
	cout << "5.����ְ����Ϣ" << endl;
	cout << "6.���ձ������" << endl;
	cout << "7.��������ĵ�" << endl;
	cout << endl;
}
void workerManager::Exit_System() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void workerManager::Add_Worker(){

	int addnum = 0;
	cout << "������Ҫ���ӵ�Ա������:  " << endl;
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
			cout << "��Ե�"<<i+1<<"��Ա��������Ϣ����" << endl;
			cout << "������Ա�����:  ";
			cin >> id;
			cout << "������Ա������:  ";
			cin >> name;
			cout << "������Ա����λ���:  "<<endl;
			cout << "1Ա��" << endl << "2����" << endl << "3�ϰ�"<<endl;
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
			default:cout << "��������"<<endl;
				break;
			}
			new_space[this->m_num + i] = Worker;
		}
		//����ְ��ָ������
		delete[] this->m_array;
		m_array = new_space;
		this->m_num = new_num;
		this->m_FileIsEmpty = false;
		//��ʾ�ɹ����
		cout << "�ɹ����" << addnum<<"��ְ��"<<endl;
		this->Save();
		system("pause");
		system("cls");
	}
	else {
		cout << "������������";
		system("pause");
		system("cls");
	}

}
void workerManager::Save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	//��ÿ���˵�����д���ļ�
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
	cout << "������Ҫɾ���ı��  " << endl;
	cin >> index;
	if (index<0 || index>this->m_num) {
		cout << "��������" << endl;
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
	cout << "ɾ�����" << endl;
	this->Save();
	system("pause");
	system("cls");
}
void workerManager::Rivise_Emp() {
	int index;
	int new_id; string new_name; int new_did;
	cout << "���������޸ĵڼ���ְԱ" << endl;
	cin >> index;
	if (index<0 || index>this->m_num) {
		cout << "��������" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��Ÿ�Ϊ:  ";
	cin >> new_id;
	cout << "������Ϊ:  ";
	cin >> new_name;
	cout << "ְλ��Ÿ�Ϊ:  "<<endl;
	cout << "1Ա��" << endl << "2����" << endl << "3�ϰ�" << endl;
	cin >> new_did;
	this->m_array[index - 1]->m_ID = new_id;
	this->m_array[index - 1]->m_Name = new_name;
	this->m_array[index - 1]->m_dept_ID = new_did;
	cout << "�޸����" << endl;
	this->Save();
	system("pause");
	system("cls");
}
void workerManager::Check_Emp() {
	int checkindex; int i;
	cout << "��������ҵı��: " << endl;
	cin >> checkindex;
	for (i = 0; i < this->m_num; i++) {
		if (this->m_array[i]->m_ID == checkindex) {
			cout << "��Ա����Ϣ����:" << endl;
			this->m_array[i]->showINFO();
		}
	}
	if (i == this->m_num) {
		cout << "δ���ҵ�" << endl;
	}
	system("pause");
	system("cls");
}
void workerManager::Resort_Emp() {
	int method;
	cout << "��ѡ������ʽ:" << endl;
	cout << "1���������" << endl;
	cout << "2����Ž���" << endl;
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
		cout << "����������ɹ�" << endl;
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
		cout << "����������ɹ�" << endl;
		system("pause");
		system("cls");
	}
}
void workerManager::Clear_File() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	ofs.close();
	cout << "�����ļ����" << endl;
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