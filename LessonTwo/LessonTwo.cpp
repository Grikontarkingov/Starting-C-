#include <iostream>

using namespace std;
int main ()
{
	//Создать и инициализировать переменные пройденных типов данных
	int a = 5;
	double b = 3.0;
	char c = 'c';

	cout << "Date types: a = " << a << " b = " << b << " c = " << c << endl;

	//Создать перечисление с возможными вариантами символов для игры в крестики-нолики
	enum canSymbols {o, x};

	//Создать массив, способный содержать значения такого перечисления и инициализировать его.
	int array[3][3] = {0};

	//* Создать структуру данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами
	struct fieldPropeties {
		enum canSymbols symb;
		int field[3][3];
	}FieldProperties;

	FieldProperties.symb = o;
	cout << "enum: o = " << FieldProperties.symb;
	FieldProperties.symb = x;
	cout << " and x = " << FieldProperties.symb << endl;

	union differentTypes {
		int d;
		float e;
		char f;
	};

	union differentTypes anyNumb;

	struct taskFive{
		union differentTypes DifferentTypes;
		int isInt   : 1;
		int isFloat : 1;
		int isChar  : 1;
	} TaskFive;

	anyNumb.d = 3;
	cout << "Symbol of union = " << anyNumb.d;
	cout << " isInt = " << TaskFive.isInt;
	cout << "  isFloat = " << TaskFive.isFloat;
	cout << "  isChar = " << TaskFive.isChar << endl;

	system("pause");

	return 0;
}