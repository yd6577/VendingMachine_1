#include <iostream>
#include "VendingMachine.h"
#include "Payment.h"

using namespace std;

int main() {
    VendingMachine vendingMachine;
    vendingMachine.displayBeverages();

    int choice;
    cout << "Enter your selection: ";
    cin >> choice;

    vendingMachine.selectBeverage(choice - 1);

    int coin;
    while (vendingMachine.getAmountEntered() < vendingMachine.getSelectedBeverage().getPrice()) {
        cout << "Please insert coins (1 = $0.01, 2 = $0.10, 3 = $0.25): ";
        cin >> coin;
        vendingMachine.insertCoin(coin);
    }

    vendingMachine.withdrawBeverage();

    cout << "Thank you for your purchase! Enjoy your " << vendingMachine.getSelectedBeverage().getItemName() << endl;

    return 0;
}
