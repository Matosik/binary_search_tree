#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include "windows.h"

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
		cout << current->data << " ";
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
	void Tree_del() {
		all_delete(root);
	}

	/*~Tree() {
		all_delete(root);
	}*/

	Tree(int data) {
		root = new Node(data);
	}
	Tree() {
		root = nullptr;
	}

	


	//Tree(Tree const& other) {
	//	/*other дай нам все свои значения 
	//	мы вызовим   от всех этих значений метод insert и добавим в this дерево */
	//	root->data = other.root->data;
	//	Node* tmp = other.root;
	//	while (tmp) {
	//		this->insert(tmp->data);
	//		if (tmp == nullptr) { goto; }
	//	}
	//}
	void Printer_tree() {
		//Node* tmp = current;
		if (root == nullptr) return;
		Printer_obj(root->left);
		cout << root->data << " ";
		Printer_obj(root->right);
	}
	bool erase(int key) {
		Node* current = root;
		Node* parent = nullptr;
		while (current && current->data != key) {
			parent = current;
			if (key < current->data) {
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
		if (current->left == nullptr) {
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
		Node* replace = current->right;
		while (replace->left) {
			replace = replace->left;
		}
		int replace_val = replace->data;
		erase(replace_val);
		current->data = replace_val;
		return true;
	}

	bool chek(int value) {
		Node* tmp = root;
		while (tmp) {
			if (value > tmp->data) {
				if (tmp->right == nullptr) {
					return false;
				}
				tmp = tmp->right;
			}
			else if (value < tmp->data) {
				if (tmp->left == nullptr) {
					return false;
				}
				tmp = tmp->left;
			}
			else {
				return true;
			}
		}
	}
	bool insert(int data) {
		Node* tmp = root;
		if (root == nullptr) {
			root = new Node(data);
			return true;
		}
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