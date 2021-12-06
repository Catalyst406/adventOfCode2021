#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    ifstream ventsList("cleanData.txt");
    int hydrothermalVentMap[1000][1000] = { 0 };
    int x1, x2, y1, y2, flexTemp = 0, totalUnsafe = 0;
    while (!ventsList.eof()) {
        ventsList >> x1;
        ventsList >> y1;
        ventsList >> x2;
        ventsList >> y2;
        cout << x1 << " " << y1 << " " << x2 << " " << y2;
        if (x1 != x2 && y1 != y2) {
            int horizontal = 0, verticle = 0;
            if (x1 > x2) {
                horizontal = -1;
            }
            else {
                horizontal = 1;
            }

            if (y1 > y2) {
                verticle = -1;
            }
            else {
                verticle = 1;
            }

            for (int i = 0; i <= max(y1, y2) - min(y1, y2); i++) {
                hydrothermalVentMap[x1 + i * horizontal][y1 + i * verticle]++;
            }
        }
        else if (x1 == x2) {
            flexTemp = min(y1, y2);
            cout << " >> horizontal";
            for (int i = 0; i <= max(y1, y2) - flexTemp; i++) {
                hydrothermalVentMap[x1][flexTemp + i]++;
            }
        }
        else {
            flexTemp = min(x1, x2);
            cout << " >> verticle";
            for (int i = 0; i <= max(x1, x2) - flexTemp; i++) {
                hydrothermalVentMap[flexTemp + i][y1]++;
            }
        }
        cout << "\n";
    }

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (hydrothermalVentMap[i][j] > 1) {
                totalUnsafe++;
            }
        }
    }
    cout << totalUnsafe << " << output ";
    return(1);
}