#pragma once
#include "Tree.h"


class Collection
{
private:
	Tree* coll;
	int size;

public:
	~Collection() {
		for (int i = 0; i < size - 1; i++) {
			coll[i].Tree_del();
		}
	}
	Collection() {
		size = 0;
		coll = NULL;
	}
	int get_size_coll() {
		return size;
	}

	void add_collection(Tree poly) {
		if (coll == NULL) {
			Collection();
		}
		size++;
		Tree* new_coll = new Tree(size);
		for (int i = 0; i < size - 1; i++) {
			new_coll[i] = coll[i];
		}
		delete[] coll;
		coll = new_coll;
		coll[size - 1] = poly;
	}

	void delete_collection() {
		size = 0;
		delete[] coll;
		coll = NULL;
	}
	void delete_index(int& index) {
		if (size == 1) {
			index = 0;
			delete_collection();
			return;
		}
		for (int i = index; i < size - 1; i++) {
			coll[i] = coll[i + 1];
		}
		index = 0;
		size-- ;
		Tree* new_coll = new Tree(size);
		for (int i = 0; i < size; i++) {
			new_coll[i] = coll[i];
		}
		delete[] coll;
		coll = new_coll;
	}
	Tree& operator[](int id) {
		return coll[id];
	}
};
