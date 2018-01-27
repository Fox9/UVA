//
//  main.cpp
//  Puzzle
//
//  Created by Ellan Esenaliev on 10.11.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//


#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<vector <char> > getField();
void printField(int num, const vector<vector <char> >& v);
void makeMoves(string& s, vector<vector <char> >& v);

int main() {
    int count = 1;
    while (true) {
        vector<vector<char> > v = getField();
        if (v[0][0] == 'Z') {
            return 0;
        }
        if (count != 1) {
            cout << endl;
        }
        string turns;
        getline(cin, turns);
        makeMoves(turns , v);
        while (turns[turns.length()-1] != '0') {
            getline(cin, turns);
            makeMoves(turns , v);
        }
        
        printField(count, v);
        
        ++count;
    }
    return 0;
}

vector<vector <char> > getField() {
    vector<vector <char> > v(5, vector<char>(5,' '));
    string s;
    
    for (int i =0; i < 5; ++i) {
        getline(cin,s);
        for (int j =0; j < s.length(); ++j) {
            v[i][j] = s[j];
        }
    }
    return v;
}


void printField(int num, const vector<vector <char> >& v) {
    if (v[0][0] == '0') {
        cout << "Puzzle #" << num << ":" << endl
        << "This puzzle has no final configuration." << endl;
        
        return;
    }
    cout << "Puzzle #" << num << ":" << endl;
    for (int i =0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << v[i][j];
            if (j !=4) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
}


void makeMoves(string& s, vector<vector <char> >& v) {
    int x, y;
    bool config = true;
    for (int i =0; i < 5; ++i) {
        for (int j =0; j < 5;++j) {
            if (v[i][j] == ' ') {
                x = i;
                y = j;
            }
        }
    }
    for (int i =0; i < s.length();++i) {
        if (s[i] == '0') {
            break;
        }
        if (s[i] == 'A') {
            if (x != 0) {
                swap(v[x][y], v[x-1][y]);
                --x;
            } else {
                config = false;
            }
        } else if (s[i] == 'R') {
            if (y != 4) {
                swap(v[x][y], v[x][y+1]);
                ++y;
            } else {
                config = false;
            }
        } else if (s[i] == 'B') {
            if ( x != 4) {
                swap(v[x][y], v[x+1][y]);
                x++;
            } else {
                config = false;
            }
        } else if (s[i] == 'L') {
            if (y != 0) {
                swap(v[x][y], v[x][y-1]);
                --y;
            } else {
                config = false;
            }
        } else {
            config = false;
        }
    }
    if (!config) {
        v[0][0] = '0';
    }
}

