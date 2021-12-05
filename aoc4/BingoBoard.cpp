#include "BingoBoard.h"

void BingoBoard::addBoard(int* input)
{
	for (int i = 0; i < 25; i++) {
		values[i] = input[i];
	}
}

//could be optimized to do the is bingo check to
void BingoBoard::markNumber(int check)
{
	for (int i = 0; i < 25; i++) {
		if (values[i] == check) {
			hits[i] = 1;
			return;
		}
	}
	

}

bool BingoBoard::checkBingo()
{
	bool bingo = false;
	for (int i = 0; i < 5 && !bingo; i++) {
		if (hits[i] + hits[5 + i] + hits[10 + i] + hits[15 + i] + hits[20 + i] == 5) {
			bingo = true;
		}
		if(hits[5*i+0] + hits[5 * i + 1] + hits[5 * i + 2] + hits[5 * i + 3] + hits[5 * i + 4] == 5) {
			bingo = true;
		}
	}
	return bingo;
}

int BingoBoard::score(int lastCall)
{
	int sumOfCells = 0;
	for (int i = 0; i < 25; i++) {
		if (hits[i] == 0) {
			sumOfCells += values[i];
		}
	}
	return lastCall*sumOfCells;
}

BingoBoard::BingoBoard()
{
}
