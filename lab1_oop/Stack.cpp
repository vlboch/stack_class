#include "pch.h"
#include "Stack.h"
#include <math.h>
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

// �����������
Stack::Stack(int _type, int _maxSize,  const char* name)
{
	MaxSize = _maxSize;
	stack_arr = new int[MaxSize];
	type = _type;
	size = -1;
	cout << "���� " << this <<" "<< type << " ����i���: " << MaxSize <<" ��������. \n";
}

// ����������� ���������
Stack::Stack(const Stack & other) {
	MaxSize = other.MaxSize;
	type = other.type;
	stack_arr = new int [other.MaxSize];
	size = other.size;
	
	for (int i = 0; i < other.size + 1; i++) {
		stack_arr[i] = other.stack_arr[i];
	}

	cout << "����������� ���i������ ����i���� ����� � " << &other << " � " << this << endl;
}

// ���������� ��������� ������������
void Stack::operator= (const Stack & other) {
	cout << "��������� �������� = "<< endl;

	size = other.size;
	MaxSize = other.MaxSize;
	type = other.type;

	if (this->stack_arr!= nullptr) {
		delete[] this->stack_arr;
	}

	this->stack_arr = new int[other.MaxSize];

	for (int i = 0; i < other.size + 1; i++) {
		stack_arr[i] = other.stack_arr[i];
	}
}

// ���������� ��������� ==
bool Stack::operator==(const Stack &other) {
	
	if (size != other.size) {
		return false;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (stack_arr[i] == other.stack_arr[i]) {
				continue;
			}
			else {
				return false;
			}
			return true;
		}
	}
}

// ���������� ��������� !=
bool Stack::operator!=(const Stack &other) {

	if (size != other.size) {
		return true;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (stack_arr[i] == other.stack_arr[i]) {
				continue;
			}
			else {
				return true;
			}
		}
		return false;

	}
}

// ��������� �������� � ������� �����
void Stack::push(int element)  {
	size = size + 1;
	if (size < MaxSize) {
		stack_arr[size] = element;
	}
	else {
		cout << "���� " << this << " ����������!\n";
	}
}

// �������� ������� ������� �����
int Stack::getTop() const {
	return stack_arr[size];
}

// ��������: �� ������ ����
bool Stack::isEmpty() const {
	if (size <= 0) {
		return true;
	}
	else {
		return false;
	}
}

// ��������: �� ���� ����������
bool Stack::isFull() const {
	if (size == MaxSize) {
		return true;
	}
	else {
		return false;
	}
}

// ���� ������� �� �����
void Stack::print() const {
	for (int i = size; i > -1; i--) {
		cout << stack_arr[i] << "\t";
	}
}

// ����������� 
Stack::~Stack()
{
	delete[] stack_arr;
	cout << "\n���������� ��i��� ������� ��������� ������ - " << this;
}



