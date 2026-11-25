#include <iostream>
using namespace std;

// Define the Singly Linked List student node structure
struct student {
    char name[20];
    int age;
    char Dept[20];
    student *next;          // Pointer to the next node in the chain[cite: 18, 25]
};

// Global start (head) pointer initialized to NULL[cite: 25]
student *start = NULL;

// Helper function to create and populate a new student node from keyboard input
student* createNode() {
    student *p = new student;
    cout << "Enter student name: ";
    cin >> p->name;
    cout << "Enter student age: ";
    cin >> p->age;
    cout << "Enter student department: ";
    cin >> p->Dept;
    p->next = NULL;
    return p;
}

// 1. Insert at the Beginning[cite: 31]
void insert_beg(student *p) {
    if (start == NULL) {
        start = p;
    } else {
        student *temp = start;
        start = p;
        p->next = temp;
    }
    cout << "\n[Success] Node inserted successfully at the beginning!\n";
}

// 2. Insert at the End[cite: 33]
void insert_end(student *p) {
    if (start == NULL) {
        start = p;
    } else {
        student *q = start;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
    cout << "\n[Success] Node inserted successfully at the end!\n";
}

// 3. Insert at a Particular Position
void insert_at_position(int c, student *p) {
    if (c <= 1) {
        insert_beg(p);
        return;
    }
    
    student *q = start;
    // Traverse to the node right before position c
    for (int i = 1; i < c - 1 && q != NULL; i++) {
        q = q->next;
    }
    
    if (q == NULL) {
        cout << "\n[Error] Position out of range!\n";
        delete p; // Clean up allocated memory if position is invalid
    } else {
        p->next = q->next;
        q->next = p;
        cout << "\n[Success] Node inserted successfully at position " << c << "!\n";
    }
}

// 4. Delete at the Beginning (First Node)[cite: 42]
void del_first() {
    if (start == NULL) {
        cout << "\n[Error] List is empty!\n";
    } else {
        student *temp = start;
        start = temp->next;
        delete temp;
        cout << "\n[Success] First node deleted successfully!\n";
    }
}

// 5. Delete at the End (Last Node)[cite: 44]
void del_last() {
    if (start == NULL) {
        cout << "\n[Error] List is empty!\n";
    } else if (start->next == NULL) {
        delete start;
        start = NULL;
        cout << "\n[Success] Last node deleted successfully!\n";
    } else {
        student *q = start;
        // Find the second-to-last node[cite: 44]
        while (q->next->next != NULL) {
            q = q->next;
        }
        student *temp = q->next;
        q->next = NULL;
        delete temp;
        cout << "\n[Success] Last node deleted successfully!\n";
    }
}

// 6. Delete at a Particular Position[cite: 46]
void del_at_position(int c) {
    if (start == NULL) {
        cout << "\n[Error] List is empty!\n";
        return;
    }
    if (c == 1) {
        del_first();
        return;
    }
    
    student *q = start;
    for (int i = 1; i < c - 1 && q != NULL; i++) {
        q = q->next;
    }
    
    if (q == NULL || q->next == NULL) {
        cout << "\n[Error] Node position not found!\n";
    } else {
        student *p = q->next; // Node to be deleted[cite: 46]
        q->next = p->next;    // Disconnect the node[cite: 46]
        delete p;
        cout << "\n[Success] Node at position " << c << " deleted successfully!\n";
    }
}

// 7. Display the List (Forward Traversal)[cite: 37]
void display() {
    if (start == NULL) {
        cout << "\n[Info] The student list is empty!\n";
        return;
    }
    
    student *q = start;
    cout << "\n--- CURRENT STUDENT LIST (FORWARD) ---\n";
    int index = 1;
    do {
        cout << "Node " << index++ << ":\n";
        cout << "  Name:       " << q->name << "\n";
        cout << "  Age:        " << q->age << "\n";
        cout << "  Department: " << q->Dept << "\n";
        cout << "------------------------------------\n";
        q = q->next;
    } while (q != NULL);
}

// Main Menu Driver Loop
int main() {
    int choice;
    do {
        cout << "\n=== SINGLY LINKED LIST MENU ===\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Particular Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Particular Position\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                student *p = createNode();
                insert_beg(p);
                break;
            }
            case 2: {
                student *p = createNode();
                insert_end(p);
                break;
            }
            case 3: {
                int pos;
                cout << "Enter the position number to insert at: ";
                cin >> pos;
                student *p = createNode();
                insert_at_position(pos, p);
                break;
            }
            case 4:
                del_first();
                break;
            case 5:
                del_last();
                break;
            case 6: {
                int pos;
                cout << "Enter the position number to delete: ";
                cin >> pos;
                del_at_position(pos);
                break;
            }
            case 7:
                display();
                break;
            case 8:
                cout << "\nExiting program. Goodbye!\n";
                break;
            default:
                cout << "\n[Error] Invalid choice! Please select between 1 and 8.\n";
        }
    } while (choice != 8);

    return 0;
}