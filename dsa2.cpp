#include <iostream>

using namespace std;

// --- Helper Functions ---
void printArray(int arr[], int n) {
    cout << "The sorted array is ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Pointer-based swap helper
void swapPtr(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// --- Searching Algorithms ---

int linear(int arr[], int n) {
    int tar;
    cout << "Enter the key - ";
    cin >> tar;

    for (int i = 0; i < n; i++) {
        if (arr[i] == tar) {
            cout << "The number found " << arr[i] << "\n";
            return 0;
        }
    }
    cout << "The value is not found\n";
    return 0;
}

int binary(int arr[], int n) {
    int tar;
    cout << "Enter the key - ";
    cin >> tar;
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == tar) {
            cout << "The number found " << arr[mid] << "\n";
            return 0;
        } else if (arr[mid] < tar) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "The value is not found\n";
    return 0;
}

// --- Sorting Algorithms ---

int simple(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printArray(arr, n);
    return 0;
}

// Original Bubble Sort (Array indexing)
int bubble(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printArray(arr, n);
    return 0;
}

// New Bubble Sort (Pointer arithmetic & pointer swap)
int bubblePointer(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                swapPtr(arr + j, arr + j + 1);
            }
        }
    }
    printArray(arr, n);
    return 0;
}

int selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    printArray(arr, n);
    return 0;
}

int insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printArray(arr, n);
    return 0;
}

// Helper to find position for Binary Insertion Sort
int binarySearchPos(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == arr[mid]) {
            return mid + 1;
        } else if (item > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        int loc = binarySearchPos(arr, key, 0, j);

        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[loc] = key;
    }
    printArray(arr, n);
    return 0;
}

// --- Main Function ---

int main() {
    bool loop = true;
    int n;
    cout << "Enter number of array - ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << " - ";
        cin >> arr[i];
    }

    do {
        cout << "\nChoose what to do" << endl;
        cout << "1. Searching" << endl;
        cout << "2. Sorting" << endl;
        cout << "3. Exit" << endl;

        int chs;
        cout << "Enter - ";
        cin >> chs;

        switch (chs) {
            case 1: {
                int cho;
                cout << "Which searching type" << endl;
                cout << "1. Linear searching " << endl;
                cout << "2. Binary searching " << endl;
                cout << "Enter - ";
                cin >> cho;

                if (cho == 1) {
                    linear(arr, n);
                } else if (cho == 2) {
                    binary(arr, n);
                } else {
                    cout << "Invalid option." << endl;
                }
                break;
            }

            case 2: {
                int ch;
                cout << "Which sorting type" << endl;
                cout << "1. Simple Sort" << endl;
                cout << "2. Bubble Sort" << endl;
                cout << "3. Bubble Sort (Using Pointers)" << endl;
                cout << "4. Selection Sort" << endl;
                cout << "5. Insertion Sort" << endl;
                cout << "6. Binary Insertion Sort" << endl;
                cout << "Enter - ";
                cin >> ch;

                if (ch == 1) {
                    simple(arr, n);
                } else if (ch == 2) {
                    bubble(arr, n);
                } else if (ch == 3) {
                    bubblePointer(arr, n);
                } else if (ch == 4) {
                    selectionSort(arr, n);
                } else if (ch == 5) {
                    insertionSort(arr, n);
                } else if (ch == 6) {
                    binaryInsertionSort(arr, n);
                } else {
                    cout << "Invalid option." << endl;
                }
                break;
            }

            case 3: {
                loop = false;
                cout << "Program Exited..." << endl;
                break;
            }

            default:
                cout << "Invalid selection. Please choose 1, 2, or 3." << endl;
                break;
        }

    } while (loop);

    delete[] arr;
    return 0;
}