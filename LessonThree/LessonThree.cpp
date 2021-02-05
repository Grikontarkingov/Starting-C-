#include <iostream>
#include "LessonThreeTaskThree.h"

using namespace std;

extern const int g, h, i, j;

int main () {
	// Написать программу, вычисляющую выражение a * (b + (c / d)) и выводящую результат
	// с программу лавающей точкой, где a, b, c, d – целочисленные константы;
	double e;
	const int a = 2, b = 3, c = 4, d = 5;

	e = a * (b + ((double)c / d));

	cout << "e = " << e << endl;

	// Дано целое число, выведите на экран разницу между этим числом и числом 21. Если же 
	// заданное число больше, чем 21, необходимо вывести удвоенную разницу между этим числом
	// и 21. При выполнении задания следует использовать тернарный оператор.
	int number;

	cout << "Enter the number = ";
	cin >> number;

	int knownNumber = 21;
	int difference;

	difference = number - knownNumber;
	difference = (number > knownNumber) ? difference*2 : difference;

	cout << "Difference = " << difference << endl;

	// * Написать программу, вычисляющую выражение из первого задания, а переменные для неё инициализировать в другом файле

	double f;

	f = g * (h + ((double) i / j));

	cout << "f = " << f << endl;

	// Описать трёхмерный целочисленный массив, размером 3х3х3, указатель на значения внутри
	// массива и при помощи операции разыменования вывести на экран значение центральной
	// ячейки получившегося куба [1][1][1]
	int array[3][3][3], *array_ptr;

	array[1][1][1] = 123;
	array_ptr = &array[1][1][1];

	cout << "array[1][1][1] = " << *array_ptr << endl;

	int arrayTwo[3][3][3] = {0}, *arrayTwo_ptr;

	arrayTwo_ptr = &arrayTwo[0][0][0];
	arrayTwo[1][1][1] = 321;

	cout << "arrayTwo[1][1][1] = " << *(arrayTwo_ptr + 13) << endl;

	system("pause");

	return 0;
}