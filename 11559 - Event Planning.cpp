#include <iostream>
using namespace std;

int main() {
    int countPeople;
    int countMoney;
    int hotelCount;
    int weekendCount;
    while(cin >> countPeople >> countMoney >> hotelCount >> weekendCount) {
        int minCost = 0;
        for(int i = 0; i < hotelCount; i++) {
            int amount; cin >> amount;
            bool isAvailable = false;
            for(int j = 0; j < weekendCount; j++) {
                int count; cin >> count;
                if (count > countPeople) {
                    isAvailable = true;
                }
            }
            if (isAvailable && (amount*countPeople <= countMoney)) {
                if (minCost == 0) {
                    minCost = amount*countPeople;
                } else if(minCost > (amount*countPeople)) {
                    minCost = amount*countPeople;
                }
            }
        }
        if (minCost == 0) {
            cout << "stay home" << endl;
        } else {
            cout << minCost << endl;
        }
    }
    return 0;
}
