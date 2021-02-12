#include <iostream>
#include <stdarg.h>

namespace mySpace{
	void ChangeArrayTaskFive(int count,...){
		va_list ap;
		va_start(ap, count);

		int array[count];

		std::cout << "Your array: ";

		for(int i = 0; i < count; i++){
			array[i] = va_arg(ap, int);

			if(array[i] == 0){
				array[i] = 1;
			}
			else {
				array[i] = 0;
			}

			std::cout << array[i] << " ";
		}

		va_end(ap);

		std::cout << std::endl;
	}
}