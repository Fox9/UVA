//
//  main.cpp
//  TEX Quotes
//
//  Created by Ellan Esenaliev on 06.10.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    // insert code here...
    bool inQuate = false;
    char ch;
    while(cin.get(ch)) {
        if (ch == '\"' and not inQuate) {
            cout.put('`');
            cout.put('`');
            inQuate = true;
        } else if (ch == '\"' and inQuate) {
            cout.put('\'');
            cout.put('\'');
            inQuate = false;
        } else {
            cout.put(ch);
        }
    }
    return 0;
}
