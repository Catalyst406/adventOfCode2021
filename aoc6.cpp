#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <Bits.h>

using namespace std;

int main()
{
    ifstream crabmarines("data.txt");
    vector<int> positions, gas;
    int max=0, min=9999, temp;

    while (crabmarines >> temp) {
        if (temp > max) {
            max = temp;
        }
        if (temp < min) {
            min = temp;
        }
        positions.push_back(temp);
    }
    
    int start = min;
    int yetAnotherTemp = 0;
    for (int i = start; i < max; i++) {
        temp = 0;
        for (int j = 0; j < positions.size(); j++) {
            yetAnotherTemp = abs(positions.at(j) - i);
            temp += yetAnotherTemp * (yetAnotherTemp + 1) / 2;
        }
        if (min > temp && i != start) {
            min = temp;
        }
        else if(i == start){
            min = temp;
        }
        gas.push_back(temp);
    }

    cout << min;
}