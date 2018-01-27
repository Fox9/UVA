//
//  main.cpp
//  Counting Stars
//
//  Created by Ellan Esenaliev on 20.12.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x;
    int y;
    while (cin >> x >> y) {
        if(x == 0 || y == 0) {
            return 0;
        }
        vector<vector<char>> screen(x+2, vector<char>(y+2, '+'));
        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                cin >> screen[i][j];
            }
        }
        int count = 0;
        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                if (screen[i][j] == '*') {
                    bool check = true;
                    vector<int> dr = {-1, 0, 1, 0, -1, 1, -1, 1};
                    vector<int> dc = {0, 1, 0, -1, -1, 1, 1, -1};
                    for (int k = 0; k < dr.size(); ++k) {
                        int cr = i + dr[k];
                        int cc = j + dc[k];
                        if (screen[cr][cc] == '*') {
                            check = false;
                        }
                    }
                    if (check) {
                        count++;
                    }
                }
                
            }
        }
        cout << count << endl;
    }
    
    return 0;
}
