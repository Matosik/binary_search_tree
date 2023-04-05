#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;
class Tree {
private:
	struct Node {
		int data;
		Node* left;
		Node* right;
		Node(int data, Node* left = nullptr, Node* right = nullptr) : data(data), left(left), right(right) {}
	};
	int size;
	Node* root = nullptr;

	void all_delete(Node* current) {
		if (current->left != nullptr) {
			all_delete(current->left);
		}
		if (current->right != nullptr) {
			all_delete(current->right);
		}
		delete current;
	}
	
	void Printer_obj(Node* current) {
		if (current == nullptr) return;
		Printer_obj(current->left);
		cout << current->data << " ";
		Printer_obj(current->right);
	}

	void amaizing_print(Node* node, int indent) {
		if (node == nullptr) {
			return;
		}

		amaizing_print(node->right, indent + 4);
		cout << string(indent, ' ') << node->data <<endl;
		amaizing_print(node->left, indent + 4);
	}

	void copy(Node*& dest, Node* src) {
		if (src == nullptr) {
			dest = nullptr;
			return;
		}
		dest = new Node(src->data);
		copy(dest->left, src->left);
		copy(dest->right, src->right);
	}

	void get_all_dataHelper(Node* node, vector<int>& result) const {
		if (node != nullptr) {
			get_all_dataHelper(node->left, result);
			result.push_back(node->data);
			get_all_dataHelper(node->right, result);
		}
	}
	
public:
	vector<int>  get_all_data() const {
		vector<int> result;
		get_all_dataHelper(root, result);
		return result;
	}
	bool operator ==(const Tree& other) {
		vector<int>a = this->get_all_data();
		vector<int>b = other.get_all_data();
		if (a.size() != b.size()) {
			return false;
		}
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) {
				return false;
			}
		}
		return true;

	}
	Tree& operator =(const Tree& other) {
		copy(this->root, other.root);

		return *this;
	}
	void Tree_del() {
		all_delete(root);
	}
	Tree(const Tree &other){
		copy(root, other.root);
		this->size = other.size;
	}
	~Tree() {
		all_delete(root);
	}
	Tree(int data) {
		root = new Node(data);
		this->size=1;
	}
	Tree() {
		root = nullptr;
	}
	int get_size() const {
		int size = this->size;
		return size; 
	}
	void get_all_elements(vector<int> &elements, Node* current ) {

		if (current == nullptr) {return;}
		elements.push_back(current->data);
		get_all_elements(elements,current->left);
		get_all_elements(elements,current->right);
	}
	void Printer_tree_amaizing() {
		amaizing_print(root, 0);
	}
	void Printer_tree() {
		if (root == nullptr) return;
		Printer_obj(root->left);
		cout << root->data << " ";
		Printer_obj(root->right);
	}
	
	bool erase(int key) {
		if (root->left == nullptr && root->right == nullptr&& root->data == key) {
			all_delete(root);
			size = 0;
			return true;
		}
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
			this->size--;
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
			this->size--;
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
		this->size--;
		return true;
	}

	bool chek(int value) const {
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
			this->size++;
			return true;
		}
		while (tmp) {
			if (data > tmp->data) {
				if (tmp->right == nullptr) {
					tmp->right = new Node(data);
					this->size++;
					return true;
				}
				tmp = tmp->right;
			}
			else if (data < tmp->data) {
				if (tmp->left == nullptr) {
					tmp->left = new Node(data);
					this->size++;
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