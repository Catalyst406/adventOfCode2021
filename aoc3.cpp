#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
//I dont wanna talk about this code, i couldnt get it working for part 2, ended up doing in a spreadsheet. 
//if i havnt come back and fixed this code the guilt of the false star doesnt hurt me as much as redoing this day again
using namespace std;

int binaryToDecimal(int binary[])
{   
    cout << "binary to decimal: ";
    int decimal = 0, base = 1;
    for(int i = 11;i>=0;i--) {
        cout << binary[i];
        decimal += binary[i] * base;
        base *= 2;
    }
    cout << "\n";
    return decimal;
}
int decimalToBinary(int n)
{
    int y = 11, temp, out = 0;
    while (n) {
        temp = pow(2, y);
        if (n > temp){
            n -= temp;
            out += pow(10, y);
        }
    }
    return out;
}
void part1() {
    ifstream infile("data.txt");
    string binary;
    int gamma = 0, epsilon = 0, powerConsumption, total = 0;
    int value[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };

    //couts totals
    while (infile >> binary) {
        for (int i = 0; i < 12; i++) {
            if (binary.at(i) == '1') {
                value[i]++;
            }
        }
        total++;
    }
    cout << "\n";

    for (int i = 0; i < 12; i++) {
        value[i] = 2 * value[i] / total;
    }

    gamma = binaryToDecimal(value);

    for (int i = 0; i < 12; i++) {
        if (value[i] == 1) {
            value[i] = 0;
        }
        else {
            value[i] = 1;
        }
    }

    epsilon = binaryToDecimal(value);

    powerConsumption = gamma * epsilon;

    printf("Power Consumption: %d", powerConsumption);
}
int findCommon(vector<string>* inputs, int index,int size) {
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        if (inputs->at(i).at(index) == '1') {
            total++;
        }
    }
    if (size == 0) {
        return(0);
    }
    return ((total*2/size));
}
void part2() {
    ifstream infile("data.txt");
    vector<string> o2genRate;
    vector<string> co2genRate;
    string temp;

    int size;
    while (infile >> temp) {
        o2genRate.push_back(temp);
        co2genRate.push_back(temp);
    }

    for (int j = 0; j < 12;j++) {
        size = o2genRate.size();
        if (size > 1) {
            if (findCommon(&o2genRate, j, size)) {
                temp = "1";
            }
            else {
                temp = "0";
            }

            for (int i = size - 1; i >= 0; i--)
            {
                if (o2genRate.at(i) != temp) {
                    o2genRate.erase(o2genRate.begin() + i);
                }
            }
        }
    }

    for (int j = 0; j < 12; j++) {
        size = co2genRate.size();
        if (size != 1) {
            if (findCommon(&co2genRate, j, size)) {
                temp = "0";
            }
            else {
                temp = "1";
            }

            for (int i = size - 1; i >= 0; i--)
            {
                if (co2genRate.at(i) != temp) {
                    co2genRate.erase(co2genRate.begin() + i);
                }
            }
        }
    }

    cout << co2genRate.at(0) << " " << o2genRate.at(0);
}


int main()
{
    part2();
}
