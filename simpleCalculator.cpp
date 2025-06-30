#include <iostream>
using namespace std;

int main() {
    double result, num;
    char op;
    bool validOp = true;

    cout << "Enter first number: ";
    cin >> result;

    if (cin.fail()) {
        cout << "Invalid input. Please enter a number." << endl;
        return 1;
    }

    while (true) {
        cout << "Choose operation to do (+, -, *, /, = to exit): ";
        cin >> op;

        if (op == '=') {
            cout << "Thank you for using the calculator. Your last result was " << result << "." << endl;
            break;
        } else if (op == '+' || op == '-' || op == '*' || op == '/') {
            validOp = true;
        } else {
            cout << "Invalid operation. Please try again." << endl;
            validOp = false;
        }

        if (validOp) {
            cout << "Enter next number: ";
            cin >> num;


            if (cin.fail()) {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear(); // Clear error flag
                cin.ignore(10000, '\n'); // Discard invalid input
                continue; // Skip this iteration
            }

            switch(op) {
                case '+':
                    result += num;
                    break;
                case '-':
                    result -= num;
                    break;
                case '*':
                    result *= num;
                    break;
                case '/':
                    if (num != 0)
                        result /= num;
                    else {
                        cout << "Error: Division by zero!" << endl;
                        continue;
                    }
                    break;
            }

            cout << "Result: " << result << endl;
        }
    }

    return 0;
}
