//
//  main.cpp
//  Magic square palindromes.
//
//  Created by Ellan Esenaliev on 09.11.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string clear_string(const string& line)
{
    string phrase = "";
    
    for (int i = 0; i < line.size(); ++i)
    {
        if (line[i] >= 'a' && line[i] <= 'z')
            phrase += line[i];
    }
    
    return phrase;
}

int box_size(const string &phrase)
{
    int boxSize = sqrt(phrase.size());
    
    if (boxSize * boxSize != phrase.size())
        return 0;
    
    int end = phrase.size() - 1;
    int goTo = phrase.size() / 2;
    
    for (int i = 0; i <= goTo; i++)
    {
        if (phrase[i] != phrase[end - i])
        {
            return 0;
        }
    }
    
    return boxSize;
}


int main()
{
    string line;
    
    
    int x;
    cin >> x;
    cin.ignore();
    
    for (int i = 1; i <= x; i++)
    {
        getline(cin, line);
        
        string clearString;
        clearString = clear_string(line);
        
        cout << "Case #" << i << ":\n";
        
        int size = box_size(clearString);
        
        if (size)
            cout << size << '\n';
        else
            cout << "No magic :(\n";
    }
}
