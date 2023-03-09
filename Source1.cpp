#include <iostream>
#include <conio.h>
using namespace std;


// Бинарный поиск
class Tree {
private:

	struct Node {
		int data;
		Node* left;
		Node* right;
		Node(int data, Node* left = nullptr, Node* right = nullptr) : data(data), left(left), right(right) {}
	};

	Node* root = nullptr;

	void Printer_obj(Node* current) {
		if (current == nullptr) return;
		Printer_obj(current->left);
		cout << current->data << endl;
		Printer_obj(current->right);
	}

	void all_delete(Node* current) {
		if (current->left != nullptr) {
			all_delete(current->left);
		}
		if (current->right != nullptr) {
			all_delete(current->right);
		}
		delete current;
	}

public:
	~Tree() {
		all_delete(root);
	}

	Tree(int data = 0) {
		root = new Node(data);
	}
	//Tree(Tree const& other) {
	//	/*other дай нам все свои значения 
	//	мы вызовим от всех этих значений метод insert и добавим в this дерево */
	//}

	void Printer_tree() {
		//Node* tmp = current;
		if (root == nullptr) return;
		Printer_obj(root->left);
		cout << root->data << endl;
		Printer_obj(root->right);
	}
	bool erase(int key) {
		Node* current = root;
		Node* parent = nullptr;
		while (current && current->data != key) {
			parent = current;
			if (key<current->data) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}


		if (!current) {
			return false;
		}

		// у элемента 1 потомок
		if (current->left==nullptr) {
			if (parent && parent->left == current) {
				parent->left = current->right;
			}
			if (parent && parent->right == current) {
				parent->right = current->right;
			}
			delete current;
			return true;
		}


		if (current->right == nullptr) {
			if (parent && parent->left == current) {
				parent->left = current->left;
			}
			if (parent && parent->right == current) {
				parent->right = current->left;
			}
			delete current;
			return true;
		}

		// у элемента 2 потомка
		Node* replace= current->right;
		while (replace->left) {
			replace = replace->left;
		}
		int replace_val = replace->data;
		erase(replace_val);
		current->data = replace_val;
		return true;
	}
	bool insert(int data) {
		Node* tmp = root;
		while (tmp) {
			if (data > tmp->data) {
				if (tmp->right == nullptr) {
					tmp->right = new Node(data);
					return true;
				}
				tmp = tmp->right;
			}
			else if (data < tmp->data) {
				if (tmp->left == nullptr) {
					tmp->left = new Node(data);
					return true;
				}
				tmp = tmp->left;
			}
			else {
				return false;
			}
		}

	}

};

//Tree union_(const Tree& a, const Tree& b) {
//	return;
//}
//
//Tree symmenric_difference(const Tree& a, const Tree& b) {
//	return;
//}

void main() {
	setlocale(LC_ALL, "ru");
	Tree myTree(10);
	myTree.insert(5);


	myTree.insert(12);
	myTree.insert(11);
	myTree.insert(13);
	myTree.insert(4);
	myTree.insert(6);
	myTree.erase(12);
	myTree.Printer_tree();

	cout << "Нажмите любую кнопку, чтобы завершить работу программы.";
	_getch();
}