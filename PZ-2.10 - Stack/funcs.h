#include "Stack.h"

template <typename T>
void safeEnter(T &value)
{
	while (!(std::cin >> value)) {
		std::cin.clear();
		while (std::cin.get() != '\n') continue;
		std::cout << "Input error. Try again: ";
	}
}

int menu() {
	int choise;
	std::cout << "\n1. Create stack\n"
		      << "2. Delete stack\n"
		      << "3. Push element\n"
		      << "4. Pop element\n"
		      << "5. Download nums\n"
		      << "6. Print stack\n"
		      << "7. Print curent element\n"
		      << "8. Exit programm\n"
		      << "\nSelect an option: ";
	try {
		safeEnter(choise);
		if ((choise < 0) || (choise > 8)) throw "nonexistent menu option";
	}
	catch (const char* s) {
		std::cout << "Error: " << s << std::endl;
	}
	
	return choise;
}

template <typename T>
void createStack(Stack<T>& stack)
{
	if (stack.size() != 0) throw "stack already created";

	int size;
	std::cout << "Size: ";
	safeEnter(size);
	if (size < 1) throw "invalid size";

	T range;
	std::cout << "Range: ";
	safeEnter(range);

	for (int i = 0; i < size; i++)
		stack.push((T)rand() / RAND_MAX * range);
	std::cout << "Stack created" << std::endl;
}

template <typename T>
void deleteStack(Stack<T>& stack)
{
	if (stack.size() == 0) throw "stack is empty";
	stack.clear();
	std::cout << "Stack deleted" << std::endl;
}

template <typename T>
void pushElement(Stack<T>& stack)
{
	if (stack.size() == 0) throw "stack is empty";

	T element;
	std::cout << "Input element: ";
	safeEnter(element);

	stack.push(element);
	std::cout << "Element pushed onto stack" << std::endl;
}

template <typename T>
T popElement(Stack<T>& stack)
{
	if (stack.size() == 0) throw "stack is empty";

	T element = stack.pop();
	std::cout << "Element popped from stack" << std::endl;

	return element;
}

template <typename T>
void downloadNums(Stack<T>& stack) {
	if (stack.size() == 0) throw "stack is empty";

	std::string fileName;
	std::cout << "Input file name: ";
	std::cin >> fileName;

	std::fstream f(fileName, std::ios_base::in);
	if (!f.is_open()) throw "file does not exist";

	std::string num;
	while (std::getline(f, num, ' '))
		stack.push(std::stof(num));

	f.close();
	std::cout << "Nums loaded onto the stack" << std::endl;
}

template <typename T>
void printStack(Stack<T>& stack) {
	if (stack.size() == 0) throw "stack is empty";
	stack.print();
}

template <typename T>
void peekElement(Stack<T>& stack) {
	if (stack.size() == 0) throw "stack is empty";

	int num;
	std::cout << "Number of element: ";
	safeEnter(num);

	if (num < 0) throw "invalid number";

	std::cout << stack.peek(num) << std::endl;
}
