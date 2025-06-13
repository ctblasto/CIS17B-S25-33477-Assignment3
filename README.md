# CIS17B-S25-33477-Assignment3

# Bank Account Management System

## Overview
This C++ project is a simple **Bank Account Management System** created for CIS17B coursework. It demonstrates class design, smart pointer usage, exception handling, and basic user interaction.

### Features
- Create a bank account with an initial balance
- Deposit funds (with validation)
- Withdraw funds (with balance checks)
- Close the account and prevent further transactions
- Exception handling for:
  - Negative deposits
  - Overdrawing
  - Operations on closed accounts

### Technologies
- Language: C++
- Memory Management: `std::unique_ptr`
- Error Handling: Custom exception classes

## How to Compile

Use any modern C++ compiler with C++17 support:

```bash
g++ -std=c++17 Assignment3.cpp -o BankApp
```

## How to Run

```bash
./BankApp
```

## Sample Output

```
Enter initial balance for account #123456: 1000
Bank Account Created: #123456
Enter amount to deposit: 1000
Deposited $1000 successfully.
Enter amount to withdraw: 500
Withdrew $500 successfully.
Current Balance: $1500
Attempting to withdraw $600...
Error: Insufficient funds!
Attempting to deposit -50...
Error: Cannot deposit a negative amount!
Attempting to deposit into a closed account...
Error: Account is closed for transactions!
```

## Author
CIS 17B Student – Spring 2025
