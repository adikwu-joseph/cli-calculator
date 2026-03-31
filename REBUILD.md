# CLI Calculator — Rebuild Guide

This guide walks through rebuilding the CLI Calculator from scratch. Follow each step in order.

---

## Step 1 — Set up the file

Create `main.cpp` and add the includes and namespace:

```cpp
#include <iostream>
#include <limits>

using namespace std;
```

- `iostream` — for `cin` and `cout`
- `limits` — for `numeric_limits` used in input clearing

---

## Step 2 — Write `clearInput()`

This resets `cin` after bad input so the program doesn't get stuck in an infinite loop:

```cpp
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
```

- `cin.clear()` — clears the error flag on the stream
- `cin.ignore(...)` — discards everything left in the input buffer up to and including the newline

---

## Step 3 — Write `isValidOperator()`

Returns `true` if the character is one of the four supported operators:

```cpp
bool isValidOperator(char operation) {
    return operation == '+' || operation == '-' || operation == '*' || operation == '/';
}
```

---

## Step 4 — Write the arithmetic functions

One function per operation, each takes two `double` arguments and returns a `double`:

```cpp
double add(double a, double b)      { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b)   { return a / b; }
```

`divide()` trusts the caller to check for zero before calling it.

---

## Step 5 — Write `main()`

Declare variables:

```cpp
int main() {
    char operation;
    double num1, num2;
    double result = 0.0;
```

- `result` initialised to `0.0` to avoid undefined behaviour

---

## Step 6 — First number input with validation

Inside a `while(true)` loop, prompt for the first number. Retry on invalid input:

```cpp
    while (true) {
        cout << "Enter first number: ";
        while (!(cin >> num1)) {
            cout << "Invalid input. Enter a valid number: ";
            clearInput();
        }
```

- `cin >> num1` returns `false` if the input cannot be parsed as a `double`
- The inner loop keeps retrying until valid input is received

---

## Step 7 — Operator input with quit and validation

```cpp
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
```

- `break` exits the outer `while(true)` loop and ends the program
- `continue` restarts the outer loop from the top, prompting for the first number again

---

## Step 8 — Second number input with validation

Same pattern as Step 6:

```cpp
        cout << "Enter second number: ";
        while (!(cin >> num2)) {
            cout << "Invalid input. Enter a valid number: ";
            clearInput();
        }
```

---

## Step 9 — Perform the calculation

Use a `switch` statement to call the correct function. Handle division by zero before calling `divide()`:

```cpp
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
                if (num2 == 0) {
                    cout << "\nError: Division by zero is not allowed.\n\n";
                    continue;
                }
                result = divide(num1, num2);
                break;
        }
```

- Each `break` prevents fall-through to the next case
- `continue` on division by zero skips the result output and restarts the loop

---

## Step 10 — Print the result

```cpp
        cout << "\nResult: " << num1 << " " << operation << " " << num2 << " = " << result << "\n\n";
    }

    return 0;
}
```

---

## Build & Run

```bash
g++ main.cpp -o calculator
./calculator
```

---

## Common Mistakes to Avoid

| Mistake | Fix |
|---|---|
| `double result;` without initialisation | Always initialise to `0.0` |
| Missing `break` in switch cases | Each case needs `break` to prevent fall-through |
| Not calling `clearInput()` after bad input | Without it, `cin` stays in a failed state and loops infinitely |
| Calling `divide()` without checking `num2` first | Check for zero before the function call |
