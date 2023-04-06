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
			cout << "\tEnter the correct number: ";
		}
	}
	return number;
}

void next_programm() {
	cout << "\n\n\t\t\t\tPress any key to continue";
	_getch();
}
//interaction with trees
Tree create_Tree() {
	system("cls");
	int root, now_add, adding_el;
	cout << "\n\n\t\tInput root for tree: ";
	root = check();
	//loading_animation(root);
	system("cls");
	Tree result = Tree(root);
	cout << "\n\n\t\tEnter the number of elements you want to add now: ";
	now_add = check();
	if (now_add > 0) {
		for (int i = 0; i < now_add; i++) {
			cout << "\n\t\t\tAdd element: ";
			adding_el = check();
			result.insert(adding_el);
		}
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
	cout << "\n\n\tInput the tree index that you want delete element: ";
	id = check();
	while (id > coll.size() - 1 || id < 0) {
		system("cls");
		print_all_collection(coll);
		cout << "\n\n\tInput correct index: ";
		id = check();
	}
	cout << "\n\t\tInput value that you want erase: ";
	val = check();
	if (coll[id].get_size() == 1) {
		if (coll[id].chek(val)) {
			coll.erase(coll.begin() + id);
			cout << "\n\t\t\tDeleted!!!";
		}
		else {
			cout << "\n\t\tIs not deleted";
		}
	}
	else {
		flag = coll[id].erase(val);
		if (flag) {
			cout << "\n\t\t\tDeleted!!!";
		}
		else {
			cout << "\n\t\tIs not deleted";
		}
	}
	next_programm();
}

//menu
int menu0() {
	while (true) {
		system("cls");
		cout << "\n\n\t\t\tAdd first Tree - [ 1 ]\n\t\t\t";
		cout << "Back           - [esc]";
		int key= _getch();
		if (key == 27 || key == 49) {
			return key;
		}
	}
}
int menu1() {
	while (true) {
		system("cls");
		cout << "\n\t\tCreat forest         - [ 1 ]\n\t\t";
		cout << "Show all trees       - [ 2 ]\n\t\t";
		cout << "Actions with trees   - [ 3 ]\n\t\t";
		cout << "Back                 - [esc]";

		int key = _getch();
		if ( key == 49 || key == 50|| key ==51) { return key; }
		else if (key == 27) {
			while (true) {
				system("cls");
				cout << "\n\n\t\tAre you sure you want to get out? \n\t\tAll data will be deleted\n\n\t\tyes  - [enter]\n\t\tno   - [ esc ]";
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
		cout << "\n\n\n\tAdd element to the tree             - [ 1 ]";
		cout << "\n\t Delete element from tree           - [ 2 ]";
		cout << "\n\t Union 2 trees                      - [ 3 ]";
		cout << "\n\t Symmetric difference of 2 trees    - [ 4 ]";
		cout << "\n\t Check element                      - [ 5 ]";
		cout << "\n\t Nice output to the consol          - [ 6 ]";
		cout << "\n\t Delete tree                        - [ 7 ]";
		cout << "\n\t See the number of elements         - [ 8 ]";
		cout << "\n\t Back                               - [esc]";
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
	cout << "\n\n\t\t Input index trees that you want to union: \n\tFirst id: ";
	id1 = check();
	while (id1 >= coll.size() || id1 < 0) {
		cout << "\n\n\tInput current id: ";
		id1 = check();
	}
	cout << "\tSecond id: ";
	id2 = check();
	while (id2 >= coll.size() || id2 < 0) {
		cout << "\n\n\tInput current id: ";
		id2 = check();
	}
	Tree result = union_(coll[id1], coll[id2]);
	system("cls");
	cout << "\n\n";
	result.Printer_tree();
	cout << "\n\t\t Want to add this tree to your collection?";
	cout << "\n\t\t esc - no";
	cout << "\n\t\t enter - yes";
	while (true) {
		flag = _getch();
		if (flag == 13 || flag == 27) { break; }
	}
	if (flag == 27)
	{
		cout << "\n\n\t\tTree is not added:(";
	}
	else {
		coll.push_back(result);
		cout << "\n\n\t\tTree is added:)";
	}
	next_programm();
}
void choice_trees_for_sd(vector<Tree> &coll){
	system("cls");
	int id1, id2,flag;

	print_all_collection(coll);
	cout << "\n\n\t\t Input index trees that you want to symmetric difference:";
	cout << " \n\t First id: ";
	id1 = check();
	while (id1 >= coll.size() || id1 < 0) {
		cout << "\n\n\t Input current id: ";
		id1 = check();
	}
	cout << "\t Second id: ";
	id2 = check();
	while (id2 >= coll.size() || id2 < 0) {
		cout << "\n\n\t Input current id: ";
		id2 = check();
	}
	if (coll[id1] == coll[id2]) {
		cout << "\n\t We got an empty set";
		next_programm();
		return;
	}
	Tree result = symmenric_difference(coll[id1], coll[id2]);
	cout << "\n\t\t Want to add this tree to your collection?";
	cout << "\n\t\t esc - no";
	cout << "\n\t\t enter - yes";
	while (true) {
		flag = _getch();
		if (flag == 13 || flag == 27) { break; }
	}
	if (flag == 27)
	{
		cout << "\n\tTree is not added:(";
	}
	else {
		coll.push_back(result);
		cout << "\n\tTree is added:)";
	}
	next_programm();
}
void choice_tree_for_check(vector<Tree>& coll) {
	system("cls");
	int id,value;
	print_all_collection(coll);
	cout << "\n\n\t\tInput index trees that you want check element: ";
	id = check();
	while (id > coll.size() || id < 0) {
		system("cls");
		print_all_collection(coll);
		cout << "\n\n\tInput current id: ";
		id = check();
	}
	cout << "\n\t\tInput value to be checked: ";
	value = check();
	if (coll[id].chek(value)) {
		cout << "\n\t\t\tElement is present !";
	}
	else {
		cout << "\n\t\t\tWe don't keep them here!!!";
	}
	next_programm();
}
void choice_tree_for_print(vector<Tree>&coll){
	system("cls");
	int id;
	cout << "\t\t\t Input index that you want print in concole: ";
	id = check();
	while (id >= coll.size() || id < 0) {
		system("cls");
		cout << " Input index from 0 to " << coll.size() - 1 << " : ";
		id = check();
	}
	coll[id].Printer_tree_amaizing();
	next_programm();
}
void choice_tree_for_delete(vector<Tree>& coll) {
	system("cls");
	int id,flag;
	cout << "\t\t\t Input index that want you delete: ";
	id = check();
	while (id >= coll.size() || id < 0) {
		system("cls");
		cout << " Input index from 0 to " << coll.size() - 1 << " : ";
		id = check();
	}
	cout << "\n\t\tYou sure that want delete tree?\n\t\t esc - no\n\t\t enter - yes";
	while (true) {
		flag = _getch();
		if (flag == 27 || flag == 13) {
			break;
		}
	}
	if (flag == 13) {
		coll.erase(coll.begin() + id);
		cout << "\n\n\tNature will not thank you... ";
	}
	else {
		cout << "\n\n\t\tThe tree is saved!!!0w0 ";
	}
	next_programm();
}
void choice_tree_for_add_element(vector<Tree>& coll) {
	system("cls");
	int id, value;
	print_all_collection(coll);
	cout << "\n\n\t\tInput index that you want added element: ";
	id = check();
	while (id > coll.size() || id < 0) {
		system("cls");
		print_all_collection(coll);
		cout << "\n\n\tInpt cuurent index: ";
		id = check();
	}
	cout << "\n\t\tInput value that add in tree: ";
	value = check();
	if (coll[id].insert(value)) {
		cout << "\n\n\t\tElement added UwU";
	}
	else {
		cout << "\n\n\t\tElement not is added QwQ";
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
	setlocale(LC_ALL, "RUS");
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
