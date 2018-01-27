//
//  main.cpp
//  Oil Deposits
//
//  Created by Ellan Esenaliev on 20.12.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Pixel
{
    int r;
    int c;
    int nb;
    
    Pixel(int aR, int aC, int aNB)
    : r(aR), c(aC), nb(aNB)
    {
    }
};


int main() {
    // insert code here...
    int m;
    int n;
    while(cin >> m >> n) {
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<vector<char>> screen(m+2, vector<char>(n+2, '+'));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> screen[i][j];
            }
        }
        int count = 0;
        for(int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; ++j)
            {
                if(screen[i][j] == '@') {
                    vector<int> dr = {-1, 0, 1, 0, -1, 1, -1, 1};
                    vector<int> dc = {0, 1, 0, -1, -1, 1, 1, -1};
                    
                    stack<Pixel> stack;
                    
                    screen[i][j] = '.';
                    stack.push(Pixel(i, j, 0));
                    while (not stack.empty())
                    {
                        bool found = false;
                        
                        for (int i = stack.top().nb; i < dr.size() and not found; ++i)
                        {
                            int cr = stack.top().r + dr[i];
                            int cc = stack.top().c + dc[i];
                            if (screen[cr][cc] == '@')
                            {
                                found = true;
                                screen[cr][cc] = '.';
                                stack.top().nb = i;
                                stack.push(Pixel(cr, cc, 0));
                            }
                        }
                        if (not found)
                        {
                            stack.pop();
                        }
                    }
                    count++;
                }
            }
        }
        cout << count << endl;
        
    }
    return 0;
}
