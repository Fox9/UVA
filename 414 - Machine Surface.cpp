//
//  main.cpp
//  Machine Surface
//
//  Created by Ellan Esenaliev on 07.11.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x;
    while(cin >> x) {
        if(x == 0)
            break;
        int maxElementX = 0;
        vector<int> counts;
        string line;
        getline(cin,line);
        for(int i = 0; i < x; i++) {
            getline(cin,line);
            int xSymbolCount = 0;
            for(char symbol: line) {
                if (symbol == 'X')
                    xSymbolCount++;
            }
            maxElementX = max(maxElementX, xSymbolCount);
            counts.push_back(xSymbolCount);
        }
        int result = 0;
        for(int i: counts) {
            result += maxElementX - i;
        }
        cout << result << endl;
    }
    return 0;
}

