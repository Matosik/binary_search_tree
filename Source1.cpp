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
			cout << "\tВведите корректное число: ";
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
	cout << "\n\n\t\t\t\tНажмите любую кнопку, чтобы продолжить";
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
	next_programm();
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
		cout<<"\n\t\t\tУдаление прошло успешно!!!";
	}
	else {
		cout << "\n\t\t  Tакого элемента нет. Попробуйте удалить сущесвующий элемент вдруг получится ;)";
	}
	next_programm();
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
		cout << "\n\n\n\t Добавить элемент в дерево - [1]\n\t Удалить элемент из дерева - [2]\n\t Объеденить 2 множества(дерева) - [3]\n\t Симметрическая разность 2 множеств(деревьев) - [4]\n\t Проверить есть ли элемент - [5]\n\t Вывести дерево в красивом(нет) виде - [6]\n\t Удалить дерево - [7]\n\t Назад - [esc]";
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
		cout << "\n\n\t\t Введите индексы множеств, которые хотите объеденить: \n\t Первый id: ";
		int id1, id2;
		id1 = check();
		while (id1<=collection.get_size_coll()|| id1<0) {
			cout << "\n\n\tВведите существующий id дерева: ";
			id1 = check();
		}
		cout << "\tВторой id: ";
		id2 = check();
		while (id2 <= collection.get_size_coll() || id2 < 0) {
			cout << "\n\n\tВведите существующий id дерева: ";
			id2 = check();
		}
		Tree result = union_(collection[id1], collection[id2]);

		cout << "\n\t\t Хотите доавить это дерево в коллекцию?\n\t\t esc - no\n\t\t enter - yes ";
		int flag;
		while (true) {
			flag = _getch();
			if (flag == 13 || flag == 27) { break; }
		}
		if (flag == 27)
		{
			cout << "\n\tХозяин - барин. дерево не добавлено:(";
		}
		else {
			add_tree_in_coll(result, collection);
			cout << "\n\tХозяин - барин. дерево  добавлено:)";
		}
		next_programm();
		goto menuAct;
	case 52:
		system("cls");
		print_all_coll(collection);
		cout << "\n\n\t\t Введите индексы множеств, из которых хотите получить симметрическую разность: \n\t Первый id: ";
		id1 = check();
		while (id1 <= collection.get_size_coll() || id1 < 0) {
			cout << "\n\n\tВведите существующий id дерева: ";
			id1 = check();
		}
		cout << "\tВторой id: ";
		id2 = check();
		while (id2 <= collection.get_size_coll() || id2 < 0) {
			cout << "\n\n\tВведите существующий id дерева: ";
			id2 = check();
		}
		Tree result2 = symmenric_difference(collection[id1], collection[id2]);
		result2.Printer_tree();

		cout << "\n\t\t Хотите доавить это дерево в коллекцию?\n\t\t esc - no\n\t\t enter - yes ";
		while (true) {
			flag = _getch();
			if (flag == 13 || flag == 27) { break; }
		}
		if (flag == 27)
		{
			cout << "\n\tХозяин - барин. дерево не добавлено:(";
		}
		else{
			add_tree_in_coll(result2, collection);
			cout << "\n\tХозяин - барин. дерево  добавлено:)";
		}
		next_programm();
		goto menuAct;
	case 53:
		system("cls");
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
		if (collection[id].chek(val)) {
			cout << "\n\t\t\tЭлемент присутствует, не беспокойтесь!";
		}
		else {
			cout << "\n\t\t\tТаких здесь не держим!!!";
		}
		next_programm();
		goto menuAct;
	case 54:
		system("cls");
		cout << "\t\t\t Введите индекс дерева которое хотите вывести в консоль: ";
		id = check();
		while(id>=collection.get_size_coll() || id<0){
			system("cls");
			cout << " Введите корректный индекс от 0 до " << collection.get_size_coll()-1 << " : ";
			id = check();
		}
		collection[id].Printer_tree_amaizing();
		next_programm();
	case 55:
		system("cls");
		cout << "\t\t\t Введите индекс дерева которое хотите вывести в консоль: ";
		id = check();
		while (id >= collection.get_size_coll() || id < 0) {
			system("cls");
			cout << " Введите корректный индекс от 0 до " << collection.get_size_coll() - 1 << " : ";
			id = check();
		}
		cout << "\n\t\tВы уверенны что хотите удалить дерево?\n\t\t esc - no\n\t\t enter - yes";
		while (true) {
			flag= _getch();
			if (flag == 27 || flag == 13) {
				break;
			}
		}
		if (flag == 13) {
			collection.delete_index(id);
			cout << "\n\n\tОооо нет вы срубили дерево 0_0 природа вам спасибо не скажет... ";
		}
		else {
			cout << "\n\n\t\tФуууууух Грета Тунберг рада";
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