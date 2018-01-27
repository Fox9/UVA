//
//  main.cpp
//  test
//
//  Created by Ellan Esenaliev on 21.10.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main() {
    //PRESENTATION ERROR, PLS CONTACT ME IF YOU CAN DO THIS ISSUE WITHOUT FUCKING "PRESENTATION ERROR"
    int n; cin >> n;
    cout << endl;
    for(int i = 0; i < n; i++) {
        string result = "yes";
        int numberOfColumns; cin >> numberOfColumns;
        int firstY; cin >> firstY;
        int secondY; cin >> secondY;
        int varForCheck = firstY - secondY;
        for(int j = 0; j < numberOfColumns - 1; j++) {
            int y1; cin >> y1;
            int y2; cin >> y2;
            if (y1 - y2 != varForCheck) {
                result = "no";
            }
        }
        cout << result << endl;
    }
    return 0;
}

