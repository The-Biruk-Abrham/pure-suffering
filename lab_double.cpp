#include <iostream>
using namespace std;


struct Employee {
    string name;
    int salary;
    Employee *next;
    Employee *previous;       
};

Employee *start = NULL;


Employee *createnode(){
    Employee *p = new Employee;
    cout << "Enter Employee Name: ";
    cin >> p-> name;
    cout << "Enter employee salary: ";
    cin  >> p-> salary;
    p -> next = NULL;
    p -> previous = NULL;
    return p;
}


void insert_beg(Employee *p){
    if (start == NULL) {
        start = p;
    }
    else {
        Employee *temp = start;
        start = p;
        temp->previous = p;
        p->next = temp;
    }

    cout <<"Node added successfully\n";
}


void insert_last(Employee *p){
    if (start == NULL) {
        start = p;
    }
    else {
        Employee *temp = start;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
        p->previous = temp;
    }

    cout <<"Node added successfully\n";
}


void insert_atParticular(Employee *p, int c){
    if (c < 1){
        cout << "\n out of range\n";
        delete p;
        return;
    }

    if (c == 1){
        insert_beg(p);
        return;
    }

    if (start == NULL){
        cout << "\n out of range\n";
        delete p;
        return;
    }

    Employee *temp = start;
    for (int i = 1; i < c - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if (temp == NULL){
        cout << "\n out of range\n";
        delete p;
    }
    else if (temp->next == NULL){
        temp->next = p;
        p->previous = temp;
        cout << "Node added successfully\n";
    }
    else {
        p->next = temp->next;
        p->previous = temp;
        temp->next->previous = p;
        temp->next = p;
        cout << "Node added successfully\n";
    }
}


void display_forward (){
    if (start == NULL){
        cout << "\n The list is empity";
        return;
    }

    Employee *temp = start;
    cout << "--- These are the Employee ---" <<endl;
    int idx = 1;

    while (temp != NULL){
        cout << "Employee " << idx <<endl;
        cout << "Name:   " << temp->name <<endl;
        cout << "Salary: " << temp->salary <<endl;
        cout << "------------------------------\n";
        temp = temp->next;
        idx++;
    }
}


void display_backward (){
    if (start == NULL){
        cout << "\n The list is empity";
        return;
    }

    Employee *temp = start;
    while (temp->next != NULL){
        temp = temp->next;
    }

    cout << "--- These are the Employee (Backward) ---" <<endl;
    int idx = 1;

    while (temp != NULL){
        cout << "Employee " << idx <<endl;
        cout << "Name:   " << temp->name <<endl;
        cout << "Salary: " << temp->salary <<endl;
        cout << "------------------------------\n";
        temp = temp->previous;
        idx++;
    }
}


void delete_first() {
    if (start == NULL){
        cout << "\nThe list is empity";
        return;
    }
    else {
        Employee *temp = start;
        start = start->next;
        if (start != NULL){
            start->previous = NULL;
        }
        delete temp;
        cout<< "Node at first deleted\n";
    }
}


void delete_last() {
    if (start == NULL){
        cout << "\n The list is empity";
    }
    else if(start->next == NULL){
        delete start;
        start = NULL;
        cout << "Deleted successfully!\n";
    }
    else {
        Employee *temp = start;
        while(temp->next != NULL){
            temp =temp->next;
        }

        temp->previous->next = NULL;
        delete temp;
        cout << "Deleted successfully!\n";
    }
}


void delete_atParticular(int c){
    if (start == NULL) {
        cout << "\nThe list is empity\n";
        return;
    }

    if (c == 1){
        delete_first();
        return;
    }

    Employee *e = start;
    for (int i=1; i< c && e != NULL; i++){
        e = e->next;
    }

    if(e == NULL){
        cout << "\n out of range\n";
    }
    else {
        if (e->next != NULL) {
            e->next->previous = e->previous;
        }
        if (e->previous != NULL) {
            e->previous->next = e->next;
        }
        delete e;
        cout << "\nDeleted successfully!\n";
    }
}


void search_by_name(string name){
    if (start == NULL){
        cout << "\n The list is empity";
        return;
    }

    Employee *temp = start;
    int idx = 1;
    bool found = false;

    while (temp != NULL){
        if (temp->name == name){
            if (!found){
                cout << "--- Matching Employees ---" << endl;
                found = true;
            }
            cout << "Employee " << idx << endl;
            cout << "Name:   " << temp->name << endl;
            cout << "Salary: " << temp->salary << endl;
            cout << "------------------------------\n";
        }
        temp = temp->next;
        idx++;
    }

    if (!found){
        cout << "\nEmployee with name \"" << name << "\" not found.\n";
    }
}


int main(){
    int choice;
    do {
        cout << "\n--- MENU  --" << endl;
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at last\n";
        cout << "3. Insert at particular position\n";
        cout << "4. Delete at the beginning\n";
        cout << "5. Delete at last\n";
        cout << "6. Delete at particular\n";
        cout << "7. Display forward\n";
        cout << "8. Display backward\n";
        cout << "9. Search by name\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Employee *p = createnode();
                insert_beg(p);
                break;
            }
            case 2: {
                Employee *p = createnode();
                insert_last(p);
                break;
            }
            case 3: {
                int pos;
                cout << "Enter the position to insert: ";
                cin >> pos;
                Employee *p = createnode();
                insert_atParticular(p, pos);
                break;
            }
            case 4: {
                delete_first();
                break;
            }
            case 5: {
                delete_last();
                break;
            }
            case 6: {
                int pos;
                cout << "Enter the position to delete: ";
                cin >> pos;
                delete_atParticular(pos);
                break;
            }
            case 7: {
                display_forward();
                break;
            }
            case 8: {
                display_backward();
                break;
            }
            case 9: {
                string name;
                cout << "Enter Employee Name to search: ";
                cin >> name;
                search_by_name(name);
                break;
            }
            case 10: {
                cout << "Exiting the program.\n";
                return 0;
            }
            default: {
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
    } while(choice != 10);

    return 0;
}
