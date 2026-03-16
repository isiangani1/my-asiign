#include <iostream>
#include <string>

class BankAccount {
private://wem a var is private it can not be acces outside the classs
    int accountNumber;//unq ac ID
    std::string accountHolder;// unq acc holders name
    double balance;// bal in the AC

public://can be accessed outside the class
    // Constructor
    BankAccount(int accNum, const std::string& holder, double bal)
        : accountNumber(accNum), accountHolder(holder), balance(bal) {}

// member functions
    // Deposit money
    bool deposit(double amount) {
        if (amount <= 0) return false;
        balance += amount;
        return true;
    }

    // Withdraw money
    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) return false;
        balance -= amount;
        return true;
    }

    // Display account details
    void displayAccount() const {
        std::cout << "Account Number: " << accountNumber << "\n"
                  << "Account Holder: " << accountHolder << "\n"
                  << "Balance: " << balance << "\n\n";
    }
};
/// main func

int main() {

    // Create two bank account objects
    BankAccount ac1(101, "John", 5000);
    BankAccount ac2(102, "Mary", 3000);

    // Display initial account details
    ac1.displayAccount();

    // Perform a deposit
    if (ac1.deposit(1000)) {
        std::cout << "Deposit successful\n";
    } else {
        std::cout << "Deposit failed: invalid amount\n";
    }

    // Perform a withdrawal
    if (ac1.withdraw(2000)) {
        std::cout << "Withdrawal successful\n";
    } else {
        std::cout << "Withdrawal failed: insufficient funds or invalid amount\n";
    }

    std::cout << "\n";

    // Display updated account information
    ac1.displayAccount();

    return 0;
}