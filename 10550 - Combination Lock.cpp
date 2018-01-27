//
//  main.cpp
//  test
//
//  Created by Ellan Esenaliev on 21.10.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int startNumber;
    int firstLock;
    int secondLock;
    int thirdLock;
    while(cin >> startNumber >> firstLock >> secondLock >> thirdLock) {
        if(startNumber == 0 && firstLock== 0 && secondLock == 0 && thirdLock == 0 ) {
            return 0;
        }
        int answer = 1080;
        answer += (startNumber - firstLock) > 0 ? (startNumber - firstLock) * 9 : (startNumber - firstLock) * 9 + 360;
        answer += (secondLock - firstLock) > 0 ? (secondLock - firstLock) * 9 : (secondLock - firstLock + 40) * 9;
        answer += (secondLock - thirdLock) > 0 ? (secondLock - thirdLock) * 9 : (secondLock - thirdLock + 40) * 9;
        cout << answer << endl;
    }
    return 0;
}

