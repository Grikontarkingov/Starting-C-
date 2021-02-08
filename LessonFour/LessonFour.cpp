#include <iostream>

int main (){
	int check = 1; // выход из программ;

	// Написать программу, проверяющую что сумма двух чисел лежит в пределах
	// от 10 до 20 (включительно), если да – вывести true, в противном случае – false;
	do{
		std::cout << "Task 1" << std::endl;

		int firstNum, secondNum, sum = 0;

		std::cout << "Enter the first integer = ";
		std::cin >> firstNum;

		std::cout << "Enter the second integer = ";
		std::cin >> secondNum;

		sum = firstNum + secondNum;

		if((sum >= 10) && (sum <= 20)){
			std::cout << "True" << std::endl;
		}
		else{
			std::cout << "False" << std::endl;
		}

		std::cout << "Enter 0, if you want continue or 1 to retry ";
		std::cin >> check;

	}while(check != 0);

	// Написать программу, проверяющую, является ли некоторое число - натуральным простым.
	// Простое число - это число, которое делится без остатка только на единицу и себя само.
	check = 1;

	while(check != 0){
		std::cout << "Task 2" << std::endl;

		int simpleNum;

		std::cout << "Enter the integer = ";
		std::cin >> simpleNum;

		if(simpleNum == 1){
			std::cout << "Your enter a non-natural simple!" << std::endl;
		}
		else{
			for(int i = 2; i <= simpleNum; i++){
				if(i == simpleNum){
					std::cout << "Your enter a natural simple!" << std::endl;
					break;
				}
				else if(simpleNum % i == 0){
					std::cout << "Your enter a non-natural simple!" << std::endl;
					break;
				}
			}
		}

		std::cout << "Enter 0, if you want continue or 1 to retry ";
		std::cin >> check;
	};
	

	// Написать программу, выводящую на экран “истину”, если две целочисленные константы,
	// объявленные в её начале либо равны десяти сами по себе, либо их сумма равна десяти.
	check = 1;

	do{
		std::cout << "Task 3" << std::endl;

		int firstNum, secondNum;

		std::cout << "Enter the first integer = ";
		std::cin >> firstNum;

		std::cout << "Enter the second integer = ";
		std::cin >> secondNum;

		if(((firstNum == 10) && (secondNum == 10)) || (firstNum + secondNum == 10)){
			std::cout << "True" << std::endl;
		}
		else{
			std::cout << "False" << std::endl;
		}

		std::cout << "Enter 0, if you want continue or 1 to retry ";
		std::cin >> check;

	}while(check != 0);
	

	// Написать программу, которая определяет является ли год високосным. Каждый 4-й год
	// является високосным, кроме каждого 100-го, при этом каждый 400-й – високосный. Для
	// проверки работы вывести результаты работы программы в консоль
	check = 1;

	do{
		std::cout << "Task 4" << std::endl;

		int getYear;

		std::cout << "Enter the year = ";
		std::cin >> getYear;

		if(getYear % 4 != 0){
			std::cout << "This is not leap-year!" << std::endl;
		}
		else{
			if(getYear % 100 != 0){
				std::cout << "This is leap-year!" << std::endl;
			}
			else{
				if(getYear % 400 == 0){
					std::cout << "This is leap-year!" << std::endl;
				}
				else{
					std::cout << "This is not leap-year!" << std::endl;
				}
			}
		}

		std::cout << "Enter 0, if you want continue or 1 to retry ";
		std::cin >> check;

	}while(check != 0);

	system("pause");

	return 0;
}