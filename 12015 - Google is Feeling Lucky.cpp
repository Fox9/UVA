//
//  main.cpp
//  Google is Feeling Lucky
//
//  Created by Ellan Esenaliev on 14.11.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int x;
    
    while(cin >> x) {
        for(int i = 1; i <= x; i++) {
            vector<string> stack;
            int max = 0;
            for(int j = 1; j <= 10; j++) {
                string line; cin >> line;
                int rating; cin >> rating;
                
                if (max < rating) {
                    max = rating;
                    stack.clear();
                    stack.push_back(line);
                } else if (max == rating) {
                    stack.push_back(line);
                }
            }
            
            cout << "Case #" << i << ":" << endl;
            for(string site: stack) {
                cout << site << endl;
            }
        }
    }
    return 0;
}
