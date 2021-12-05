#pragma once
#include <iostream>
class BingoBoard
{
public:
	int values[25] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int hits[25] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	void addBoard(int*);

	void markNumber(int);

	bool checkBingo();

	int score(int);

	BingoBoard();

};

