#include <iostream>
#include <fstream>

//needs to be optimized, theres something going wrong wiht interger overflow in the last part, but i wasnt able to figure it out

using namespace std;

int main()
{
    ifstream fishList("data.txt");
    //ifstream fishList("test.txt");
    unsigned long long int ageCount[9] = { 0 };
    unsigned long long int temp;
    unsigned long long int oldTemp = 0;
    int DaysOfBreeding = 256;

    while (fishList >> temp) {
        ageCount[temp] = ageCount[temp]+1;
    }

    for (int i = 1; i < DaysOfBreeding; i++) {
        cout << "\nDay: " << i <<"\n";
        
        temp = ageCount[0];
        for (int j = 0; j < 8; j++) {
            ageCount[j] = ageCount[j + 1];
        }
        ageCount[8] = temp;
        ageCount[6] = ageCount[6] + temp;

        for (int j = 0; j < 9; j++) {
            cout << "Number of age " << j << " = " << ageCount[j] << "\n";
        }
        temp = 0;
        for (int i : ageCount) {
            temp = temp+i;
        }
        cout << "Total Fish = " << temp << "\n";
        if (oldTemp > temp && oldTemp !=0) {
            cout << "Total Overflowed\n";
        }
        oldTemp = temp;
    }
}
