#include <iostream>
#include <stdarg.h>
#include "LessonFiveTaskSix.h"

using namespace std;
 
int main(int argc, char** argv){
	// Задать целочисленный массив, состоящий из элементов 0 и 1.
	// Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию,
	// заменяющую в принятом массиве 0 на 1, 1 на 0;

	int arrayOne[5] = {1, 0, 0, 1, 1};
	int lengthOne = sizeof(arrayOne) / sizeof(arrayOne[0]);

	mySpace::PrintIntArray(arrayOne, lengthOne);
	mySpace::ChangeArray(arrayOne, lengthOne);
	mySpace::PrintIntArray(arrayOne, lengthOne);

	// Задать пустой целочисленный массив размером 8. Написать функцию,
	// которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;
	int arrayTwo[8];
	int lengthTwo = sizeof(arrayTwo) / sizeof(arrayTwo[0]);

	mySpace::FillingArray(arrayTwo, lengthTwo);
	mySpace::PrintIntArray(arrayTwo, lengthTwo);

	// * Написать метод, в который передается не пустой одномерный целочисленный
	// массив, метод должен вернуть истину если в массиве есть место, в котором
	// сумма левой и правой части массива равны. Примеры:
	// checkBalance([1, 1, 1, || 2, 1]) → true,
	// checkBalance ([2, 1, 1, 2, 1]) → false,
	// checkBalance ([10, || 1, 2, 3, 4]) → true.
	// Абстрактная граница показана символами ||, эти символы в массив не входят.
	int arrayThree[5] = {10, 1, 2, 3, 4};
	int lengthThree = sizeof(arrayThree) / sizeof(arrayThree[0]);
	bool sumArray;

	sumArray = mySpace::SumArray(arrayThree, lengthThree);

	mySpace::PrintIntArray(arrayThree, lengthThree);
	cout << "The sum of the left and right are equal? - " << (sumArray ? "true" : "false") << endl;

	// * Написать функцию, которой на вход подаётся одномерный массив и число n
	// (может быть положительным, или отрицательным), при этом метод должен
	// циклически сместить все элементы массива на n позиций.
	int arrayFour[5] = {10, 1, 2, 3, 4};
	int lengthFour = sizeof(arrayFour) / sizeof(arrayFour[0]);
	int n = -2;

	mySpace::PrintIntArray(arrayFour, lengthFour);
	mySpace::ShiftElements(arrayFour, lengthFour, n);
	mySpace::PrintIntArray(arrayFour, lengthFour);

	// ** Написать функцию из первого задания так, чтобы она работала с
	// аргументом переменной длины.
	mySpace::ChangeArrayTaskFive(6, 0, 1, 0, 0, 1, 1);

	// ** Написать все функции в отдельных файлах в одном пространстве имён,
	// вызвать их на исполнение в основном файле программы используя указатели на функции.

	system("pause");

	return 0;
}