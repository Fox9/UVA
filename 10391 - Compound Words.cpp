//
//  main.cpp
//  10391 - Compound Words
//
//  Created by Ellan Esenaliev on 07.11.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> line;
    string word;
    
    while (cin >> word) {
        line.push_back(word);
    }
    sort(line.begin(), line.end());
    for(int i = 0; i < line.size(); i++) {
        if(line[i].length() == 1)
            continue;
        for(int j = 0; j < line[i].length(); j++) {
            string firstPart = line[i].substr(0, j);
            string secondPart = line[i].substr(j, line[i].length()-1);
            if((binary_search(line.begin(), line.end(), firstPart)) && (binary_search(line.begin(), line.end(), secondPart))) {
                cout << line[i] << endl;
                break;
            }
            
        }
    }
    
    return 0;
}
