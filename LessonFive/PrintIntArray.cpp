#include <iostream>

namespace mySpace{
	void PrintIntArray(int array[], int length){
		std::cout << "Your array:";

		for(int i = 0; i < length; i++){
			printf(" %d", array[i]);
		}

		std::cout << std::endl;
	}
}