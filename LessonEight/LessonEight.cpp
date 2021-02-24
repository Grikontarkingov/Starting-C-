#include <iostream>
#include <random>
#include <algorithm>

#define CHECK(A,B) (((A) >= (0)) && ((A) < (B)))
#define GETARRAYELEMENT(ARRAY,ARRAYINDEXUPPER,ARRAYINDEXDOWNER) (*((*((ARRAY) + (ARRAYINDEXUPPER))) + (ARRAYINDEXDOWNER)))

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(0, 2);

enum SYMBGAME { PLAYER = 'X', AI = 'O', EMPTY = '_' };

typedef struct {
	int sizeX;
	int sizeY;
	SYMBGAME **map;
	int toWin;
} Field;

char getValue(SYMBGAME **array, const int y, const int x){
	return GETARRAYELEMENT(array, y, x);
}

void setValue(SYMBGAME **array, const int y, const int x, SYMBGAME symb){
	GETARRAYELEMENT(array, y, x) = symb;
}

//init field
void initField(Field &field){
	field.toWin = 3;
	field.sizeX = 3;
	field.sizeY = 3;
	field.map = new SYMBGAME *[field.sizeY];

	for(int y = 0; y < field.sizeY; y++){
		field.map[y] = new SYMBGAME[field.sizeX];

		for(int x = 0; x < field.sizeX; x++){
			setValue(field.map, y, x, EMPTY);
		}
	}
}

//print field
void printField(Field &field){
	std::system("cls");

	std::cout << " -1-2-3-\n";

	for(int i = 0; i < field.sizeY; i++){
		std::cout << (i + 1) << "|";
		for(int j = 0; j < field.sizeX; j++){
			std::cout << getValue(field.map, i, j) << "|";
		}
		std::cout << std::endl;
	}
}


//check cell empty
bool isEmpty(Field &field, const int x, const int y){
	return getValue(field.map, y, x) == EMPTY;
}

bool isRange(Field &field, const int x, const int y){
	return CHECK(x, field.sizeX) && CHECK(y, field.sizeY);
}

//player turn
void playerTurn(Field &field){
	int x;
	int y;
	bool isError = false;

	do{
		if(isError){
			std::cout << "Your coordinates is incorrect!" << std::endl;
		}

		std::cout << "Enter upper and downer elements a space separated from 1 to 3: ";

		std::cin >> x;
		std::cin.ignore(1);
		std::cin >> y;

		x--; y--;
		isError = true;

	}while(!isRange(field, x, y) || !isEmpty(field, x, y));

	setValue(field.map, y, x, PLAYER);
}

// check draw
bool isDraw(Field &field){
	for(int y = 0; y < field.sizeY; y++){
		for(int x = 0; x < field.sizeX; x++){
			if(isEmpty(field, x, y)){
				return false;
			}
		}
	}

	return true;
}

// check win
bool checkLine(Field &field, int y, int x, int vx, int vy, int length, SYMBGAME symb){
	const int endX = x + (length - 1) * vx;
	const int endY = y + (length - 1) * vy;

	if (!isRange(field, endX, endY)){
		return false;
	}

	for (int i = 0; i < length; i++) {
		if (getValue(field.map, (y + i * vy), (x + i * vx)) != symb){
			return false;
		}
	}

	return true;
}

bool isWin(Field &field, SYMBGAME symb){
	for(int y = 0; y < field.sizeY; y++){
		for(int x = 0; x < field.sizeX; x++){
			if(getValue(field.map, y, x) == EMPTY){
				continue;
			}

			if(checkLine(field, y, x, 1, 0, field.toWin, symb)){
				return true;
			}
			if(checkLine(field, y, x, 1, 1, field.toWin, symb)){
				return true;
			}
			if(checkLine(field, y, x, 0, 1, field.toWin, symb)){
				return true;
			}
			if(checkLine(field, y, x, 1, -1, field.toWin, symb)){
				return true;
			}
		}
	}

	return false;
}

//ai turn
bool isAiWin(Field &field) {
	for (int y = 0; y < field.sizeY; y++) {
		for (int x = 0; x < field.sizeX; x++) {
			if (isEmpty(field, x, y)) {
				setValue(field.map, y, x, AI);

				if (isWin(field, AI)){
					return true;
				}

				setValue(field.map, y, x, EMPTY);
			}
		}
	}

	return false;
}

bool isHumWin(Field &field) {
	for (int y = 0; y < field.sizeY; y++) {
		for (int x = 0; x < field.sizeX; x++) {
			if (isEmpty(field, x, y)) {
				setValue(field.map, y, x, PLAYER);

				if (isWin(field, PLAYER)) {
					setValue(field.map, y, x, AI);

					return true;
				}

				setValue(field.map, y, x, EMPTY);
			}
		}
	}

	return false;
}

void aiTurn(Field &field) {
	if (isAiWin(field)){
		return;
	}

	if (isHumWin(field)){
		return;
	}

	int x;
	int y;

	do {
		x = dist(mt);
		y = dist(mt);
	} while (!isEmpty(field, x, y));

	setValue(field.map, y, x, AI);
}

bool gameCheck(Field &field, SYMBGAME symb, std::string win) {
	printField(field);

	if (isWin(field, symb)) {
		std::cout << win << std::endl;

		return true;
	}

	if (isDraw(field)) {
		std::cout << "Draw!" << std::endl;

		return true;
	}

	return false;
}

int main(int argc, char** argv){
	// game cycle + new game
	Field field;

	while(true){
		initField(field);
		printField(field);

		while(true){
			playerTurn(field);

			if(gameCheck(field, PLAYER, "Player is win!")){
				break;
			}

			aiTurn(field);
			if(gameCheck(field, AI, "AI is win!")){
				break;
			}
		}

		std::string answer;

		std::cout << "Play again?";
		std::cin >> answer;

		transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

		if (answer.find('y') != 0){
			break;
		}
	}

	system("pause");

	return 0;
}