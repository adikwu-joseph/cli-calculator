#include <iostream>
#include <limits>

using namespace std;

// Clears cin error state and discards invalid input to avoid infinite loops
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Validates supported operators
bool isValidOperator(char operation) {
    return operation == '+' || operation == '-' || operation == '*' || operation == '/';
}

double add(double a, double b)      { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b)   { return a / b; }

int main() {
    char operation;
    double num1, num2;
    double result = 0.0;

    while (true) {
        cout << "Enter first number: ";
        while (!(cin >> num1)) {
            cout << "Invalid input. Enter a valid number: ";
            clearInput();
        }

        cout << "Enter operation (+, -, *, /) or 'q' to quit: ";
        cin >> operation;

        if (operation == 'q' || operation == 'Q') {
            cout << "\nExiting calculator. Goodbye!\n";
            break;
        }

        if (!isValidOperator(operation)) {
            cout << "\nInvalid operation. Please try again.\n\n";
            clearInput();
            continue;
        }

        cout << "Enter second number: ";
        while (!(cin >> num2)) {
            cout << "Invalid input. Enter a valid number: ";
            clearInput();
        }

        switch (operation) {
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                // Guard against division by zero
                if (num2 == 0) {
                    cout << "\nError: Division by zero is not allowed.\n\n";
                    continue;
                }
                result = divide(num1, num2);
                break;
        }

        cout << "\nResult: " << num1 << " " << operation << " " << num2 << " = " << result << "\n\n";
    }

    return 0;
}
