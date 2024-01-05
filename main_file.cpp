#include <iostream>
#include <vector>
#include <algorithm>

// Define a basic Account structure
struct Account {
    int accountNumber;
    std::string name;
    double balance;

    // Constructor to initialize account details
    Account(int accNum, std::string accName, double bal) : accountNumber(accNum), name(std::move(accName)), balance(bal) {}
};

// Function to display account details
void showAccountDetails(const std::vector<Account>& accounts, int accNumber) {
    auto it = std::find_if(accounts.begin(), accounts.end(), [accNumber](const Account& acc) {
        return acc.accountNumber == accNumber;
    });

    if (it != accounts.end()) {
        std::cout << "Account Number: " << it->accountNumber << "\n";
        std::cout << "Name: " << it->name << "\n";
        std::cout << "Balance: " << it->balance << "\n";
    } else {
        std::cout << "Account not found!\n";
    }
}

// Function to deposit into an account
void deposit(std::vector<Account>& accounts, int accNumber, double amount) {
    auto it = std::find_if(accounts.begin(), accounts.end(), [accNumber](const Account& acc) {
        return acc.accountNumber == accNumber;
    });

    if (it != accounts.end()) {
        it->balance += amount;
        std::cout << "Amount deposited. Updated balance: " << it->balance << "\n";
    } else {
        std::cout << "Account not found!\n";
    }
}

// Function to withdraw from an account
void withdraw(std::vector<Account>& accounts, int accNumber, double amount) {
    auto it = std::find_if(accounts.begin(), accounts.end(), [accNumber](const Account& acc) {
        return acc.accountNumber == accNumber;
    });

    if (it != accounts.end()) {
        if (it->balance >= amount) {
            it->balance -= amount;
            std::cout << "Amount withdrawn. Updated balance: " << it->balance << "\n";
        } else {
            std::cout << "Insufficient balance!\n";
        }
    } else {
        std::cout << "Account not found!\n";
    }
}

int main() {
    std::vector<Account> accounts;

    // Sample accounts
    accounts.emplace_back(1001, "Alice", 5000.0);
    accounts.emplace_back(1002, "Bob", 3000.0);
    accounts.emplace_back(1003, "Charlie", 7000.0);

    // Example usage
    showAccountDetails(accounts, 1002); // Show details of account number 1002
    deposit(accounts, 1001, 2000.0);  // Deposit 2000 into account number 1001
    withdraw(accounts, 1003, 8000.0); // Attempt to withdraw 8000 from account number 1003

    return 0;
}
