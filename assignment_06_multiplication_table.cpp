// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

void printTable(int number) {
    cout << "Multiplication Table for " << number << ":\n";

    for (int multiplier = 1; multiplier <= 12; ++multiplier) {
        cout << setw(2) << number << "  x "
             << setw(2) << multiplier << "  = "
             << setw(3) << number * multiplier << '\n';
    }
}

void partA() {
    int number;

    cout << "Enter a positive integer for Part A: ";
    if (!(cin >> number) || number <= 0) {
        cout << "Error: please enter a positive integer.\n";
        return;
    }

    printTable(number);
}

void partB() {
    int limit;

    cout << "\nEnter a positive integer N for Part B: ";
    if (!(cin >> limit) || limit <= 0) {
        cout << "Error: please enter a positive integer.\n";
        return;
    }

    for (int number = 1; number <= limit; ++number) {
        printTable(number);

        if (number < limit) {
            cout << "---------------------------\n";
        }
    }
}

int main() {
    partA();
    partB();

    return 0;
}

