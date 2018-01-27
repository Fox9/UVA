//
//  main.cpp
//  Secret Research
//
//  Created by Ellan Esenaliev on 17.10.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main() {
    // insert code here...
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string x; cin >> x;
        if (x.length() <= 2) {
            if (x[0] == '1' || x[0] == '4' || (x[0]== '7' && x[1] == '8')) {
                cout << "+"<< endl;
            }
        } else {
            if (x[x.length()-2] == '3' && x[x.length()-1] == '5') {
                cout << "-" << endl;
            } else if (x[0] == '9' && x[x.length()-1] == '4') {
                cout << "*" << endl;
            } else if (x[0] == '1' && x[1] == '9' && x[2] == '0') {
                cout << "?" << endl;
            }
        }
    }
    return 0;
}
