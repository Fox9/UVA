//
//  main.cpp
//  Palindromes
//
//  Created by Ellan Esenaliev on 14.11.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
    
    string s1="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    string s2="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    
    map<char,char> Letters;
    
    for(int i = 0; i < s1.size(); i++) {
        Letters[s1[i]] = s2[i];
    }
    
    string line;
    while(cin >> line){
        
        bool palindrome = true;
        bool mirrored = true;
        
        int len = int(line.length());
        for(int i = 0; i <= len/2; i++){
            
            if(line[i] != line[len-i-1]) {
                palindrome = false;
            }
            
            if(line[len-i-1]!= Letters[line[i]]) {
                mirrored = false;
            }
        }
        
        if(palindrome && mirrored)
            cout << line <<" -- is a mirrored palindrome." << endl;
        else if(palindrome && !mirrored)
            cout << line << " -- is a regular palindrome." << endl;
        else if(!palindrome && mirrored)
            cout << line << " -- is a mirrored string." << endl;
        else
            cout << line << " -- is not a palindrome." << endl;
        cout << endl;
    }
    
    return 0;
}
