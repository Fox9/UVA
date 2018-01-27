//
//  main.cpp
//  Automatic Poetry
//
//  Created by Ellan Esenaliev on 06.11.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int x; cin >> x;
    
    string firstLine;
    string secondLine;
    getline(cin, firstLine);
    string finalStr;
    for(int i = 0; i < x; i++) {
        
        bool inBreakets = false;
        getline(cin, firstLine);
        getline(cin, secondLine);
        
        vector<string> stringsInBreakets;
        vector<string> stringsOutOfBreakets;
        
        string tempStringInBreakets;
        string tempStringOutOfBreakets;
        for(char ch: firstLine){
            if(ch == '<') {
                inBreakets = true;
                stringsOutOfBreakets.push_back(tempStringOutOfBreakets);
                tempStringOutOfBreakets = "";
            } else if (ch == '>') {
                inBreakets = false;
                stringsInBreakets.push_back(tempStringInBreakets);
                tempStringInBreakets = "";
            } else {
                finalStr += ch;
            }
            if (inBreakets) {
                if(ch != '<' && ch != '>')
                    tempStringInBreakets += ch;
            } else {
                if(ch != '<' && ch != '>')
                    tempStringOutOfBreakets += ch;
            }
        }
        stringsOutOfBreakets.push_back(tempStringOutOfBreakets);
        finalStr += "\n";
        for(char ch: secondLine) {
            if (ch == '.') {
                finalStr += stringsInBreakets.back();
                stringsInBreakets.pop_back();
                finalStr += stringsOutOfBreakets[1];
                finalStr += stringsInBreakets.back();
                stringsInBreakets.pop_back();
                finalStr += stringsOutOfBreakets[2];
                break;
            }
            finalStr += ch;
        }
        finalStr += "\n";
//        cout << alltext << endl;
    }
    cout << finalStr;
    
    return 0;
}
