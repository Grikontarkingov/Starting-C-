namespace mySpace{
	bool SumArray(int array[], int length){
		int sum = 0;

		for(int i = 0; i < length; i++){
				sum += array[i];
		}

		if(sum % 2 == 0){
			return true;
		}
		else {
			return false;
		}
	}
}