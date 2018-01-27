//
//  main.cpp
//  Correct Move
//
//  Created by Ellan Esenaliev on 10.11.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>

using namespace std;

bool isIllegalState(int &king, int &queen);
bool isIllegalMove(int &king, int &queen, int &queenTo);
bool isMoveNotAllowed(int &king, int &queen, int &queenTo);
bool isStop(int &king, int &queen, int &queenTo);

int main() {
    int king, queen, queenTo;
    
    while (cin >> king >> queen >> queenTo) {
        if (isIllegalState(king, queen)) {
            cout << "Illegal state" << endl;
        } else if (isIllegalMove(king, queen, queenTo)) {
            cout << "Illegal move" << endl;
        } else if (isMoveNotAllowed(king, queen, queenTo)) {
            cout << "Move not allowed" << endl;
        } else if (isStop(king, queen, queenTo)) {
            cout << "Stop" << endl;
        } else {
            cout << "Continue" << endl;
        }
    }
}

bool isIllegalState(int &king, int &queen) {
    return king == queen;
}

bool isIllegalMove(int &king, int &queen, int &queenTo) {
    bool first_check = ((queenTo - queen) % 8 != 0 && queenTo / 8 != queen / 8) || queen == queenTo;
    bool second_check = ((king - queen) % 8 == 0 && (king - queenTo) % 8 == 0) || (king / 8 == queen / 8 && king  / 8 == queenTo / 8);
    bool third_check = king <= max(queen, queenTo) && king >= min(queen, queenTo);
    return first_check || (second_check && third_check);
}

bool isMoveNotAllowed(int &king, int &queen, int &queenTo) {
    int diff;
    diff = max(king, queenTo) - min(king, queenTo);
    return diff == 8 || (diff == 1 && king / 8 == queenTo / 8);
}

bool isStop(int &king, int &queen, int &queenTo) {
    return (king == 0 && queenTo == 9) || (king == 7 && queenTo == 14) || (king == 56 && queenTo == 49) || (king == 63 && queenTo == 54);
}
