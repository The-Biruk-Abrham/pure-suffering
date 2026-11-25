#include <iostream>
#include <string>
using namespace std;

// Define the Doubly Linked List student node structure
struct student {
    char name[20];
    int age;
    char Dept[20];
    student *next;      // Points to the successor node[cite: 49, 52]
    student *previous;  // Points to the predecessor node[cite: 52]
};

// Global start (head) pointer initialized to NULL
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
        temp->next = p;
        p->previous = temp;
        cout << "\n[Success] Node inserted successfully at position " << c << "!\n";
    } else {
        p->next = temp->next;
        p->previous = temp;
        temp->next->previous = p;
        temp->next = p;
        cout << "\n[Success] Node inserted successfully at position " << c << "!\n";
    }
}

// 4. Display List (Forward)[cite: 49]
void display_forward() {
    if (start == NULL) {
        cout << "\n[Info] The student list is empty!\n";
        return;
    }
    
    student *temp = start;
    cout << "\n--- STUDENT LIST (FORWARD) ---\n";
    int index = 1;
    while (temp != NULL) {
        cout << "Node " << index++ << ":\n";
        cout << "  Name:       " << temp->name << "\n";
        cout << "  Age:        " << temp->age << "\n";
        cout << "  Department: " << temp->Dept << "\n";
        cout << "------------------------------\n";
        temp = temp->next;
    }
}

// 5. Display List (Backward)[cite: 49, 51]
void display_backward() {
    if (start == NULL) {
        cout << "\n[Info] The student list is empty!\n";
        return;
    }
    
    student *temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    cout << "\n--- STUDENT LIST (BACKWARD) ---\n";
    int index = 1;
    while (temp != NULL) {
        cout << "Node from end (" << index++ << "):\n";
        cout << "  Name:       " << temp->name << "\n";
        cout << "  Age:        " << temp->age << "\n";
        cout << "  Department: " << temp->Dept << "\n";
        cout << "------------------------------\n";
        temp = temp->previous;
    }
}

// 6. Search for a Student by Name (Linear Search)[cite: 24, 48]
void search_node(string targetName) {
    if (start == NULL) {
        cout << "\n[Info] The student list is empty. Nothing to search!\n";
        return;
    }

    student *q = start;
    int position = 1;
    bool found = false;

    while (q != NULL) {
        string currentName = q->name; // Convert char array to std::string for comparison
        if (currentName == targetName) {
            cout << "\n[Found] Student located at Node " << position << "!\n";
            cout << "  Name:       " << q->name << "\n";
            cout << "  Age:        " << q->age << "\n";
            cout << "  Department: " << q->Dept << "\n";
            cout << "------------------------------\n";
            found = true;
            break;
        }
        q = q->next;
        position++;
    }

    if (!found) {
        cout << "\n[Result] Student with name '" << targetName << "' was not found in the list.\n";
    }
}

// Main Menu Driver Loop
int main() {
    int choice;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Particular Position\n";
        cout << "4. Display List (Forward)\n";
        cout << "5. Display List (Backward)\n";
        cout << "6. Search for a Student by Name\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
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
                display_forward();
                break;
            case 5:
                display_backward();
                break;
            case 6: {
                string searchName;
                cout << "Enter the name of the student to search: ";
                cin >> searchName;
                search_node(searchName);
                break;
            }
            case 7:
                cout << "\nExiting program. Goodbye!\n";
                break;
            default:
                cout << "\n[Error] Invalid choice! Please select between 1 and 7.\n";
        }
    } while (choice != 7);

    return 0;
}