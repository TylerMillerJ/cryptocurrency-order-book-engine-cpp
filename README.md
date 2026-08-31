# C++ Crypto Trading System
## Description
The program simulates the experience of buying and selling cryptocurrencies from the command line using a text-based interface and a dataset representing the order book of a real currency exchange platform. 

The goal of this project is to apply Object-Oriented Programming (OOP) concepts in C++ while learning how cryptocurrency trading systems work, including the structure of exchange order books, order submission and matching, and basic currency trading operations.

## Implementation Details
The program is initialized through the MerkelMain class, which creates a Wallet with predefined starting balances for USDT, BTC, LTC, ETH, DOGE, and SOL. The wallet validates that only supported currencies can be used for bids, asks, and deposits. Users can submit orders and make deposits through the program, with input and currency validation performed before transactions are accepted.

## Usage
On startup, the program initializes the user's wallet with the default balances. The user can then make deposits and submit bids or asks using the supported currencies. After submitting orders, the user must select the option to continue forward in time so that the order book advances to the next timestamp and performs order matching. Orders are only matched when the order book is advanced forward in time.

Build the program using:

make

Then run the program interactively with:

./OrderBookEngine

Alternatively, run the program using the test script:

./OrderBookEngine < testfile.txt

## Testing
The project includes testfile.txt, which provides automated input to test the main functionality and input validation of the program. The test script verifies wallet initialization, valid deposits, bid and ask submissions, advancing the order book through time, and order matching. It also tests invalid input including unsupported currencies, invalid or negative prices and amounts, missing or extra arguments, and non-numeric values.

### Credits

This crypto trading system coded is a C++ is built as a guided project on coursera created by Professor Matthew Yee-King of University Of London's Object Oriented Programming Specialization 


