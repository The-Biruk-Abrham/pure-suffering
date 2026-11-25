#include <iostream>
#include <string>
using namespace std;

// Define the Doubly Linked List employee node structure
struct employee {
    string name;
    double salary;
    employee *next;      // Points to the successor node
    employee *previous;  // Points to the predecessor node
};

// Global start (head) pointer initialized to NULL
employee *start = NULL;

// Helper function to create and populate a new employee node from keyboard input
employee* createNode() {
    employee *p = new employee;
    cout << "Enter employee name: ";
    cin >> p->name;
    cout << "Enter employee salary: ";
    cin >> p->salary;
    p->next = NULL;
    p->previous = NULL;
    return p;
}

// 1. Insert at the Beginning
void insert_beg(employee *p) {
    if (start == NULL) {
        start = p;
    } else {
        employee *temp = start;
        start = p;
        temp->previous = p; // Making old first node's previous point to new node
        p->next = temp;     // Making new node's next point to old first node
    }
    cout << "\n[Success] Employee inserted successfully at the beginning!\n";
}

// 2. Delete at Beginning
void del_first() {
    if (start == NULL) {
        cout << "\n[Error] The employee list is empty!\n";
    } else {
        employee *temp = start;
        start = start->next;
        if (start != NULL) {
            start->previous = NULL;
        }
        delete temp;
        cout << "\n[Success] First employee deleted successfully!\n";
    }
}

// 3. Delete at the End
void del_last() {
    if (start == NULL) {
        cout << "\n[Error] The employee list is empty!\n";
    } else if (start->next == NULL) {
        delete start;
        start = NULL;
        cout << "\n[Success] Last employee deleted successfully!\n";
    } else {
        employee *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->previous->next = NULL;
        delete temp;
        cout << "\n[Success] Last employee deleted successfully!\n";
    }
}

// 4. Delete at a Particular Position
void del_at_position(int c) {
    if (start == NULL) {
        cout << "\n[Error] The employee list is empty!\n";
        return;
    }
    if (c == 1) {
        del_first();
        return;
    }
    
    employee *s = start;
    for (int i = 1; i < c && s != NULL; i++) {
        s = s->next;
    }
    
    if (s == NULL) {
        cout << "\n[Error] Position not found!\n";
    } else {
        if (s->next != NULL) {
            s->next->previous = s->previous;
        }
        if (s->previous != NULL) {
            s->previous->next = s->next;
        }
        delete s;
        cout << "\n[Success] Employee at position " << c << " deleted successfully!\n";
    }
}

// 5. Display Forward
void display_forward() {
    if (start == NULL) {
        cout << "\n[Info] The employee list is empty!\n";
        return;
    }
    
    employee *temp = start;
    cout << "\n--- EMPLOYEE LIST (FORWARD) ---\n";
    int index = 1;
    while (temp != NULL) {
        cout << "Employee " << index++ << ":\n";
        cout << "  Name:   " << temp->name << "\n";
        cout << "  Salary: $" << temp->salary << "\n";
        cout << "------------------------------\n";
        temp = temp->next;
    }
}

// Main Menu Driver Loop
int main() {
    int choice;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Delete at Beginning\n";
        cout << "3. Delete at the End\n";
        cout << "4. Delete at Particular Position\n";
        cout << "5. Display Forward\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                employee *p = createNode();
                insert_beg(p);
                break;
            }
            case 2:
                del_first();
                break;
            case 3:
                del_last();
                break;
            case 4: {
                int pos;
                cout << "Enter the position number to delete: ";
                cin >> pos;
                del_at_position(pos);
                break;
            }
            case 5:
                display_forward();
                break;
            case 6:
                cout << "\nExiting program. Goodbye!\n";
                break;
            default:
                cout << "\n[Error] Invalid choice! Please select between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}