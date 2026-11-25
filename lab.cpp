#include <iostream>
using namespace std;


struct student {
    char name[20];
    int id;
    char Dept[20];
    student *next;          
};

student *start = NULL;


//employe
//name and salary


void addSampleData() {
    
    student *p1 = new student;
    strcpy(p1->name, "Abebe");
    p1->id = 101;
    strcpy(p1->Dept, "Software");
    p1->next = NULL;
    
    
    student *p2 = new student;
    strcpy(p2->name, "Kebede");
    p2->id = 102;
    strcpy(p2->Dept, "Computer");
    p2->next = NULL;
    
    
    student *p3 = new student;
    strcpy(p3->name, "Tigist");
    p3->id = 103;
    strcpy(p3->Dept, "Information");
    p3->next = NULL;

    
    start = p1;
    p1->next = p2;
    p2->next = p3;
    
    cout << "\n[Info] 3 sample student records loaded successfully!\n";
}


student* createNode() {
    student *p = new student;
    cout << "Enter name: ";
    cin >> p->name;
    cout << "Enter ID: ";
    cin >> p->id;
    cout << "Enter department: ";
    cin >> p->Dept;
    p->next = NULL;
    return p;
}


void insert_beg(student *p) {
    if (start == NULL) {
        start = p;
    } else {
        student *temp = start;
        start = p;
        p->next = temp;
    }
    cout << "\ninserted successfully at the beginning!\n";
}


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
    cout << "\ninserted successfully at the end!\n";

    }

    void insert_at_position(int c, student *p) {
    if (c <= 1) {
        insert_beg(p);
        return;
    }
    
    student *q = start;
    
    for (int i = 1; i < c - 1 && q != NULL; i++) {
        q = q->next;
    }
    
    if (q == NULL) {
        cout << "\n[Error] Position out of range!\n";
        delete p; 
    } else {
        p->next = q->next;
        q->next = p;
        cout << "\n[Success] Node inserted successfully at position " << c << "!\n";
    }

    }

    void display_forward() {
    if (start == NULL) {
        cout << "\n[Info] The student list is empty!\n";
        return;
    }
    
    student *q = start;
    cout << "\n--- CURRENT STUDENT LIST (FORWARD) ---\n";
    int index = 1;
    while (q != NULL) {
        cout << "Node " << index++ << ":\n";
        cout << "  Name:       " << q->name << "\n";
        cout << "  ID:         " << q->id << "\n";
        cout << "  Department: " << q->Dept << "\n";
        cout << "------------------------------------\n";
        q = q->next;
    }
    }



    void display_backward() {
        
        if (start == NULL) {
            cout << "\nList is empty\n"; 
            return;
        }
        
        cout << "\n--- CURRENT STUDENT LIST (BACKWARD) ---\n";
        
        
        student *curr = start;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        
        int index = 1;
        
        while (true) {
            
            cout << "Node from end (" << index++ << "):\n";
            cout << "  Name:       " << curr->name << "\n";
            cout << "  ID:         " << curr->id << "\n";
            cout << "  Department: " << curr->Dept << "\n";
            cout << "------------------------------------\n";
            
        
            if (curr == start) {
                break;
            }
            
            
            student *previous = start;
            while (previous->next != curr) {
                previous = previous->next;
            }
            
            
            curr = previous;
        }
    }



    
void search_node(int targetId) {
    if (start == NULL) {
        cout << "\n[Info] The student list is empty. Nothing to search!\n";
        return;
    }

    student *q = start;
    int position = 1;
    bool found = false;

    while (q != NULL) {
        
        if (q->id == targetId) {
            cout << "\n[Found] Student located at Node " << position << "!\n";
            cout << "  Name:       " << q->name << "\n";
            cout << "  ID:         " << q->id << "\n";
            cout << "  Department: " << q->Dept << "\n";
            cout << "------------------------------------\n";
            found = true;
            break;
        }
        q = q->next;
        position++;
    }

    if (!found) {
        cout << "\n[Result] Student with ID " << targetId << " was not found in the list.\n";
    }
}

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


void del_last() {
    if (start == NULL) {
        cout << "\n[Error] List is empty!\n";
    } else if (start->next == NULL) {
        delete start;
        start = NULL;
        cout << "\n[Success] Last node deleted successfully!\n";
    } else {
        student *q = start;
        
        while (q->next->next != NULL) {
            q = q->next;
        }
        student *temp = q->next;
        q->next = NULL;
        delete temp;
        cout << "\n[Success] Last node deleted successfully!\n";
    }
}


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
        student *p = q->next; 
        q->next = p->next;    
        delete p;
        cout << "\n[Success] Node at position " << c << " deleted successfully!\n";
    }
}



    int main() {
        addSampleData();


    int choice;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Particular Position\n";
        cout << "4. Display List (Forward)\n";
        cout << "5. Display List (Backward)\n";
        cout << "6. Search for a Student by ID\n";
        cout << "7. Delete First Node\n";
        cout << "8. Delete Last Node\n";
        cout << "9. Delete Node at Particular Position\n";
        cout << "10. Exit\n";
        cout << "Enter your choice (1-10): ";
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
            case 6:
                {
                    int targetId;
                    cout << "Enter the ID of the student to search for: ";
                    cin >> targetId;
                    search_node(targetId);
                }
                break;

            case 7:
                del_first();
                break;
            case 8:
                del_last();
                break;
            case 9:
                {
                    int pos;
                    cout << "Enter the position of the node to delete: ";
                    cin >> pos;
                    del_at_position(pos);
                }
                break;
            case 10:
                cout << "\nExiting program. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please select between 1 and 10.\n";
        }
    } while (choice != 10);

    return 0;
}