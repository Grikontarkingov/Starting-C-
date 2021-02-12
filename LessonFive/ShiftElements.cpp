namespace mySpace{
	void ShiftElements(int array[], int length, int n){
		int temp;

		if(n < 0){
			 n *= -1;

			for(int i = 0; i < n; i++){
				temp = array[0];

				for(int j = 1; j < length; j++){
					array[j - 1] = array[j];
				}

				array[length - 1] = temp;
			}
		}
		else {
			for(int i = 0; i < n; i++){
				temp = array[length - 1];

				for(int j = length - 1; j > 0; j--){
					array[j] = array[j - 1];
				}

				array[0] = temp;
			}
		}
		
	}
}