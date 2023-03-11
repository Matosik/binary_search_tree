#include "Tree.h"
#include "Collection.h"
#include <time.h>
using namespace std;


int check()
{
	int number = 0;

	while (!(cin >> number) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			system("cls");
			cout << "\t������� ���������� �����: ";
		}
	}
	return number;
}

Tree union_(const Tree& a, const Tree& b) {
	for (int )
}

//Tree symmenric_difference(const Tree& a, const Tree& b) {
//	return;
//}
void print_all_coll(Collection& coll) {
	system("cls");
	for (int i = 0; i < coll.get_size_coll(); i++) {
		cout << "\tid - [" << i << "]\t{ ";
		coll[i].Printer_tree();
		cout << " }\n\n";
	}

}
void loading_animation(int value) {
	system("cls");

	Sleep(400);
	cout << "\n\n\n\n\t\t\t������� ���� ������ .......";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\t������� ���� ������ |......";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\t������� ���� ������ ||.....";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\t������� ���� ������ |||....";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\t������� ���� ������ ||||...";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\t������� ���� ������ |||||..";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\t������� ���� ������ ||||||.";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\t������� ���� ������ |||||||";
	system("cls");
	cout << "\n\n\n\n\t\t\t�������� ������ � ������� "<<value<<" ��������� ";
	Sleep(2000);

}
void add_in_coll(Collection &coll) {
	system("cls");
	cout << "\n\n\t\t������� ������ ������: ";
	int root;
	int now_add;
	root= check();
	//loading_animation(root);
	system("cls");
	Tree newTree(root);
	cout << "\n\n\t\t������� ����������� ��������� ������� ������ �������� ������: ";
	now_add = check();
	if (now_add > 0) {
		int adding_el;
		for (int i = 0; i < now_add; i++) {
			cout << "\n\t\t\t�������� �������: ";
			adding_el= check();
			newTree.insert(adding_el);
		}
		cout << "\n\n\t\t�������� ��� �������� ���� ���������\n\t   ���� �������� �������� ��� �������� ������ ������� ��� � ������� ����.";
	}
	coll.add_collection(newTree);
	cout << "\n\n\t\t ������� ����� ������,����� ��������� � ������� ����.";
	_getch();
}
void add_elements(Collection &coll) {
	system("cls");
	int id, count,val;
	bool flag;
	print_all_coll(coll);
	cout << "\n\n\t\t������� id ������, � ������� ������ �������� �������: ";
	id = check();
	while (id > coll.get_size_coll() || id < 0) {
		system("cls");
		print_all_coll(coll);
		cout << "\n\n\t������� ������������ id ������,  � ������� ������ �������� �������:: ";
		id = check();
	}
	cout << "\n\t\t������� ��������� ������� �������� - ";
	count = check();
	for (int i = 0; i < count; i++) {
		cout << "\n\t\t\t�������: ";
		val = check();
		flag = coll[id].insert(val);
		if (!flag) {
			cout << "\t\t\t\t" << val << " ��� ����";
		}
	}
}
void erase_elements(Collection& coll) {
	system("cls");
	int id, count, val;
	print_all_coll(coll);
	cout << "\n\n\t������� id ������, �� �������� ������ ������� �������: ";
	id = check();
	while (id > coll.get_size_coll()-1 || id < 0) {
		system("cls");
		print_all_coll(coll);
		cout << "\n\n\t������� ������������ id ������, �� �������� ������ ������� �������: ";
		id = check();
	}
	cout << "\n\t\t������� ������� ������� ����� ������� - ";
	val = check();
	bool flag = coll[id].erase(val);
	if (flag) {
		cout<<"\n\t\t\t�������� ������ �������!!!\n\n\t\t\t������� ����� ������ ����� ����������";
	}
	else {
		cout << "\n\t\t  T����� �������� ���. ���������� ������� ����������� ������� ����� ��������� ;)\n\n\t\t  ������� ����� ������ ����� ��������� � ���� ������ ";
	}
	_getch();
}
void del_from_coll(Collection &coll) {


}
int menu0() {
	while (true) {
		system("cls");
		cout << "\n\t\t�������� ������ ����� - [1]\n\t\t��������� ������ - [esc]";
		int key= _getch();
		if (key == 27 || key == 49) {
			return key;
		}
	}
}

int menu1() {
	while (true) {
		system("cls");
		cout << "\n\t\t������� ��� - [1]\n\t\t�������� ��� ������� - [2]\n\t\t�������� � ��������� - [3]\n\t\t��������� ������ - [esc]";
		int key = _getch();
		if (key == 27 || key == 49 || key == 50|| key ==51) { return key; }
	}
}

int menu_action() {
	while (true) {
		system("cls");
		cout << "\n\n\n\t �������� ������� � ������ - [1]\n\t ������� ������� �� ������ - [2]\n\t ���������� 2 ���������(������) - [3]\n\t �������������� �������� 2 ��������(��������) - [4]\n\t ��������� ���� �� ������� - [5]\n\t ����� - [esc]";
		int key = _getch();
		if (key == 27 || key == 49 || key == 50 || key ==51|| key ==52|| key ==53){ return key; }
	}
}

