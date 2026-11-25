#include <iostream>
#include <string>
using namespace std;

const int MAX_STACK = 100;

// ==========================================
// 1. MAIN INTEGER STACK (ARRAY-BASED)
// ==========================================
int stackArr[MAX_STACK];
int top = -1;

void initialize() {
    top = -1;
}

bool isEmpty() {
    return (top < 0);
}

bool isFull() {
    return (top >= MAX_STACK - 1);
}

int getSize() {
    return top + 1;
}

void makeEmpty() {
    top = -1;
    cout << "\n[Success] Stack cleared (made empty).\n";
}

void push(int newItem) {
    if (isFull()) {
        cout << "\n[Error] Stack Overflow! Cannot push " << newItem << ".\n";
    } else {
        top++;
        stackArr[top] = newItem;
        cout << "\n[Success] Pushed " << newItem << " onto the stack.\n";
    }
}

int pop() {
    if (isEmpty()) {
        cout << "\n[Error] Stack Underflow! Stack is empty.\n";
        return -1;
    } else {
        int removedItem = stackArr[top];
        top--;
        return removedItem;
    }
}

int peek() {
    if (isEmpty()) {
        cout << "\n[Info] Stack is empty. No top element.\n";
        return -1;
    } else {
        return stackArr[top];
    }
}

void display() {
    if (isEmpty()) {
        cout << "\n[Info] Stack is empty.\n";
        return;
    }
    cout << "\n--- STACK ELEMENTS (TOP TO BOTTOM) ---\n";
    for (int i = top; i >= 0; i--) {
        cout << "  " << stackArr[i] << (i == top ? "  <-- TOP" : "") << "\n";
    }
    cout << "--------------------------------------\n";
}

// ==========================================
// 2. HELPER CHARACTER & STRING STACKS
// ==========================================
struct CharStack {
    char data[MAX_STACK];
    int tos;

    CharStack() {
        tos = -1;
    }

    bool empty() {
        return tos < 0;
    }

    bool full() {
        return tos >= MAX_STACK - 1;
    }

    void push(char ch) {
        if (!full()) {
            data[++tos] = ch;
        }
    }

    char pop() {
        if (!empty()) {
            return data[tos--];
        }
        return '\0';
    }

    char topVal() {
        if (!empty()) {
            return data[tos];
        }
        return '\0';
    }
};

struct StringStack {
    string data[MAX_STACK];
    int tos;

    StringStack() {
        tos = -1;
    }

    bool empty() {
        return tos < 0;
    }

    bool full() {
        return tos >= MAX_STACK - 1;
    }

    void push(const string& s) {
        if (!full()) {
            data[++tos] = s;
        }
    }

    string pop() {
        if (!empty()) {
            return data[tos--];
        }
        return "";
    }
};

// ==========================================
// 3. STACK APPLICATIONS
// ==========================================

// Reverse a string using a stack
void reverseStringApp() {
    string text;
    cout << "Enter a word/string (no spaces): ";
    cin >> text;

    CharStack s;
    for (int i = 0; i < (int)text.length(); i++) {
        s.push(text[i]);
    }

    cout << "Reversed string: ";
    while (!s.empty()) {
        cout << s.pop();
    }
    cout << "\n";
}

// Reverse a list of numbers using the main stack
void reverseNumbersApp() {
    int count, val;
    cout << "How many numbers do you want to reverse? ";
    cin >> count;

    if (count <= 0 || count > MAX_STACK) {
        cout << "[Error] Enter a count between 1 and " << MAX_STACK << ".\n";
        return;
    }

    initialize();
    for (int i = 0; i < count; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> val;
        push(val);
    }

    cout << "Reversed numbers: ";
    while (!isEmpty()) {
        cout << pop() << " ";
    }
    cout << "\n";
}

