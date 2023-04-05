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
			cout << "\tÂâåäèòå êîððåêòíîå ÷èñëî: ";
		}
	}
	return number;
}
void loading_animation(int value) {
	system("cls");

	Sleep(400);
	cout << "\n\n\n\n\t\t\tÑîçäàåì âàøå äåðåâî .......";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\tÑîçäàåì âàøå äåðåâî |......";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\tÑîçäàåì âàøå äåðåâî ||.....";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\tÑîçäàåì âàøå äåðåâî |||....";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\tÑîçäàåì âàøå äåðåâî ||||...";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\tÑîçäàåì âàøå äåðåâî |||||..";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\tÑîçäàåì âàøå äåðåâî ||||||.";
	Sleep(400);
	system("cls");
	cout << "\n\n\n\n\t\t\tÑîçäàåì âàøå äåðåâî |||||||";
	system("cls");
	cout << "\n\n\n\n\t\t\tÑîçäàíèå äåðåâà ñ ãîëîâîé " << value << " çàâåðøåíà ";
	Sleep(2000);

}
void next_programm() {
	cout << "\n\n\t\t\t\tÍàæìèòå ëþáóþ êíîïêó, ÷òîáû ïðîäîëæèòü";
	_getch();
}
//interaction with trees
Tree create_Tree() {
	system("cls");
	int root, now_add, adding_el;
	cout << "\n\n\t\tÂâåäèòå êîðåíü äåðåâà: ";
	root = check();
	//loading_animation(root);
	system("cls");
	Tree result = Tree(root);
	cout << "\n\n\t\tÂâåäèòå êîëëè÷åñòâî ýëåìåíòîâ êîòîðîå õîòèòå äîáàâèòü ñåé÷àñ: ";
	now_add = check();
	if (now_add > 0) {
		for (int i = 0; i < now_add; i++) {
			cout << "\n\t\t\tÄîáàâèòü ýëåìåíò: ";
			adding_el = check();
			result.insert(adding_el);
		}
		cout << "\n\n\t\tÍàâåðíîå âñå ýëåìåíòû áûëè äîáàâëåíû";
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
	cout << "\n\n\tÂâåäèòå id äåðåâà, èç êîòîðîãî õîòèòå óäàëèòü ýëåìåíò: ";
	id = check();
	while (id > coll.size() - 1 || id < 0) {
		system("cls");
		print_all_collection(coll);
		cout << "\n\n\tÂâåäèòå ñóùåñòâóþùèé id äåðåâà, èç êîòîðîãî õîòèòå óäàëèòü ýëåìåíò: ";
		id = check();
	}
	cout << "\n\t\tÂâåäèòå ýëåìåíò êîðîðûé íóæíî óäàëèòü - ";
	val = check();
	if (coll[id].get_size() == 1) {
		if (coll[id].chek(val)) {
			coll.erase(coll.begin() + id);
			cout << "\n\t\t\tÓäàëåíèå ïðîøëî óñïåøíî!!!";
		}
		else {
			cout << "\n\t\tTàêîãî ýëåìåíòà íåò. Ïîïðîáóéòå óäàëèòü ñóùåñâóþùèé ýëåìåíò âäðóã ïîëó÷èòñÿ ;)";
		}
	}
	else {
		flag = coll[id].erase(val);
		if (flag) {
			cout << "\n\t\t\tÓäàëåíèå ïðîøëî óñïåøíî!!!";
		}
		else {
			cout << "\n\t\tTàêîãî ýëåìåíòà íåò. Ïîïðîáóéòå óäàëèòü ñóùåñâóþùèé ýëåìåíò âäðóã ïîëó÷èòñÿ ;)";
		}
	}
	next_programm();
}

//menu
int menu0() {
	while (true) {
		system("cls");
		cout << "\n\t\tÄîáàâèòü ïåðâîå äðåâî - [ 1 ]\n\t\t";
		cout << "Íàçàä                 - [esc]";
		int key= _getch();
		if (key == 27 || key == 49) {
			return key;
		}
	}
}
int menu1() {
	while (true) {
		system("cls");
		cout << "\n\t\tÑîçäàòü ëåñ          - [ 1 ]\n\t\t";
		cout << "Ïîêàçàòü âñå äåðåâüÿ - [ 2 ]\n\t\t";
		cout << "Äåéñòâèÿ ñ äåðåâüÿìè - [ 3 ]\n\t\t";
		cout << "Íàçàä                - [esc]";

		int key = _getch();
		if ( key == 49 || key == 50|| key ==51) { return key; }
		else if (key == 27) {
			while (true) {
				system("cls");
				cout << "\n\n\t\tÂû óâåðåíû ÷òî õîòèòå âûéòè? \n\t\tÂñå äàííûå áóäóò óäàëåíû\n\n\t\tyes  - [enter]\n\t\tno   - [ esc ]";
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
		cout << "\n\n\n\t Äîáàâèòü ýëåìåíò â äåðåâî           - [ 1 ]";
		cout << "\n\t Óäàëèòü ýëåìåíò èç äåðåâà           - [ 2 ]";
		cout << "\n\t Îáúåäåíèòü 2 ìíîæåñòâà(äåðåâà)      - [ 3 ]";
		cout << "\n\t Ñèììåòðè÷åñêàÿ ðàçíîñòü 2 ìíîæåñòâ  - [ 4 ]";
		cout << "\n\t Ïðîâåðèòü åñòü ëè ýëåìåíò           - [ 5 ]";
		cout << "\n\t Âûâåñòè äåðåâî â êðàñèâîì(íåò) âèäå - [ 6 ]";
		cout << "\n\t Óäàëèòü äåðåâî                      - [ 7 ]";
		cout << "\n\t Ïîñìîòðåòü ðàçìåð äåðåâà            - [ 8 ]";
		cout << "\n\t Íàçàä                               - [esc]";
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
	cout << "\n\n\t\t Ââåäèòå èíäåêñû ìíîæåñòâ, êîòîðûå õîòèòå îáúåäåíèòü: \n\tÏåðâûé id: ";
	id1 = check();
	while (id1 >= coll.size() || id1 < 0) {
		cout << "\n\n\tÂâåäèòå ñóùåñòâóþùèé id äåðåâà: ";
		id1 = check();
	}
	cout << "\tÂòîðîé id: ";
	id2 = check();
	while (id2 >= coll.size() || id2 < 0) {
		cout << "\n\n\tÂâåäèòå ñóùåñòâóþùèé id äåðåâà: ";
		id2 = check();
	}
	Tree result = union_(coll[id1], coll[id2]);
	system("cls");
	cout << "\n\n";
	result.Printer_tree();
	cout << "\n\t\t Õîòèòå äîàâèòü ýòî äåðåâî â êîëëåêöèþ?";
	cout << "\n\t\t esc - no";
	cout << "\n\t\t enter - yes";
	while (true) {
		flag = _getch();
		if (flag == 13 || flag == 27) { break; }
	}
	if (flag == 27)
	{
		cout << "\n\n\t\tÕîçÿèí - áàðèí. äåðåâî íå äîáàâëåíî:(";
	}
	else {
		coll.push_back(result);
		cout << "\n\n\t\tÕîçÿèí - áàðèí. äåðåâî  äîáàâëåíî:)";
	}
	next_programm();
}
void choice_trees_for_sd(vector<Tree> &coll){
	system("cls");
	int id1, id2,flag;

	print_all_collection(coll);
	cout << "\n\n\t\t  Ââåäèòå èíäåêñû ìíîæåñòâ, èç êîòîðûõ õîòèòå ïîëó÷èòü ñèììåòðè÷åñêóþ ðàçíîñòü";
	cout << " \n\tÏåðâûé id: ";
	id1 = check();
	while (id1 >= coll.size() || id1 < 0) {
		cout << "\n\n\tÂâåäèòå ñóùåñòâóþùèé id äåðåâà: ";
		id1 = check();
	}
	cout << "\tÂòîðîé id: ";
	id2 = check();
	while (id2 >= coll.size() || id2 < 0) {
		cout << "\n\n\tÂâåäèòå ñóùåñòâóþùèé id äåðåâà: ";
		id2 = check();
	}
	if (coll[id1] == coll[id2]) {
		cout << "\n\tÏîëó÷èòñÿ ïóñòîå ìíîæåñòâî";
		next_programm();
		return;
	}
	Tree result = symmenric_difference(coll[id1], coll[id2]);
	cout << "\n\t\t Õîòèòå äîàâèòü ýòî äåðåâî â êîëëåêöèþ?";
	cout << "\n\t\t esc - no";
	cout << "\n\t\t enter - yes";
	while (true) {
		flag = _getch();
		if (flag == 13 || flag == 27) { break; }
	}
	if (flag == 27)
	{
		cout << "\n\tÕîçÿèí - áàðèí. äåðåâî íå äîáàâëåíî:(";
	}
	else {
		coll.push_back(result);
		cout << "\n\tÕîçÿèí - áàðèí. äåðåâî  äîáàâëåíî:)";
	}
	next_programm();
}
void choice_tree_for_check(vector<Tree>& coll) {
	system("cls");
	int id,value;
	print_all_collection(coll);
	cout << "\n\n\t\tÂâåäèòå id äåðåâà, â êîòîðîì õîòèòå ïðîâåðèòü ýëåìåíò: ";
	id = check();
	while (id > coll.size() || id < 0) {
		system("cls");
		print_all_collection(coll);
		cout << "\n\n\tÂâåäèòå ñóùåñòâóþùèé id äåðåâà: ";
		id = check();
	}
	cout << "\n\t\tÂâåäèòå ýëåìåíò êîòîðûé íóæíî íàéòè - ";
	value = check();
	if (coll[id].chek(value)) {
		cout << "\n\t\t\tÝëåìåíò ïðèñóòñòâóåò, íå áåñïîêîéòåñü!";
	}
	else {
		cout << "\n\t\t\tÒàêèõ çäåñü íå äåðæèì!!!";
	}
	next_programm();
}
void choice_tree_for_print(vector<Tree>&coll){
	system("cls");
	int id;
	cout << "\t\t\t Ââåäèòå èíäåêñ äåðåâà êîòîðîå õîòèòå âûâåñòè â êîíñîëü: ";
	id = check();
	while (id >= coll.size() || id < 0) {
		system("cls");
		cout << " Ââåäèòå êîððåêòíûé èíäåêñ îò 0 äî " << coll.size() - 1 << " : ";
		id = check();
	}
	coll[id].Printer_tree_amaizing();
	next_programm();
}
void choice_tree_for_delete(vector<Tree>& coll) {
	system("cls");
	int id,flag;
	cout << "\t\t\t Ââåäèòå èíäåêñ äåðåâà êîòîðîå õîòèòå óäàëèòü: ";
	id = check();
	while (id >= coll.size() || id < 0) {
		system("cls");
		cout << " Ââåäèòå êîððåêòíûé èíäåêñ îò 0 äî " << coll.size() - 1 << " : ";
		id = check();
	}
	cout << "\n\t\tÂû óâåðåííû ÷òî õîòèòå óäàëèòü äåðåâî?\n\t\t esc - no\n\t\t enter - yes";
	while (true) {
		flag = _getch();
		if (flag == 27 || flag == 13) {
			break;
		}
	}
	if (flag == 13) {
		coll.erase(coll.begin() + id);
		cout << "\n\n\tÎîîî íåò âû ñðóáèëè äåðåâî 0_0 ïðèðîäà âàì ñïàñèáî íå ñêàæåò... ";
	}
	else {
		cout << "\n\n\t\tÔóóóóóóõ Ãðåòà Òóíáåðã ðàäà";
	}
	next_programm();
}
void choice_tree_for_add_element(vector<Tree>& coll) {
	system("cls");
	int id, value;
	print_all_collection(coll);
	cout << "\n\n\t\tÂâåäèòå id äåðåâà, â êîòîðîå õîòèòå äîáàâèòü ýëåìåíò: ";
	id = check();
	while (id > coll.size() || id < 0) {
		system("cls");
		print_all_collection(coll);
		cout << "\n\n\tÂâåäèòå ñóùåñòâóþùèé id äåðåâà: ";
		id = check();
	}
	cout << "\n\t\tÂâåäèòå ýëåìåíò êîòîðûé íóæíî äîáàâèòü: ";
	value = check();
	if (coll[id].insert(value)) {
		cout << "\n\n\t\tÝëåìåíò äîáàâëåí UwU";
	}
	else {
		cout << "\n\n\t\tÓâû òàêîé ýëåìåíò óæå åñòü QwQ";
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
