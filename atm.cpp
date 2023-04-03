#include <iostream>
#include <map>
using namespace std;

map<string, int> accounts = {
    {"1234", 5000},
    {"1478", 10000},
    {"9632", 7500},
    
};

void display_menu() {
    cout<<endl;
    cout << "      * * * *Welcome to the ATM* * * *" << endl;
    cout << "      ********************************" << endl;
    cout << "                  MENU              " << endl;
    cout << "      ********************************" << endl;
    cout << "            1. Check balance" << endl;
    cout << "            2. Withdraw cash" << endl;
    cout << "            3. Deposit cash" << endl;
    cout << "            4. Exit" << endl;
    cout << "      ********************************" << endl;
    cout<<endl;
}

void check_balance(string name) {
    int balance = accounts[name];
    cout << "Your balance is: $" << balance << endl;
    cout<<endl;
}

void withdraw_cash(string name, int amount) {
    
    if (amount > accounts[name]) {
        cout << "Insufficient funds" << endl;
    } else {
        accounts[name] -= amount;
        cout << "Withdrawal successful. Your new balance is $" << accounts[name] << endl;
    }
    cout<<endl;
}

void deposit_cash(string name, int amount) {
    accounts[name] += amount;
    cout << "Deposit successful. Your new balance is $" << accounts[name] << endl;
    cout<<endl;
}

int main() {
    while (true) {
        display_menu();

        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "Enter your Secret PIN : ";
            cin >> name;
            if(name.length()!= 4) cout<<"      ***********INVALID PIN***********"<<endl<<endl;
            else check_balance(name);
        } else if (choice == 2) {
            string name;
            int amount;
            cout << "Enter your Secret PIN : ";
            cin >> name;
            if(name.length()!= 4) cout<<      "***********INVALID PIN***********"<<endl<<endl;
            else{
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            withdraw_cash(name, amount);
            }
        } else if (choice == 3) {
            string name;
            int amount;
            cout << "Enter your Secret PIN : ";
            cin >> name;
            if(name.length()!= 4) cout<<"      ***********INVALID PIN***********"<<endl<<endl;
            else{
            cout << "Enter amount to deposit: ";
            cin >> amount;
            deposit_cash(name, amount);
            }
        } else if (choice == 4) {
            cout << "      * * * *Thank you for using the ATM!* * * *      " << endl;
            break;
        } else {
            cout << " * * * *Invalid choice. Please try again.* * * *      " << endl;
        }
    }
    return 0;
}
