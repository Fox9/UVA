//
//  main.cpp
//  Error Correction
//
//  Created by Ellan Esenaliev on 06.11.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int main() {
    
    int sizeOfMatrix;
    while(cin >> sizeOfMatrix) {
        if(sizeOfMatrix == 0) {
            return 0;
        }
        vector<vector<int>> myVector;
        myVector.resize(sizeOfMatrix, vector<int>(sizeOfMatrix));
        
        int checkRow = 0;
        int row = 0;
        int column = 0;
        
        for(int i = 0; i < sizeOfMatrix; i++) {
            int count = 0;
            for(int j = 0; j < sizeOfMatrix; j++) {
                int x; cin >> x;
                myVector[i][j] = x;
                count += x;
            }
            if (count % 2 != 0) {
                checkRow += 1;
                row = i;
            }
        }
        if (checkRow <= 1) {
            int checkColumn = 0;
            for(int i = 0; i < sizeOfMatrix; i++) {
                int count = 0;
                for(int j = 0; j < sizeOfMatrix; j++) {
                    count += myVector[j][i];
                }
                if (count % 2 != 0) {
                    checkColumn++;
                    column = i;
                }
            }
            
            if (checkColumn == 1 && checkRow == 1) {
                cout << "Change bit (" << row+1 << "," << column+1 << ")" << endl;
            } else if (checkColumn == 0 && checkRow == 0){
                cout << "OK" << endl;
            } else {
                cout << "Corrupt" << endl;
            }
            
        } else {
            cout << "Corrupt" << endl;
        }
    }
    return 0;
}
