#pragma once
#include "Tree.h"
#include <time.h>
#include <list>
#include <chrono>

size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

float fill_time(int count) {
	//int start = clock();
	auto start = chrono::high_resolution_clock::now();
	Tree myTree;
	for (int i = 0; i < count; i++) {
		myTree.insert(lcg());
	}
	auto end = chrono::high_resolution_clock::now();
	//int end = clock();
	chrono::duration<float> result = end - start;
	return result.count();
}
float seek_time(int count) {
	Tree myTree;
	for (int i = 0; i < count; i++) {
		myTree.insert(lcg());
	}
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000; i++) {
		myTree.chek(lcg());

	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> result = end - start;
	return result.count() / 1000;
}
float insert_time(int count) {
	Tree myTree;
	for (int i = 0; i < count; i++) {
		myTree.insert(lcg());
	}
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000; i++) {
		myTree.insert(lcg());
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> result = end - start;
	return result.count() / 1000;
}
float erase_time(int count) {
	Tree myTree;
	for (int i = 0; i < count; i++) {
		myTree.insert(lcg());
	}
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000; i++) {
		myTree.erase(lcg());
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> result = end - start;
	return result.count() / 1000;
}

void speed_test_for_tree() {
	double mid_value = 0;
	float fill_val;
	for (int i = 0; i < 100; i++) {
		fill_val = fill_time(1000);
		mid_value += fill_val;
	}
	cout << "������� ����� ���������� ������ 1,000 ����������: " << mid_value / 100 << endl;


	mid_value = 0;
	for (int i = 0; i < 100; i++) {
		fill_val = fill_time(10000);
		mid_value += fill_val;
	}
	cout << "������� ����� ���������� ������ 10,000 ����������: " << mid_value / 100 << endl;

	mid_value = 0;
	for (int i = 0; i < 100; i++) {
		fill_val = fill_time(100000);
		mid_value += fill_val;
	}
	cout << "������� ����� ���������� ������ 100,000 ����������: " << mid_value / 100 << endl << endl;

	mid_value = 0;
	for (int i = 0; i < 1000; i++) {
		fill_val = seek_time(1000);
		mid_value += fill_val;
	}


	cout << "������� ����� ������ �������� � ������ �� 1,000 ���������: " << seek_time(1000) << endl;
	cout << "������� ����� ������ �������� � ������ �� 10,000 ���������: " << seek_time(10000) << endl;
	cout << "������� ����� ������ �������� � ������ �� 100,000 ���������: " << seek_time(100000) << endl << endl;

	cout << "������� ����� ���������� �������� � ������ �� 1,000 ���������: " << insert_time(1000) << endl;
	cout << "������� ����� ���������� �������� � ������ �� 10,000 ���������: " << insert_time(10000) << endl;
	cout << "������� ����� ���������� �������� � ������ �� 100,000 ���������: " << insert_time(100000) << endl << endl;


	cout << "������� ����� �������� �������� �� ������ �� 1,000 ���������: " << erase_time(1000) << endl;
	cout << "������� ����� �������� �������� �� ������ �� 10,000 ���������: " << erase_time(10000) << endl;
	cout << "������� ����� �������� �������� �� ������ �� 100,000 ���������: " << erase_time(100000) << endl << endl;


}


float vec_fill(int count) {
	vector<int> myV;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < count; j++) { //
			myV.push_back(lcg());
		}
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> result = end - start;
	return result.count() / 100;
}
float vec_seek(int count) {
	vector<int> myV;
	int mid_time = 0;
	for (int j = 0; j < count; j++) {
		myV.push_back(lcg());
	}
	mid_time = 0;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000; i++) {
		find(myV.begin(), myV.end(), lcg()) != myV.end();
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> result = end - start;
	return result.count()/1000;
}

void speed_test_for_vector() {
	cout << "C������ ����� ���������� ������� �� 1.000 ���������: " << vec_fill(1000) << endl;
	cout << "C������ ����� ���������� ������� �� 10.000 ���������: " << vec_fill(10000) << endl;
	cout << "C������ ����� ���������� ������� �� 100.000 ���������: " << vec_fill(100000) << endl << endl;
	//=====================����� ��������====================================

	cout << "C������ ����� ������ �������� �  ������� �� 1.000 ���������: " << vec_seek(1000) << endl;
	cout << "C������ ����� ������ �������� �  ������� �� 10.000 ���������: " << vec_seek(10000) << endl;
	cout << "C������ ����� ������ �������� �  ������� �� 100.000 ���������: " << vec_seek(100000) << endl << endl;
}