// Check if a string is a palindrome using a stack
void palindromeApp() {
    string word;
    cout << "Enter a word to check palindrome: ";
    cin >> word;

    CharStack s;
    for (int i = 0; i < (int)word.length(); i++) {
        s.push(word[i]);
    }

    string reversed = "";
    while (!s.empty()) {
        reversed += s.pop();
    }

    if (word == reversed) {
        cout << "[Result] '" << word << "' IS a palindrome.\n";
    } else {
        cout << "[Result] '" << word << "' is NOT a palindrome.\n";
    }
}

// Check balanced parentheses / brackets / braces
bool isMatchingPair(char openCh, char closeCh) {
    return (openCh == '(' && closeCh == ')') ||
           (openCh == '{' && closeCh == '}') ||
           (openCh == '[' && closeCh == ']');
}

void balancedBracketsApp() {
    string expr;
    cout << "Enter an expression with brackets/braces/parentheses: ";
    cin >> expr;

    CharStack s;
    bool balanced = true;

    for (int i = 0; i < (int)expr.length(); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || !isMatchingPair(s.pop(), ch)) {
                balanced = false;
                break;
            }
        }
    }

    if (!s.empty()) {
        balanced = false;
    }

    if (balanced) {
        cout << "[Result] Brackets/braces are BALANCED.\n";
    } else {
        cout << "[Result] Brackets/braces are NOT balanced.\n";
    }
}

// Convert decimal number to binary using a stack
void decimalToBinaryApp() {
    int num;
    cout << "Enter a non-negative decimal number: ";
    cin >> num;

    if (num < 0) {
        cout << "[Error] Please enter a non-negative number.\n";
        return;
    }

    if (num == 0) {
        cout << "Binary: 0\n";
        return;
    }

    initialize();
    int temp = num;
    while (temp > 0) {
        int rem = temp % 2;
        push(rem);
        temp = temp / 2;
    }

    cout << "Binary of " << num << ": ";
    while (!isEmpty()) {
        cout << pop();
    }
    cout << "\n";
}

// Evaluate single-digit postfix expression (e.g., 23+ or 6523+8*+3+*)
void evaluatePostfixApp() {
    string postfix;
    cout << "Enter postfix expression (single digits and +, -, *, /, %): ";
    cin >> postfix;

    initialize();

    for (int i = 0; i < (int)postfix.length(); i++) {
        char ch = postfix[i];
        if (ch >= '0' && ch <= '9') {
            push(ch - '0');
        } else {
            if (getSize() < 2) {
                cout << "[Error] Invalid postfix expression.\n";
                return;
            }
            int x = pop();
            int y = pop();
            int result = 0;

            if (ch == '+') result = y + x;
            else if (ch == '-') result = y - x;
            else if (ch == '*') result = y * x;
            else if (ch == '/') {
                if (x == 0) {
                    cout << "[Error] Division by zero.\n";
                    return;
                }
                result = y / x;
            } else if (ch == '%') {
                if (x == 0) {
                    cout << "[Error] Modulo by zero.\n";
                    return;
                }
                result = y % x;
            } else {
                cout << "[Error] Unsupported operator '" << ch << "'.\n";
                return;
            }

            push(result);
        }
    }

    if (getSize() == 1) {
        cout << "[Result] Postfix evaluation = " << pop() << "\n";
    } else {
        cout << "[Error] Invalid postfix expression.\n";
    }
}

// Operator precedence for Infix to Postfix conversion
int precedence(char op) {
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfixApp() {
    string infix;
    cout << "Enter infix expression (no spaces, e.g., A+B*C or (A+B)*C): ";
    cin >> infix;

    CharStack ops;
    string postfix = "";

    for (int i = 0; i < (int)infix.length(); i++) {
        char ch = infix[i];

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        } else if (ch == '(') {
            ops.push(ch);
        } else if (ch == ')') {
            while (!ops.empty() && ops.topVal() != '(') {
                postfix += ops.pop();
            }
            if (!ops.empty() && ops.topVal() == '(') {
                ops.pop();
            }
        } else {
            while (!ops.empty() && ops.topVal() != '(' && precedence(ops.topVal()) >= precedence(ch)) {
                postfix += ops.pop();
            }
            ops.push(ch);
        }
    }

    while (!ops.empty()) {
        if (ops.topVal() != '(') {
            postfix += ops.pop();
        } else {
            ops.pop();
        }
    }

    cout << "[Result] Postfix expression: " << postfix << "\n";
}

