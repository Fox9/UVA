//
//  main.cpp
//  Decode the Mad man
//
//  Created by Ellan Esenaliev on 06.11.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    string line;
    while(getline(cin, line)) {
        string keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
        locale loc;
        for(int i = 0; i < line.length(); i++) {
            if(line[i] == ' ')
                cout << " ";
            else {
                for(int j = 0; j < keyboard.length(); j++) {
                    line[i] = tolower(line[i], loc);
                    if (keyboard[j] == line[i]) {
                        cout << keyboard[j-2];
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}
