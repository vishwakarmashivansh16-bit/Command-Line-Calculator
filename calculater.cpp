/*
------------------------------------------------------------
|   Project Title : C++ Command-Line Calculator             |
|   Author        : Shivansh Vishwakarma                    |
|   Language      : C++                                     |
|   Date Created  : October 2025                            |
|   Version       : 1.0                                     |
|-----------------------------------------------------------|
|   Description:                                            |
|   This program is a simple C++ calculator that performs   |
|   multiple mathematical operations such as Addition,      |
|   Subtraction, Multiplication, Division, Remainder,       |
|   Percentage, Power, Square Root, and Factorial.          |
|                                                           |
|   Features:                                               |
|   ➤ Takes multiple inputs using vectors                  |
|   ➤ Uses switch-case for selecting operations            |
|   ➤ Includes input validation for safe execution         |
|   ➤ Beginner-friendly and well-commented code            |
------------------------------------------------------------
*/

#include <bits/stdc++.h>   // Includes all standard libraries (useful for competitive coding)
#include <cmath>           // For mathematical operations like pow() and sqrt()
using namespace std;

int main() {

    // Step 1: Ask the user how many numbers will be used in operations
    cout << "Enter the number of digits in which you will perform calculator operation: " << endl;
    int n;
    cin >> n;  

    // Step 2: Display available operations
    cout << "\nEnter which operation you want to use:" << endl;
    cout << "1. SUM" << endl;
    cout << "2. SUBTRACTION" << endl;
    cout << "3. MULTIPLICATION" << endl;
    cout << "4. DIVISION" << endl;
    cout << "5. REMAINDER" << endl;
    cout << "6. PERCENTAGE" << endl;
    cout << "7. POWER" << endl;
    cout << "8. SQUARE ROOT" << endl;
    cout << "9. FACTORIAL" << endl;

    // Step 3: User chooses which task to perform
    int value;
    cout << "\nEnter which task you have to perform: ";
    cin >> value;

    // Step 4: Take input values from the user
    cout << "\nEnter the value(s): " << endl;
    vector<double> array(n);  // Store user inputs in a dynamic array
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // Step 5: Perform calculation based on user choice
    switch (value) {

        // -------------------- CASE 1: SUM --------------------
        case 1: {
            double sum = 0;
            for (int i = 0; i < n; i++) {
                sum += array[i];
            }
            cout << "Sum = " << sum << endl;
            break;
        }

        // -------------------- CASE 2: SUBTRACTION --------------------
        case 2: {
            double sub = array[0];
            for (int i = 1; i < n; i++) {
                sub -= array[i];
            }
            cout << "Subtraction = " << sub << endl;
            break;
        }

        // -------------------- CASE 3: MULTIPLICATION --------------------
        case 3: {
            double mul = 1;
            for (int i = 0; i < n; i++) {
                mul *= array[i];
            }
            cout << "Multiplication = " << mul << endl;
            break;
        }

        // -------------------- CASE 4: DIVISION --------------------
        case 4: {
            double division = array[0];
            for (int i = 1; i < n; i++) {
                if (array[i] != 0)
                    division /= array[i];
                else {
                    cout << "Error: Division by zero is not possible!" << endl;
                    return 0; // Exit the program safely
                }
            }
            cout << "Division = " << division << endl;
            break;
        }

        // -------------------- CASE 5: REMAINDER --------------------
        case 5: {
            // Using integer modulus since remainder operation is for integers
            int a = array[0], b = array[1];
            if (b != 0) {
                int rem = a % b;
                cout << "Remainder = " << rem << endl;
            } else {
                cout << "Error: Division by zero is not possible for remainder!" << endl;
            }
            break;
        }

        // -------------------- CASE 6: PERCENTAGE --------------------
        case 6: {
            double total = 0;
            for (int i = 0; i < n; i++) {
                total += array[i];
            }
            double percentage = (total / n); // Average value
            cout << "Percentage (average) = " << percentage << "%" << endl;
            break;
        }

        // -------------------- CASE 7: POWER --------------------
        case 7: {
            if (n >= 2) {
                double t = pow(array[0], array[1]); // base^exponent
                cout << "Power = " << t << endl;
            } else {
                cout << "Error: Power operation requires at least 2 values (base and exponent)." << endl;
            }
            break;
        }

        // -------------------- CASE 8: SQUARE ROOT --------------------
        case 8: {
            if (array[0] >= 0) {
                double s = sqrt(array[0]);
                cout << "Square Root = " << s << endl;
            } else {
                cout << "Error: Square root of a negative number is not possible!" << endl;
            }
            break;
        }

        // -------------------- CASE 9: FACTORIAL --------------------
        case 9: {
            cout << "Enter a value for factorial: " << endl;
            int u = (int)array[0];
            if (u >= 0) {
                double f = 1;
                for (int i = 1; i <= u; i++) {
                    f *= i;
                }
                cout << "Factorial = " << f << endl;
            } else {
                cout << "Error: Factorial of a negative number is not possible!" << endl;
            }
            break;
        }

        // -------------------- DEFAULT CASE --------------------
        default: {
            cout << "Invalid choice! Please restart and select a valid operation number (1-9)." << endl;
            break;
        }
    }

    return 0;
}
