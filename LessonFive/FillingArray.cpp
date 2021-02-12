namespace mySpace{
	void FillingArray(int array[],int length){
		int number = 1;

		for(int i = 0; i < length; i++){
			array[i] = number;

			number+=3;
		}
	}
}