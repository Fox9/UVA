//
//  main.cpp
//  Loansome Car Buyer
//
//  Created by Ellan Esenaliev on 06.11.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int loanDur, nRec;
    double downPayment, loan;
    while(cin >> loanDur >> downPayment >> loan >> nRec) {
        if (loanDur < 0) {
            break;
        }
        
        int month;
        double percent;
        vector<double> decP;
        decP.resize(100);
        for(int i = 0; i < nRec; i++) {
            cin >> month >> percent;
            for(int j = month; j < 100; j++) {
                decP[j] = percent;
            }
        }
        
        
        int now = 0;
        double monthlyPayment = loan / loanDur;
        double curVal = (loan + downPayment) * (1 - decP[0]);
        while (curVal < loan) {
            now++;
            loan -= monthlyPayment;
            curVal = curVal * (1-decP[now]);
        }
        
        cout << now << " month";
        if (now != 1)
            cout << "s";
        cout << endl;
        
    }
    
    return 0;
}
