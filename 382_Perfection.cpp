//
//  main.cpp
//  Perfection
//
//  Created by Ellan Esenaliev on 06.10.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n;
    cout << "PERFECTION OUTPUT"<< endl;
    while(cin >> n) {
        if (n == 0) {
            cout << "END OF OUTPUT"<< endl;
            return 0;
        }
        int del = 0;
        for(int i = 1; i < n; i++) {
            if ((n % i) == 0) {
                del += i;
            }
        }
        if (del > n) {
            cout << right << setw(5) << n << "  ABUNDANT" << endl;
        } else if (del < n){
            cout<< right << setw(5) << n << "  DEFICIENT" << endl;
        } else {
            cout<< right << setw(5) << n << "  PERFECT" << endl;
        }
    }
    return 0;
}
