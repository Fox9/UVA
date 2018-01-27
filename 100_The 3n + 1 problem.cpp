//
//  main.cpp
//  100-The 3n+1
//
//  Created by Ellan Esenaliev on 06.10.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    // insert code here...
    int a, b;
    while (cin >> a >> b) {
        int x = a;
        int y = b;
        if (x > y) {
            swap(x, y);
        }
        int r = 0;
        for(int i = x; i <= y; i++) {
            int t = i;
            int c = 1;
            while(t != 1) {
                c++;
                
                if(t % 2 == 0) {
                    t = t / 2;
                } else {
                    t = 3 * t + 1;
                }
                
            }
            r = max(r, c);
        }
        cout << a << ' ' << b << ' ' << r << "\n";
     
        
    }
    return 0;
}
