#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int data, Node* left = nullptr, Node* right = nullptr) : data(data), left(left), right(right) {}
};
class Tree {
private:
	int size;
	Node* root = nullptr;
	void all_delete(Node* current);

	void Printer_obj(Node* current);

	void amaizing_print(Node* node, int indent);

	void copy(Node*& dest, Node* src);

	void get_all_dataHelper(Node* node, vector<int>& result) const;
	
public:
	vector<int>  get_all_data() const;
	bool operator ==(const Tree& other);
	Tree& operator =(const Tree& other);
	void Tree_delete();
	Tree(const Tree& other);
	~Tree();
	Tree(int data);
	Tree();
	int get_size() const;
	void Printer_tree_amaizing();
	void Printer_tree();
	bool erase(int key);

	bool chek(int value) const;
	bool insert(int data);
};