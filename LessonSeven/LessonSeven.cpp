#include <iostream>

#define ARRAYSIZE 5
#define CHECK(A,B) std::cout << (((A >= 0) && (B < A)) ? "Number is in the range!" : "Number isn't in the range!") << std::endl
#define GETARRAYELEMENT(ARRAY,ARRAYINDEX) std::cout << "Your element: " << (*(ARRAY + ARRAYINDEX)) << std::endl
#define GETAMOUNT(ARRAY,TYPE) (sizeof ARRAY / sizeof(TYPE))

int main(int argc, char** argv){
	// Описать макрокоманду, проверяющую, входит ли переданное ей число в диапазон от нуля
	// (включительно) до переданного ей второго аргумента (исключительно)
	int a,b;

	std::cout << "Enter upper number for range: ";
	std::cin >> a;

	std::cout << "Enter the number you want to check: ";
	std::cin >> b;

	CHECK(a,b);

	// Описать макрокоманду, получающую доступ к элементу двумерного массива (организованного динамически)
	// посредством разыменования указателей
	int *array = new int[ARRAYSIZE]{4, 3, 2, 1, 0};
	int index;

	std::cout << "Enter array index: ";
	std::cin >> index;

	if((index >= 0) && (index < ARRAYSIZE)){
		GETARRAYELEMENT(array,index);
	}
	else{
		std::cout << "You enter index out of range!" << std::endl;
	}

	delete array;

	// * Описать макрокоманду, возвращающую количество элементов локального массива, принимающую на вход
	// ссылку на массив и его тип
	int localArray[7];
	int sizeOfLocalArray;

	sizeOfLocalArray = GETAMOUNT(localArray, "int");

	std::cout << "Amount of elements: " << sizeOfLocalArray << std::endl;

	system("pause");

	return 0;
}