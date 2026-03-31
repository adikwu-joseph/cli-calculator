# CLI Calculator

A command-line calculator written in C++ that performs basic arithmetic operations with input validation and error handling.

## Features

- Addition, subtraction, multiplication, division
- Input validation — rejects non-numeric input and invalid operators
- Division by zero protection
- Continuous loop — perform multiple calculations without restarting
- Clean exit with `q`

## Usage

```
Enter first number: 10
Enter operation (+, -, *, /) or 'q' to quit: *
Enter second number: 5

Result: 10 * 5 = 50
```

## Build & Run

**Requirements:** C++ compiler (g++ or clang++)

```bash
g++ main.cpp -o calculator
./calculator
```

## Concepts Demonstrated

- Function decomposition
- Switch statements
- While loops and control flow (`break`, `continue`)
- Input validation using `cin` failure state and `numeric_limits`
- Division by zero error handling

## Future Improvements

- Add calculation history
- Add modulus and power operations
- Refactor into OOP design

## License

MIT
