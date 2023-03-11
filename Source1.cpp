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
			cout << "\tВведите корректное число: ";
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
	cout << "\n\n\n\n\t\t\tСоздаем ваше дерево .......";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\tСоздаем ваше дерево |......";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\tСоздаем ваше дерево ||.....";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\tСоздаем ваше дерево |||....";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\tСоздаем ваше дерево ||||...";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\tСоздаем ваше дерево |||||..";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\tСоздаем ваше дерево ||||||.";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\tСоздаем ваше дерево |||||||";
	system("cls");
	cout << "\n\n\n\n\t\t\tСоздание дерева с головой "<<value<<" завершена ";
	Sleep(2000);

}
void add_in_coll(Collection &coll) {
	system("cls");
	cout << "\n\n\t\tВведите корень дерева: ";
	int root;
	int now_add;
	root= check();
	//loading_animation(root);
	system("cls");
	Tree newTree(root);
	cout << "\n\n\t\tВведите колличество элементов которое хотите добавить сейчас: ";
	now_add = check();
	if (now_add > 0) {
		int adding_el;
		for (int i = 0; i < now_add; i++) {
			cout << "\n\t\t\tДобавить элемент: ";
			adding_el= check();
			newTree.insert(adding_el);
		}
		cout << "\n\n\t\tНаверное все элементы были добавлены\n\t   Если захотите добавить еще элементы можете сделать это в главном меню.";
	}
	coll.add_collection(newTree);
	cout << "\n\n\t\t Нажмите любую кнопку,чтобы вернуться в главное меню.";
	_getch();
}
void add_elements(Collection &coll) {
	system("cls");
	int id, count,val;
	bool flag;
	print_all_coll(coll);
	cout << "\n\n\t\tВведите id дерева, в которое хотите добавить элемент: ";
	id = check();
	while (id > coll.get_size_coll() || id < 0) {
		system("cls");
		print_all_coll(coll);
		cout << "\n\n\tВведите существующий id дерева,  в которое хотите добавить элемент:: ";
		id = check();
	}
	cout << "\n\t\tСколько элементов желаете добавить - ";
	count = check();
	for (int i = 0; i < count; i++) {
		cout << "\n\t\t\tДобавть: ";
		val = check();
		flag = coll[id].insert(val);
		if (!flag) {
			cout << "\t\t\t\t" << val << " уже есть";
		}
	}
}
void erase_elements(Collection& coll) {
	system("cls");
	int id, count, val;
	print_all_coll(coll);
	cout << "\n\n\tВведите id дерева, из которого хотите удалить элемент: ";
	id = check();
	while (id > coll.get_size_coll()-1 || id < 0) {
		system("cls");
		print_all_coll(coll);
		cout << "\n\n\tВведите существующий id дерева, из которого хотите удалить элемент: ";
		id = check();
	}
	cout << "\n\t\tВведите элемент корорый нужно удалить - ";
	val = check();
	bool flag = coll[id].erase(val);
	if (flag) {
		cout<<"\n\t\t\tУдаление прошло успешно!!!\n\n\t\t\tНажмите любую кнопку чтобы продолжить";
	}
	else {
		cout << "\n\t\t  Tакого элемента нет. Попробуйте удалить сущесвующий элемент вдруг получится ;)\n\n\t\t  Нажмите любую кнопку чтобы вернуться в меню выбора ";
	}
	_getch();
}
void del_from_coll(Collection &coll) {


}
int menu0() {
	while (true) {
		system("cls");
		cout << "\n\t\tДобавить первое древо - [1]\n\t\tЗавершить работу - [esc]";
		int key= _getch();
		if (key == 27 || key == 49) {
			return key;
		}
	}
}

int menu1() {
	while (true) {
		system("cls");
		cout << "\n\t\tСоздать лес - [1]\n\t\tПоказать все деревья - [2]\n\t\tДействия с деревьями - [3]\n\t\tЗавершить работу - [esc]";
		int key = _getch();
		if (key == 27 || key == 49 || key == 50|| key ==51) { return key; }
	}
}

int menu_action() {
	while (true) {
		system("cls");
		cout << "\n\n\n\t Добавить элемент в дерево - [1]\n\t Удалить элемент из дерева - [2]\n\t Объеденить 2 множества(дерева) - [3]\n\t Симметрическая разность 2 множеств(деревьев) - [4]\n\t Проверить есть ли элемент - [5]\n\t Назад - [esc]";
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
			cout << "\n\n\t\t\t\tНажмите любую кнопку, чтобы продолжить";
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
		cout << "\n\n\t\tВведите id дерева, в котором хотите проверить элемент: ";
		id = check();
		while (id > collection.get_size_coll() || id < 0) {
			system("cls");
			print_all_coll(collection);
			cout << "\n\n\tВведите существующий id дерева, из которого хотите удалить элемент: ";
			id = check();
		}
		cout << "\n\t\tВведите элемент который нужно найти - ";
		val=check();
		flag = collection[id].chek(val);
		if (flag) {
			cout << "\n\t\t\tЭлемент присутствует, не беспокойтесь! \n\n\t\t\tНажмите любую кнопку чтобы продолжить";
		}
		else {
			cout << "\n\t\t\tТаких здесь не держим!!!\n\n\t\t\tНажмите любую кнопку чтобы продолжить";
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
	cout << "Среднее время заполнения дерева 1,000 элементами: " << mid_value / 100<<endl;


	mid_value = 0;
	for (int i = 0; i < 100; i++) {
		fill_val = fill_time(10000);
		mid_value += fill_val;
	}
	cout << "Среднее время заполнения дерева 10,000 элементами: " << mid_value / 100 << endl;

	mid_value = 0;
	for (int i = 0; i < 100; i++) {
		fill_val = fill_time(100000);
		mid_value += fill_val;
	}
	cout << "Среднее время заполнения дерева 100,000 элементами: " << mid_value / 100 << endl<<endl;

	mid_value = 0;
	for (int i = 0; i < 1000; i++) {
		fill_val = seek_time(1000);
		mid_value += fill_val;
	}


	cout << "Среднее время поиска элемента в дереве на 1,000 элементов: " << seek_time(1000)<<endl;
	cout << "Среднее время поиска элемента в дереве на 10,000 элементов: " << seek_time(10000)<<endl;
	cout << "Среднее время поиска элемента в дереве на 100,000 элементов: " << seek_time(100000)<<endl<<endl;

	cout << "Среднее время ДОБАВЛЕНИЯ элемента в дерево на 1,000 элементов: " << insert_time(1000) << endl;
	cout << "Среднее время ДОБАВЛЕНИЯ элемента в дерево на 10,000 элементов: " << insert_time(10000) << endl;
	cout << "Среднее время ДОБАВЛЕНИЯ элемента в дерево на 100,000 элементов: " << insert_time(100000) <<endl <<endl;


	cout << "Среднее время УДАЛЕНИЯ элемента из дерева на 1,000 элементов: " << erase_time(1000) << endl;
	cout << "Среднее время УДАЛЕНИЯ элемента из дерева на 10,000 элементов: " << erase_time(10000) << endl;
	cout << "Среднее время УДАЛЕНИЯ элемента из дерева на 100,000 элементов: " << erase_time(100000) <<endl<< endl;

		
}


int main() {
	setlocale(LC_ALL, "ru");
	mission();
	//speed_test();
	_getch();
	return 1;
}