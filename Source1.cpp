#include "Tree.h"
#include "Collection.h"
#include "test_time.h"
#include "windows.h"

//task
bool mini(int f, int s) {
	if (f < s) { return true; }
	return false;
}
Tree union_(const Tree& a, const Tree& b) {
	Tree result = b;
	vector<int> elements = a.get_all_data();
	for (int i = 0; i < elements.size(); i++) {
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

//stuf
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
	cout << "\n\n\n\n\t\t\tСоздание дерева с головой " << value << " завершена ";
	Sleep(2000);

}
void next_programm() {
	cout << "\n\n\t\t\t\tНажмите любую кнопку, чтобы продолжить";
	_getch();
}
//interaction with trees
Tree create_Tree() {
	system("cls");
	int root, now_add, adding_el;
	cout << "\n\n\t\tВведите корень дерева: ";
	root = check();
	//loading_animation(root);
	system("cls");
	Tree result = Tree(root);
	cout << "\n\n\t\tВведите колличество элементов которое хотите добавить сейчас: ";
	now_add = check();
	if (now_add > 0) {
		for (int i = 0; i < now_add; i++) {
			cout << "\n\t\t\tДобавить элемент: ";
			adding_el = check();
			result.insert(adding_el);
		}
		cout << "\n\n\t\tНаверное все элементы были добавлены";
	}
	return result;
}
void print_all_collection(vector<Tree>& coll) {
	system("cls");
	for (int i = 0; i < coll.size(); i++) {
		cout << "\tid - [" << i << "]\t{ ";
		coll[i].Printer_tree();
		cout << " }\n\n";
	}
}
void erase_elements(vector<Tree>& coll) {
	system("cls");
	int id, count, val;
	bool flag;
	print_all_collection(coll);
	cout << "\n\n\tВведите id дерева, из которого хотите удалить элемент: ";
	id = check();
	while (id > coll.size() - 1 || id < 0) {
		system("cls");
		print_all_collection(coll);
		cout << "\n\n\tВведите существующий id дерева, из которого хотите удалить элемент: ";
		id = check();
	}
	cout << "\n\t\tВведите элемент корорый нужно удалить - ";
	val = check();
	if (coll[id].get_size() == 1) {
		if (coll[id].chek(val)) {
			coll.erase(coll.begin() + id);
			cout << "\n\t\t\tУдаление прошло успешно!!!";
		}
		else {
			cout << "\n\t\tTакого элемента нет. Попробуйте удалить сущесвующий элемент вдруг получится ;)";
		}
	}
	else {
		flag = coll[id].erase(val);
		if (flag) {
			cout << "\n\t\t\tУдаление прошло успешно!!!";
		}
		else {
			cout << "\n\t\tTакого элемента нет. Попробуйте удалить сущесвующий элемент вдруг получится ;)";
		}
	}
	next_programm();
}

//menu
int menu0() {
	while (true) {
		system("cls");
		cout << "\n\t\tДобавить первое древо - [ 1 ]\n\t\t";
		cout << "Назад                 - [esc]";
		int key= _getch();
		if (key == 27 || key == 49) {
			return key;
		}
	}
}
int menu1() {
	while (true) {
		system("cls");
		cout << "\n\t\tСоздать лес          - [ 1 ]\n\t\t";
		cout << "Показать все деревья - [ 2 ]\n\t\t";
		cout << "Действия с деревьями - [ 3 ]\n\t\t";
		cout << "Назад                - [esc]";

		int key = _getch();
		if ( key == 49 || key == 50|| key ==51) { return key; }
		else if (key == 27) {
			while (true) {
				system("cls");
				cout << "\n\n\t\tВы уверены что хотите выйти? \n\t\tВсе данные будут удалены\n\n\t\tyes  - [enter]\n\t\tno   - [ esc ]";
				key = _getch();
				if (key == 13 || key == 27) {
					return key;
				}
			}
		}
	}
}
int menu_action() {
	while (true) {
		system("cls");
		cout << "\n\n\n\t Добавить элемент в дерево           - [ 1 ]";
		cout << "\n\t Удалить элемент из дерева           - [ 2 ]";
		cout << "\n\t Объеденить 2 множества(дерева)      - [ 3 ]";
		cout << "\n\t Симметрическая разность 2 множеств  - [ 4 ]";
		cout << "\n\t Проверить есть ли элемент           - [ 5 ]";
		cout << "\n\t Вывести дерево в красивом(нет) виде - [ 6 ]";
		cout << "\n\t Удалить дерево                      - [ 7 ]";
		cout << "\n\t Посмотреть размер дерева            - [ 8 ]";
		cout << "\n\t Назад                               - [esc]";
		int key = _getch();
		if (key == 27 || key == 49 || key == 50 || key ==51|| key ==52|| key ==53|| key == 54|| key == 55|| key ==56){ return key; }
	}
}
int selection_menu() {
	int key;
	while (true) {
		cout << "\n\n\n\t\t\t\t Speed test - [ 1 ]\n";
		cout << "\t\t\t\t Main task  - [ 2 ]\n";
		cout << "\t\t\t\t Exit       - [esc]";
		key = _getch();
		if (key == 49 || key == 50 || key == 27) { return key; }
	}
}
//the choice of tree in the collection
void choice_trees_for_union(vector<Tree>& coll) {
	system("cls");
	int id1, id2, flag;

	print_all_collection(coll);
	cout << "\n\n\t\t Введите индексы множеств, которые хотите объеденить: \n\tПервый id: ";
	id1 = check();
	while (id1 >= coll.size() || id1 < 0) {
		cout << "\n\n\tВведите существующий id дерева: ";
		id1 = check();
	}
	cout << "\tВторой id: ";
	id2 = check();
	while (id2 >= coll.size() || id2 < 0) {
		cout << "\n\n\tВведите существующий id дерева: ";
		id2 = check();
	}
	Tree result = union_(coll[id1], coll[id2]);
	system("cls");
	cout << "\n\n";
	result.Printer_tree();
	cout << "\n\t\t Хотите доавить это дерево в коллекцию?";
	cout << "\n\t\t esc - no";
	cout << "\n\t\t enter - yes";
	while (true) {
		flag = _getch();
		if (flag == 13 || flag == 27) { break; }
	}
	if (flag == 27)
	{
		cout << "\n\n\t\tХозяин - барин. дерево не добавлено:(";
	}
	else {
		coll.push_back(result);
		cout << "\n\n\t\tХозяин - барин. дерево  добавлено:)";
	}
	next_programm();
}
void choice_trees_for_sd(vector<Tree> &coll){
	system("cls");
	int id1, id2,flag;

	print_all_collection(coll);
	cout << "\n\n\t\t  Введите индексы множеств, из которых хотите получить симметрическую разность";
	cout << " \n\tПервый id: ";
	id1 = check();
	while (id1 >= coll.size() || id1 < 0) {
		cout << "\n\n\tВведите существующий id дерева: ";
		id1 = check();
	}
	cout << "\tВторой id: ";
	id2 = check();
	while (id2 >= coll.size() || id2 < 0) {
		cout << "\n\n\tВведите существующий id дерева: ";
		id2 = check();
	}
	if (coll[id1] == coll[id2]) {
		cout << "\n\tПолучится пустое множество";
		next_programm();
		return;
	}
	Tree result = symmenric_difference(coll[id1], coll[id2]);
	cout << "\n\t\t Хотите доавить это дерево в коллекцию?";
	cout << "\n\t\t esc - no";
	cout << "\n\t\t enter - yes";
	while (true) {
		flag = _getch();
		if (flag == 13 || flag == 27) { break; }
	}
	if (flag == 27)
	{
		cout << "\n\tХозяин - барин. дерево не добавлено:(";
	}
	else {
		coll.push_back(result);
		cout << "\n\tХозяин - барин. дерево  добавлено:)";
	}
	next_programm();
}
void choice_tree_for_check(vector<Tree>& coll) {
	system("cls");
	int id,value;
	print_all_collection(coll);
	cout << "\n\n\t\tВведите id дерева, в котором хотите проверить элемент: ";
	id = check();
	while (id > coll.size() || id < 0) {
		system("cls");
		print_all_collection(coll);
		cout << "\n\n\tВведите существующий id дерева: ";
		id = check();
	}
	cout << "\n\t\tВведите элемент который нужно найти - ";
	value = check();
	if (coll[id].chek(value)) {
		cout << "\n\t\t\tЭлемент присутствует, не беспокойтесь!";
	}
	else {
		cout << "\n\t\t\tТаких здесь не держим!!!";
	}
	next_programm();
}
void choice_tree_for_print(vector<Tree>&coll){
	system("cls");
	int id;
	cout << "\t\t\t Введите индекс дерева которое хотите вывести в консоль: ";
	id = check();
	while (id >= coll.size() || id < 0) {
		system("cls");
		cout << " Введите корректный индекс от 0 до " << coll.size() - 1 << " : ";
		id = check();
	}
	coll[id].Printer_tree_amaizing();
	next_programm();
}
void choice_tree_for_delete(vector<Tree>& coll) {
	system("cls");
	int id,flag;
	cout << "\t\t\t Введите индекс дерева которое хотите удалить: ";
	id = check();
	while (id >= coll.size() || id < 0) {
		system("cls");
		cout << " Введите корректный индекс от 0 до " << coll.size() - 1 << " : ";
		id = check();
	}
	cout << "\n\t\tВы уверенны что хотите удалить дерево?\n\t\t esc - no\n\t\t enter - yes";
	while (true) {
		flag = _getch();
		if (flag == 27 || flag == 13) {
			break;
		}
	}
	if (flag == 13) {
		coll.erase(coll.begin() + id);
		cout << "\n\n\tОооо нет вы срубили дерево 0_0 природа вам спасибо не скажет... ";
	}
	else {
		cout << "\n\n\t\tФуууууух Грета Тунберг рада";
	}
	next_programm();
}
void choice_tree_for_add_element(vector<Tree>& coll) {
	system("cls");
	int id, value;
	print_all_collection(coll);
	cout << "\n\n\t\tВведите id дерева, в которое хотите добавить элемент: ";
	id = check();
	while (id > coll.size() || id < 0) {
		system("cls");
		print_all_collection(coll);
		cout << "\n\n\tВведите существующий id дерева: ";
		id = check();
	}
	cout << "\n\t\tВведите элемент который нужно добавить: ";
	value = check();
	if (coll[id].insert(value)) {
		cout << "\n\n\t\tЭлемент добавлен UwU";
	}
	else {
		cout << "\n\n\t\tУвы такой элемент уже есть QwQ";
	}
	next_programm();
}


void mission() {
	vector<Tree> collection;
menu:
	int menu_0 = -1;
	system("cls");
	if (collection.size() == 0) {
		menu_0 = menu0();
		if (menu_0 == 49) {
			collection.push_back(create_Tree());
			next_programm();
			goto menu;
		}
		else {return;}	
	}
	int menu_1 = menu1();
	switch (menu_1)
	{
	case 49:
		collection.push_back(create_Tree());
		next_programm();
		goto menu;
	case 50:
		print_all_collection(collection);
		next_programm();
		goto menu;
	case 51:
		break;
	case 27:
		goto menu;
	case 13:
		return;
	}
interaction_menu:
	system("cls");
	int menu_inter = menu_action();
	switch (menu_inter)
	{
	case 49:
		choice_tree_for_add_element(collection);
		goto interaction_menu;
	case 50:
		erase_elements(collection);
		if (collection.size() == 0) {
			goto menu;
		}
		goto interaction_menu;
	case 51:
		choice_trees_for_union(collection);
		goto interaction_menu;
	case 52:
		choice_trees_for_sd(collection);
		goto interaction_menu;
	case 53:
		choice_tree_for_check(collection);
		goto interaction_menu;
	case 54:
		choice_tree_for_print(collection);
		goto interaction_menu;
	case 55:
		choice_tree_for_delete(collection);
		if (collection.size() == 0) {
			goto menu;
		}
		goto interaction_menu;
	case 56:
		system("cls");
		for (int i = 0; i < collection.size(); i++) {
			collection[i].Printer_tree();
			cout << "\t" << collection[i].get_size()<<endl;
		}
		next_programm();
	case 27:
		goto menu;
	}
}


int main() {
	setlocale(LC_ALL, "ru");
menu:
	system("cls");
	int menu_select = selection_menu();
	switch (menu_select)
	{
	case 49:
		system("cls");
		speed_test_for_tree();
		speed_test_for_vector();
		next_programm();
		goto menu;
	case 50:
		mission();
		goto menu;
	default:
		break;
	}
	return 1;
}