#include "funcs.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(static_cast<unsigned int>(time(NULL)));

	Stack<float> stack;
	int choise = 0;

	do {
		choise = menu();

		try {
			switch (choise)
			{
			case 1: createStack(stack);
				break;
			case 2: deleteStack(stack);
				break;
			case 3: pushElement(stack);
				break;
			case 4: popElement(stack);
				break;
			case 5: downloadNums(stack);
				break;
			case 6: printStack(stack);
				break;
			case 7: peekElement(stack);
				break;
			case 8:
				break;
			default:
				break;
			}
		}
		catch (const char* s) {
			std::cout << "Error: " << s << std::endl;
		}
		
	} while (choise != 8);

	return EXIT_SUCCESS;
}