void mission() {
	Collection collection;
menu:
	//menu0
	system("cls");
	Tree newTree;
	if (collection.get_size_coll() == 0) {
		int key=menu0();
		if(key== 49) {
			add_in_coll(collection);
			goto menu;
		}
		else if(key ==27){
			return;
		}
	}
	//menu1 
	else {
		int key = menu1();
		switch(key){
		case 49: 
			add_in_coll(collection);
			goto menu;
		
		case 50:
			print_all_coll(collection);
			cout << "\n\n\t\t\t\t������� ����� ������, ����� ����������";
			_getch();
			goto menu;
		case 51:
			
			break;
		case 27:
			return;
		}
	}
menuAct:
	system("cls");
	bool flag;
	int key= menu_action();
	switch (key) {
	case 49:
		add_elements(collection);
		goto menuAct;
	case 50:
		erase_elements(collection);
		goto menuAct;
	case 51:
		goto menuAct;
	case 52:
		goto menuAct;
	case 53:
		system("cls");
		int id, count, val;
		print_all_coll(collection);
		cout << "\n\n\t\t������� id ������, � ������� ������ ��������� �������: ";
		id = check();
		while (id > collection.get_size_coll() || id < 0) {
			system("cls");
			print_all_coll(collection);
			cout << "\n\n\t������� ������������ id ������, �� �������� ������ ������� �������: ";
			id = check();
		}
		cout << "\n\t\t������� ������� ������� ����� ����� - ";
		val=check();
		flag = collection[id].chek(val);
		if (flag) {
			cout << "\n\t\t\t������� ������������, �� ������������! \n\n\t\t\t������� ����� ������ ����� ����������";
		}
		else {
			cout << "\n\t\t\t����� ����� �� ������!!!\n\n\t\t\t������� ����� ������ ����� ����������";
		}
		_getch();
		goto menuAct;
	case 27:
		goto menu;
	}
}

size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

int fill_time(int count) {
	int start = clock();
	Tree myTree;
	for (int i = 0; i < count; i++) {
		myTree.insert(lcg());
	}
	int end = clock();
	return end - start;
}
double seek_time(int count) {
	Tree myTree;
	for (int i = 0; i < count; i++) {
		myTree.insert(lcg());
	}
	clock_t start = clock();
	for (int i = 0; i < 1000; i++) {
		myTree.chek(lcg());
		
	}
	clock_t end =  clock();
	return (start-end) /1000;
}
double insert_time(int count) {
	Tree myTree;
	for (int i = 0; i < count; i++) {
		myTree.insert(lcg());
	}
	int start = clock();
	for (int i = 0; i < 1000; i++) {
		myTree.insert(lcg());
	}
	int end = clock();
	return (end - start)/1000;
}
double erase_time(int count) {
	Tree myTree;
	for (int i = 0; i < count; i++) {
		myTree.insert(lcg());
	}
	int start = clock();
	for (int i = 0; i < 1000; i++) {
		myTree.erase(lcg());
	}
	int end = clock();
	return (start-end) / 1000;
}

void speed_test() {
	double mid_value = 0;
	int fill_val;
	for (int i = 0; i < 100; i++) {
		fill_val = fill_time(1000);
		mid_value += fill_val;
	}
	cout << "������� ����� ���������� ������ 1,000 ����������: " << mid_value / 100<<endl;


	mid_value = 0;
	for (int i = 0; i < 100; i++) {
		fill_val = fill_time(10000);
		mid_value += fill_val;
	}
	cout << "������� ����� ���������� ������ 10,000 ����������: " << mid_value / 100 << endl;

	mid_value = 0;
	for (int i = 0; i < 100; i++) {
		fill_val = fill_time(100000);
		mid_value += fill_val;
	}
	cout << "������� ����� ���������� ������ 100,000 ����������: " << mid_value / 100 << endl<<endl;

	mid_value = 0;
	for (int i = 0; i < 1000; i++) {
		fill_val = seek_time(1000);
		mid_value += fill_val;
	}


	cout << "������� ����� ������ �������� � ������ �� 1,000 ���������: " << seek_time(1000)<<endl;
	cout << "������� ����� ������ �������� � ������ �� 10,000 ���������: " << seek_time(10000)<<endl;
	cout << "������� ����� ������ �������� � ������ �� 100,000 ���������: " << seek_time(100000)<<endl<<endl;

	cout << "������� ����� ���������� �������� � ������ �� 1,000 ���������: " << insert_time(1000) << endl;
	cout << "������� ����� ���������� �������� � ������ �� 10,000 ���������: " << insert_time(10000) << endl;
	cout << "������� ����� ���������� �������� � ������ �� 100,000 ���������: " << insert_time(100000) <<endl <<endl;


	cout << "������� ����� �������� �������� �� ������ �� 1,000 ���������: " << erase_time(1000) << endl;
	cout << "������� ����� �������� �������� �� ������ �� 10,000 ���������: " << erase_time(10000) << endl;
	cout << "������� ����� �������� �������� �� ������ �� 100,000 ���������: " << erase_time(100000) <<endl<< endl;

		
}


int main() {
	setlocale(LC_ALL, "ru");
	mission();
	//speed_test();
	_getch();
	return 1;
}