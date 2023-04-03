#include "Tree.h"
#include "Collection.h"
#include "test_time.h"
#include "windows.h"


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

bool mini(int f, int s) {
	if (f < s) { return true; }
	return false;
}
Tree union_(const Tree& a, const Tree& b) {
	Tree result = b;
	vector<int> elements = a.get_all_data();
	for (int i = 0; i < a.get_size(); i++) {
		result.insert(elements[i]);
	}
	return result;
}
Tree symmenric_difference(const Tree& a, const Tree& b) {
	Tree result = union_(a, b);
	int n;
	vector<int> elements;
	if (mini(a.get_size(), b.get_size())) {
		n = a.get_size();
		elements = a.get_all_data();
		for (int i = 0; i < a.get_size(); i++) {
			if (b.chek(elements[i])) {
				result.erase(elements[i]);
			}
		}
	}
	else {
		n = b.get_size();
		elements = b.get_all_data();
		for (int i = 0; i < b.get_size(); i++) {
			if (a.chek(elements[i])) {
				result.erase(elements[i]);
			}
		}
	}
	return result;
}


void next_programm() {
	cout << "\n\n\t\t\t\t������� ����� ������, ����� ����������";
	_getch();
}
void print_all_coll(Collection& coll) {
	system("cls");
	for (int i = 0; i < coll.get_size_coll(); i++) {
		cout << "\tid - [" << i << "]\t{ ";
		coll[i].Printer_tree();
		cout << " }\n\n";
	}

}

void add_tree_in_coll(Tree a, Collection coll) {
	coll.add_collection(a);
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
	next_programm();
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
		cout<<"\n\t\t\t�������� ������ �������!!!";
	}
	else {
		cout << "\n\t\t  T����� �������� ���. ���������� ������� ����������� ������� ����� ��������� ;)";
	}
	next_programm();
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
		cout << "\n\n\n\t �������� ������� � ������ - [1]\n\t ������� ������� �� ������ - [2]\n\t ���������� 2 ���������(������) - [3]\n\t �������������� �������� 2 ��������(��������) - [4]\n\t ��������� ���� �� ������� - [5]\n\t ������� ������ � ��������(���) ���� - [6]\n\t ������� ������ - [7]\n\t ����� - [esc]";
		int key = _getch();
		if (key == 27 || key == 49 || key == 50 || key ==51|| key ==52|| key ==53|| key == 54|| key == 55){ return key; }
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
			next_programm();
			goto menu;
		case 51:
			
			break;
		case 27:
			return;
		}
	}
menuAct:
	system("cls");
	int key= menu_action();
	int id, count, val;
	switch (key) {
	case 49:
		add_elements(collection);
		goto menuAct;
	case 50:
		erase_elements(collection);
		goto menuAct;
	case 51:
		system("cls");
		print_all_coll(collection);
		cout << "\n\n\t\t ������� ������� ��������, ������� ������ ����������: \n\t ������ id: ";
		int id1, id2;
		id1 = check();
		while (id1<=collection.get_size_coll()|| id1<0) {
			cout << "\n\n\t������� ������������ id ������: ";
			id1 = check();
		}
		cout << "\t������ id: ";
		id2 = check();
		while (id2 <= collection.get_size_coll() || id2 < 0) {
			cout << "\n\n\t������� ������������ id ������: ";
			id2 = check();
		}
		Tree result = union_(collection[id1], collection[id2]);

		cout << "\n\t\t ������ ������� ��� ������ � ���������?\n\t\t esc - no\n\t\t enter - yes ";
		int flag;
		while (true) {
			flag = _getch();
			if (flag == 13 || flag == 27) { break; }
		}
		if (flag == 27)
		{
			cout << "\n\t������ - �����. ������ �� ���������:(";
		}
		else {
			add_tree_in_coll(result, collection);
			cout << "\n\t������ - �����. ������  ���������:)";
		}
		next_programm();
		goto menuAct;
	case 52:
		system("cls");
		print_all_coll(collection);
		cout << "\n\n\t\t ������� ������� ��������, �� ������� ������ �������� �������������� ��������: \n\t ������ id: ";
		id1 = check();
		while (id1 <= collection.get_size_coll() || id1 < 0) {
			cout << "\n\n\t������� ������������ id ������: ";
			id1 = check();
		}
		cout << "\t������ id: ";
		id2 = check();
		while (id2 <= collection.get_size_coll() || id2 < 0) {
			cout << "\n\n\t������� ������������ id ������: ";
			id2 = check();
		}
		Tree result2 = symmenric_difference(collection[id1], collection[id2]);
		result2.Printer_tree();

		cout << "\n\t\t ������ ������� ��� ������ � ���������?\n\t\t esc - no\n\t\t enter - yes ";
		while (true) {
			flag = _getch();
			if (flag == 13 || flag == 27) { break; }
		}
		if (flag == 27)
		{
			cout << "\n\t������ - �����. ������ �� ���������:(";
		}
		else{
			add_tree_in_coll(result2, collection);
			cout << "\n\t������ - �����. ������  ���������:)";
		}
		next_programm();
		goto menuAct;
	case 53:
		system("cls");
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
		if (collection[id].chek(val)) {
			cout << "\n\t\t\t������� ������������, �� ������������!";
		}
		else {
			cout << "\n\t\t\t����� ����� �� ������!!!";
		}
		next_programm();
		goto menuAct;
	case 54:
		system("cls");
		cout << "\t\t\t ������� ������ ������ ������� ������ ������� � �������: ";
		id = check();
		while(id>=collection.get_size_coll() || id<0){
			system("cls");
			cout << " ������� ���������� ������ �� 0 �� " << collection.get_size_coll()-1 << " : ";
			id = check();
		}
		collection[id].Printer_tree_amaizing();
		next_programm();
	case 55:
		system("cls");
		cout << "\t\t\t ������� ������ ������ ������� ������ ������� � �������: ";
		id = check();
		while (id >= collection.get_size_coll() || id < 0) {
			system("cls");
			cout << " ������� ���������� ������ �� 0 �� " << collection.get_size_coll() - 1 << " : ";
			id = check();
		}
		cout << "\n\t\t�� �������� ��� ������ ������� ������?\n\t\t esc - no\n\t\t enter - yes";
		while (true) {
			flag= _getch();
			if (flag == 27 || flag == 13) {
				break;
			}
		}
		if (flag == 13) {
			collection.delete_index(id);
			cout << "\n\n\t���� ��� �� ������� ������ 0_0 ������� ��� ������� �� ������... ";
		}
		else {
			cout << "\n\n\t\t�������� ����� ������� ����";
		}
		next_programm();
	case 27:
		goto menu;
	}
}





int main() {
	setlocale(LC_ALL, "ru");
	mission();
	//speed_test();
	//check_time_vector();
	_getch();
	return 1;
}