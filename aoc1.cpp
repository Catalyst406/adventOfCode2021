
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// https://adventofcode.com/2021/day/1

int main()
{   
    //Opens file that has the data
    ifstream infile("data.txt");

    //variables to use
    vector<int> input;
    int temp, numBigger=0;
    
    //reads contents of file into vector
    while (infile >> temp) {
        input.push_back(temp);
    }

    //does the math thing
    for (int i = 3; i < input.size(); i++) {
        if (input.at(i) > input.at(i - 3)) {
            numBigger++;
        }
    }

    //gives the answer
    printf("The answer is:%d", numBigger);    
}

