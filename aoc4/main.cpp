#include <iostream>
#include <fstream>
#include "BingoBoard.h"
#include <vector>

using namespace std;

int main()
{
    //ifstream inBoards("testData.txt");
    ifstream inBoards("boards.txt");
    vector<BingoBoard> loadedBoards;
    int temp[25];
    int x = 0;

    while (!inBoards.eof()) {
        BingoBoard TempObject;
        for (int i = 0; i < 25; i++) {
            inBoards >> temp[i];
        }
        TempObject.addBoard(temp);
        loadedBoards.push_back(TempObject);
    }

    //ifstream inCalls("testCalls.txt");
    ifstream inCalls("calls.txt");
    bool hasWon[100];
    for (int x = 0; x < loadedBoards.size(); x++) {
        hasWon[x] = false;
    }
    while (inCalls>>x){
        for (int i = 0; i < loadedBoards.size(); i++) {
            loadedBoards.at(i).markNumber(x);
            if (loadedBoards.at(i).checkBingo() && !hasWon[i]) {
                cout << loadedBoards.at(i).score(x) << "<< is the answer\n";
                hasWon[i] = true;
            }
        }
    }
}