// Undo / Redo command simulation using two stacks
void undoRedoApp() {
    StringStack undoStack;
    StringStack redoStack;
    string cmd;

    cout << "\n--- UNDO / REDO SIMULATOR ---\n";
    cout << "Type a command (e.g., TypeA, Bold), or 'undo', 'redo', or 'exit':\n";

    while (true) {
        cout << "Command> ";
        cin >> cmd;

        if (cmd == "exit") {
            break;
        } else if (cmd == "undo") {
            if (undoStack.empty()) {
                cout << "[Info] Nothing to undo.\n";
            } else {
                string lastCmd = undoStack.pop();
                redoStack.push(lastCmd);
                cout << "[Undo] Undid command: " << lastCmd << "\n";
            }
        } else if (cmd == "redo") {
            if (redoStack.empty()) {
                cout << "[Info] Nothing to redo.\n";
            } else {
                string reCmd = redoStack.pop();
                undoStack.push(reCmd);
                cout << "[Redo] Redid command: " << reCmd << "\n";
            }
        } else {
            undoStack.push(cmd);
            redoStack.tos = -1; // Clear redo history on new action
            cout << "[Recorded] Executed command: " << cmd << "\n";
        }
    }
}

// ==========================================
// 4. MAIN MENU DRIVER
// ==========================================
int main() {
    initialize();
    int choice;

    do {
        cout << "\n================ STACK & APPLICATIONS MENU ================\n";
        cout << "--- Core Stack Operations ---\n";
        cout << " 1. Push\n";
        cout << " 2. Pop\n";
        cout << " 3. Peek (Top Element)\n";
        cout << " 4. Check isEmpty / isFull / Size\n";
        cout << " 5. Display Stack\n";
        cout << " 6. Clear Stack (makeEmpty)\n";
        cout << "--- Stack Applications ---\n";
        cout << " 7. Reverse a String\n";
        cout << " 8. Reverse a List of Numbers\n";
        cout << " 9. Check Palindrome\n";
        cout << "10. Check Balanced Brackets/Braces\n";
        cout << "11. Convert Decimal to Binary\n";
        cout << "12. Evaluate Postfix Expression\n";
        cout << "13. Convert Infix to Postfix\n";
        cout << "14. Undo / Redo Simulation\n";
        cout << "15. Exit\n";
        cout << "Enter your choice (1-15): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter integer value to push: ";
                cin >> val;
                push(val);
                break;
            }
            case 2: {
                if (!isEmpty()) {
                    int popped = pop();
                    cout << "\n[Success] Popped element: " << popped << "\n";
                } else {
                    pop();
                }
                break;
            }
            case 3: {
                int topVal = peek();
                if (!isEmpty()) {
                    cout << "\n[Top] Current top element: " << topVal << "\n";
                }
                break;
            }
            case 4:
                cout << "\n[Status] isEmpty: " << (isEmpty() ? "True" : "False")
                     << " | isFull: " << (isFull() ? "True" : "False")
                     << " | Size: " << getSize() << "\n";
                break;
            case 5:
                display();
                break;
            case 6:
                makeEmpty();
                break;
            case 7:
                reverseStringApp();
                break;
            case 8:
                reverseNumbersApp();
                break;
            case 9:
                palindromeApp();
                break;
            case 10:
                balancedBracketsApp();
                break;
            case 11:
                decimalToBinaryApp();
                break;
            case 12:
                evaluatePostfixApp();
                break;
            case 13:
                infixToPostfixApp();
                break;
            case 14:
                undoRedoApp();
                break;
            case 15:
                cout << "\nExiting program. Good luck in your lab!\n";
                break;
            default:
                cout << "\n[Error] Invalid choice! Please enter a number from 1 to 15.\n";
        }
    } while (choice != 15);

    return 0;
}