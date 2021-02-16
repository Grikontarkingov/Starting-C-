#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void WriteText(string, string);
char* ReadText(string);
void GlueFunc(char*, char*);
void FindWord(char*, char*);

int main(int argc, char* argv[]){
	string fileNameOne = "myFileTwo.txt";
	string fileNmaeTwo = "myFileOne.txt";

	string myTextOne = "The example programs of the previous sections provided little interaction.";
	string myTextTwo = "This section will present a short introduction to some of the most useful.";

	// Написать программу, которая создаст два текстовых файла, примерно
	// по 50-100 символов в каждом (особого значения не имеет);
	
	WriteText(myTextOne, fileNameOne);

	WriteText(myTextTwo, fileNmaeTwo);

	// Написать функцию, «склеивающую» эти файлы, предварительно буферизуя их содержимое
	// в динамически выделенный сегмент памяти нужного размера.
	char* readTextOne;
	char* readTextTwo;

	readTextOne = ReadText(fileNameOne);
	readTextTwo = ReadText(fileNmaeTwo);

	GlueFunc(readTextOne, readTextTwo);

	free(readTextOne);
	free(readTextTwo);

	// * Написать программу, которая проверяет присутствует ли указанное пользователем при запуске
	// программы слово в указанном пользователем файле (для простоты работаем только с латиницей).
	char * userWord = (char * ) calloc(20, sizeof(char));

	cout << "Enter the words to find (not more 20 symbols): ";
	cin >> userWord;

	char* textForFind = ReadText("GlueFile.txt");

	FindWord(textForFind, userWord);

	system("pause");

	return 0;
}

void WriteText(string text, string filename){
	ofstream myFile(filename);

	myFile << text << endl;

	myFile.close();
}

char* ReadText(string filename){
	ifstream myFile(filename);

	int sizeOfFile;
	char* text;

	myFile.seekg(0, ios::end);
	sizeOfFile = myFile.tellg();
	myFile.seekg(0, ios::beg);

	text = (char *) calloc(sizeOfFile, sizeof(char));

	if(!myFile){
		cout << "File not found!" <<endl;
	}

	int i = 0;

	while(!myFile.eof()){
		myFile.get(text[i]);
		i++;
	}

	myFile.close();

	return text;
}

void GlueFunc(char* textOne, char* textTwo){
	char* glueText = new char[strlen(textOne) + strlen(textTwo) + 1];

	strcpy(glueText, textOne);
	strcat(glueText, textTwo);

	WriteText(glueText, "GlueFile.txt");

	delete glueText;
}

void FindWord(char* findWord, char* text){
	int i = 0;
	int count = 0;
	int sizeofText = (sizeof(text) / sizeof(text[0]));
	int sizeofFindWord = (sizeof(findWord) / sizeof(findWord[0]));

	while(i < sizeofText){
		cout << "1";
		if(text[i] = findWord[0]){
			cout << "2";
			for(int j = 0; j < sizeofFindWord; j++){
				cout << "3";
				if(text[j + i] != findWord[j]){
					cout << "break";
					count = 0;
					break;
				}
				else{
					cout << count;
					count ++;
				}
			}
			if(count == sizeofFindWord){
				cout << "Text contains this word!" << endl;
				return;
			}
		}

		i++;
	}

	cout << "Text not contains this word!" << endl;
}