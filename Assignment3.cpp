#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

// Custom Exceptions
class NegativeDepositException : public std::runtime_error {
public:
    NegativeDepositException() : std::runtime_error("Cannot deposit a negative amount!") {}
};

class OverdrawException : public std::runtime_error {
public:
    OverdrawException() : std::runtime_error("Insufficient funds!") {}
};

class InvalidAccountOperationException : public std::runtime_error {
public:
    InvalidAccountOperationException() : std::runtime_error("Account is closed for transactions!") {}
};

class BankAccount {
private:
    std::string accountNumber;
    double balance;
    bool isActive;

public:
    BankAccount(std::string accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance), isActive(true) {
    }

    void deposit(double amount) {
        if (!isActive) throw InvalidAccountOperationException();
        if (amount < 0) throw NegativeDepositException();
        balance += amount;
    }

    void withdraw(double amount) {
        if (!isActive) throw InvalidAccountOperationException();
        if (amount > balance) throw OverdrawException();
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

    void closeAccount() {
        isActive = false;
    }
};

int main() {
    try {
        std::string accNum = "123456";
        double initialBalance;

        std::cout << "Enter initial balance for account #" << accNum << ": ";
        std::cin >> initialBalance;

        auto account = std::make_unique<BankAccount>(accNum, initialBalance);
        std::cout << "Bank Account Created: #" << accNum << std::endl;

        double depositAmount;
        std::cout << "Enter amount to deposit: ";
        std::cin >> depositAmount;
        account->deposit(depositAmount);
        std::cout << "Deposited $" << depositAmount << " successfully." << std::endl;

        double withdrawAmount;
        std::cout << "Enter amount to withdraw: ";
        std::cin >> withdrawAmount;
        account->withdraw(withdrawAmount);
        std::cout << "Withdrew $" << withdrawAmount << " successfully." << std::endl;

        std::cout << "Current Balance: $" << account->getBalance() << std::endl;

        std::cout << "Attempting to withdraw $600..." << std::endl;
        account->withdraw(600);

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        auto account = std::make_unique<BankAccount>("654321", 500);
        std::cout << "Attempting to deposit -50..." << std::endl;
        account->deposit(-50);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        auto account = std::make_unique<BankAccount>("777777", 300);
        account->closeAccount();
        std::cout << "Attempting to deposit into a closed account..." << std::endl;
        account->deposit(100);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}