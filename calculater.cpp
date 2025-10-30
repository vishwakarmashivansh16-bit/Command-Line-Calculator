/*
------------------------------------------------------------
|   Project Title : C++ Command-Line Calculator             |
|   Author        : Shivansh Vishwakarma                    |
|   Language      : C++                                     |
|   Date Created  : October 2025                            |
|   Version       : 1.1                                     |
|-----------------------------------------------------------|
|   Description:                                            |
|   This program is a simple C++ calculator that performs   |
|   multiple mathematical operations such as Addition,      |
|   Subtraction, Multiplication, Division, Remainder,       |
|   Percentage, Power, Square Root, and Factorial.          |
|                                                           |
|   Features:                                               |
|   ➤ Uses do-while loop for repeated use                  |
|   ➤ Case 10 added for program exit                       |
|   ➤ Uses switch-case for selecting operations            |
|   ➤ Includes input validation for safe execution         |
|   ➤ Beginner-friendly and well-commented code            |
------------------------------------------------------------
*/

#include <bits/stdc++.h>   // Includes all standard libraries (useful for competitive coding)
#include <cmath>           // For mathematical operations like pow() and sqrt()
using namespace std;

int main() {
    int value; // Operation choice

    // Repeat calculator operations until user chooses to exit
    do {
        cout << "\n--------------------------------------------------\n";
        cout << "🔢  C++ COMMAND-LINE CALCULATOR  🔢" << endl;
        cout << "--------------------------------------------------\n";

        // Step 1: Display available operations
        cout << "\nSelect the operation you want to perform:" << endl;
        cout << "1. SUM" << endl;
        cout << "2. SUBTRACTION" << endl;
        cout << "3. MULTIPLICATION" << endl;
        cout << "4. DIVISION" << endl;
        cout << "5. REMAINDER" << endl;
        cout << "6. PERCENTAGE" << endl;
        cout << "7. POWER" << endl;
        cout << "8. SQUARE ROOT" << endl;
        cout << "9. FACTORIAL" << endl;
        cout << "10. EXIT" << endl;

        // Step 2: User chooses operation
        cout << "\nEnter your choice (1–10): ";
        cin >> value;

        // If user chooses to exit early
        if (value == 10) {
            cout << "\nThank you for using the calculator! 👋" << endl;
            break;
        }

        // Step 3: Take number of inputs
        int n;
        cout << "\nEnter how many numbers you want to use: ";
        cin >> n;

        vector<double> array(n);
        cout << "Enter the value(s): " << endl;
        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }

        // Step 4: Perform operation using switch-case
        switch (value) {

            // -------------------- CASE 1: SUM --------------------
            case 1: {
                double sum = 0;
                for (double num : array)
                    sum += num;
                cout << "Sum = " << sum << endl;
                break;
            }

            // -------------------- CASE 2: SUBTRACTION --------------------
            case 2: {
                double sub = array[0];
                for (int i = 1; i < n; i++)
                    sub -= array[i];
                cout << "Subtraction = " << sub << endl;
                break;
            }

            // -------------------- CASE 3: MULTIPLICATION --------------------
            case 3: {
                double mul = 1;
                for (double num : array)
                    mul *= num;
                cout << "Multiplication = " << mul << endl;
                break;
            }

            // -------------------- CASE 4: DIVISION --------------------
            case 4: {
                double division = array[0];
                bool valid = true;
                for (int i = 1; i < n; i++) {
                    if (array[i] == 0) {
                        cout << "Error: Division by zero is not possible!" << endl;
                        valid = false;
                        break;
                    }
                    division /= array[i];
                }
                if (valid) cout << "Division = " << division << endl;
                break;
            }

            // -------------------- CASE 5: REMAINDER --------------------
            case 5: {
                if (n < 2) {
                    cout << "Error: Remainder requires two values!" << endl;
                    break;
                }
                int a = array[0], b = array[1];
                if (b != 0)
                    cout << "Remainder = " << a % b << endl;
                else
                    cout << "Error: Division by zero is not possible for remainder!" << endl;
                break;
            }

            // -------------------- CASE 6: PERCENTAGE --------------------
            case 6: {
                double total = 0;
                for (double num : array)
                    total += num;
                double percentage = total / n;
                cout << "Percentage (average) = " << percentage << "%" << endl;
                break;
            }

            // -------------------- CASE 7: POWER --------------------
            case 7: {
                if (n >= 2)
                    cout << "Power of "<<array[0]<<" raise "<<array[1]<<" = " << pow(array[0], array[1]) << endl;
                else
                    cout << "Error: Power operation requires at least 2 values (base and exponent)." << endl;
                break;
            }

            // -------------------- CASE 8: SQUARE ROOT --------------------
            case 8: {
                if (array[0] >= 0)
                    cout << "Square Root = " << sqrt(array[0]) << endl;
                else
                    cout << "Error: Square root of a negative number is not possible!" << endl;
                break;
            }

            // -------------------- CASE 9: FACTORIAL --------------------
            case 9: {
                int u = (int)array[0];
                if (u >= 0) {
                    double f = 1;
                    for (int i = 1; i <= u; i++)
                        f *= i;
                    cout << "Factorial = " << f << endl;
                } else {
                    cout << "Error: Factorial of a negative number is not possible!" << endl;
                }
                break;
            }

            // -------------------- DEFAULT CASE --------------------
            default:
                cout << "Invalid choice! Please enter a valid option (1–10)." << endl;
        }

        // Step 5: Ask user whether to continue or exit
        cout << "\nDo you want to perform another operation? (Y/N): ";
        char choice;
        cin >> choice;
        if (choice == 'N' || choice == 'n') {
            cout << "\nThank you for using the calculator! 👋" << endl;
            break;
        }

    } while (true); // Loop continues until user decides to exit

    return 0;
}
