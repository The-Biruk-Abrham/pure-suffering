#include <iostream>
using namespace std;

// Define the Doubly Linked List student node structure
struct student {
    char name[20];
    int age;
    char Dept[20];
    student *next;      // Points to the successor node[cite: 49, 52]
    student *previous;  // Points to the predecessor node[cite: 52]
};

// Global head pointer for the list[cite: 49]
student *start = NULL;

// Helper function to create and populate a new node from keyboard input
student* createNode() {
    student *p = new student;
    cout << "Enter student name: ";
    cin >> p->name;
    cout << "Enter student age: ";
    cin >> p->age;
    cout << "Enter student department: ";
    cin >> p->Dept;
    p->next = NULL;
    p->previous = NULL;
    return p;
}

// 1. Insert at the Beginning[cite: 54]
void insert_beg(student *p) {
    if (start == NULL) {
        start = p;
    } else {
        student *temp = start;
        start = p;
        temp->previous = p; // Making old first node's previous point to new node[cite: 54]
        p->next = temp;     // Making new node's next point to old first node[cite: 54]
    }
    cout << "\n[Success] Node inserted successfully at the beginning!\n";
}

// 2. Insert at the End[cite: 56]
void insert_end(student *p) {
    if (start == NULL) {
        start = p;
    } else {
        student *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
        p->previous = temp;
    }
    cout << "\n[Success] Node inserted successfully at the end!\n";
}

// 3. Insert at a Particular Position
void insert_at_position(int c, student *p) {
    if (c <= 1) {
        insert_beg(p);
        return;
    }
    
    student *temp = start;
    for (int i = 1; i < c - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        cout << "\n[Error] Position out of range!\n";
        delete p;
    } else if (temp->next == NULL) {
        insert_end(p);
        delete p; // Clean up since insert_end uses its own allocated pointer or handle manually:
        // Wait, to avoid double allocation handling, let's write inline for position:
    } else {
        // Correct insertion between temp and temp->next
        p->next = temp->next;
        p->previous = temp;
        temp->next->previous = p;
        temp->next = p;
        cout << "\n[Success] Node inserted successfully at position " << c << "!\n";
    }
}

// 4. Delete at the Beginning (Start)
void del_first() {
    if (start == NULL) {
        cout << "\n[Error] List is empty!\n";
    } else {
        student *temp = start;
        start = start->next;
        if (start != NULL) {
            start->previous = NULL;
        }
        delete temp;
        cout << "\n[Success] First node deleted successfully!\n";
    }
}

// 5. Delete at the End
void del_last() {
    if (start == NULL) {
        cout << "\n[Error] List is empty!\n";
    } else if (start->next == NULL) {
        delete start;
        start = NULL;
        cout << "\n[Success] Last node deleted successfully!\n";
    } else {
        student *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->previous->next = NULL;
        delete temp;
        cout << "\n[Success] Last node deleted successfully!\n";
    }
}

// 6. Delete at a Particular Position[cite: 61]
void del_at_position(int c) {
    if (start == NULL) {
        cout << "\n[Error] List is empty!\n";
        return;
    }
    if (c == 1) {
        del_first();
        return;
    }
    
    student *s = start;
    for (int i = 1; i < c && s != NULL; i++) {
        s = s->next;
    }
    
    if (s == NULL) {
        cout << "\n[Error] Node position not found!\n";
    } else {
        if (s->next != NULL) {
            s->next->previous = s->previous;
        }
        if (s->previous != NULL) {
            s->previous->next = s->next;
        }
        delete s;
        cout << "\n[Success] Node number " << c << " deleted successfully!\n";
    }
}

// 7. Display Forward Traversal[cite: 49]
void display_forward() {
    if (start == NULL) {
        cout << "\n[Info] The list is empty!\n";
        return;
    }
    student *temp = start;
    cout << "\n--- STUDENT LIST (FORWARD) ---\n";
    int idx = 1;
    while (temp != NULL) {
        cout << "Node " << idx++ << ":\n";
        cout << "  Name:       " << temp->name << "\n";
        cout << "  Age:        " << temp->age << "\n";
        cout << "  Department: " << temp->Dept << "\n";
        cout << "------------------------------\n";
        temp = temp->next;
    }
}

// 8. Display Backward Traversal[cite: 49, 51]
void display_backward() {
    if (start == NULL) {
        cout << "\n[Info] The list is empty!\n";
        return;
    }
    student *temp = start;
    // Step forward to find the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    cout << "\n--- STUDENT LIST (BACKWARD) ---\n";
    int idx = 1;
    // Traverse backward using the previous pointers[cite: 49, 59]
    while (temp != NULL) {
        cout << "Node from end (" << idx++ << "):\n";
        cout << "  Name:       " << temp->name << "\n";
        cout << "  Age:        " << temp->age << "\n";
        cout << "  Department: " << temp->Dept << "\n";
        cout << "------------------------------\n";
        temp = temp->previous;
    }
}

// Main Menu Driver
int main() {
    int choice;
    do {
        cout << "\n=== DOUBLY LINKED LIST MENU ===\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Particular Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Particular Position\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Exit\n";
        cout << "Enter your choice (1-9): ";
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
                display_forward();
                break;
            case 8:
                display_backward();
                break;
            case 9:
                cout << "\nExiting program. Goodbye!\n";
                break;
            default:
                cout << "\n[Error] Invalid choice! Please select between 1 and 9.\n";
        }
    } while (choice != 9);

    return 0;
}