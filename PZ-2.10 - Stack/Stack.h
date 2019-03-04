#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <ctime>

template <typename T>
class Stack
{
private:
	struct DataElement {
		T value;
		DataElement *next;
	};
	DataElement *first;
	int top;      //number of the current stack element

public:
	Stack();
	~Stack();

	T pop();      //push out element
	T peek(int);  //view nth element from top of stack
	void push(T); //pop element
	void print(); //print stack
	void clear(); //delete stack
	int size();   //size of stack
};

template <typename T>
Stack<T>::Stack() {
	first = NULL;
	top = 0;
}

template <typename T>
Stack<T>::~Stack() {
	while (first != NULL)
		pop();
}

template <typename T>
T Stack<T>::pop() {
	if (first == NULL) throw "stack is empty";
	DataElement *d = first;
	first = first->next;
	T tmp = d->value;
	top--;
	delete d;
	return tmp;
}

template <typename T>
T Stack<T>::peek(int num) {
	if (first == NULL) throw "stack is empty";
	DataElement* f = first;
	int i = 0;
	while (i != num) {
		if (f == NULL) throw "out of range";
		f = f->next;
		i++;
	}
	return f->value;
}

template <typename T>
void Stack<T>::push(T value) {
	DataElement *d = new DataElement();
	d->value = value;
	d->next = first;
	first = d;
	top++;
}

template <typename T>
void Stack<T>::print() {
	if (first == NULL) throw "stack is empty";
	DataElement* f = first;
	int i = 0;
	while (f != NULL) {
		std::cout << i << ". " << f->value << std::endl;
		f = f->next;
		i++;
	}
}

template <typename T>
void Stack<T>::clear() {
	while (first != NULL)
		pop();
}

template <typename T>
int Stack<T>::size() {
	return top;
}
