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
    int x; cin >> x;
    for(int j = 0; j < x; j++) {
        int n; cin >> n;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            int b; cin >> b;
            int c; cin >> c;
            ans += a*c;
        }
        cout << ans << endl;
    }
    return 0;
}
