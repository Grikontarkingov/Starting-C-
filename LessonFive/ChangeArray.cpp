namespace mySpace{
	void ChangeArray(int array[], int length){
		for(int i = 0; i < length; i++){
			if(array[i] == 0){
				array[i] = 1;
			}
			else {
				array[i] = 0;
			}
		}
	}
}