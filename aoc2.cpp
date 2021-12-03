// aoc2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile("data.txt");
    int x=0,horizontal=0,verticle=0, aim=0;
    string direction;

    while (infile >> direction>>x) {
        cout << direction;
        if (direction == "up") {
            aim -= x;
        }
        else if (direction == "down") {
            aim += x;
        }
        else if (direction == "forward") {
            horizontal += x;
            verticle += aim * x;
        }
    }

    printf("horizontal: %d, verticle: %d, total: %d", horizontal, verticle, horizontal * verticle);
}

