#include <iostream>
using namespace std;

int linear(int arr[], int n){
    int tar;
    cout <<"Enter the key - ";
    cin >> tar;

     for (int i = 0; i < n; i++) {
        if (arr[i] == tar) {
            cout << "The number found "<< arr[i]; 
            return 0;
        }
    }
    cout << "The value is not found";
    return 0;
}

int binary(int arr[], int n){
   int tar;
    cout <<"Enter the key - ";
    cin >> tar;
   int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == tar){
           cout << "The number found "<< arr[mid];
           return 0;
           }
        else if (arr[mid] < tar)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "The value is not found";
    return 0;
}



int simple (int arr[], int n){
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    cout <<"The sorted array is ";
    for (int i=0; i < n; i++){
         cout <<arr[i] <<" ";
    }

  return 0;
    
}


int bubble( int arr[], int n){
   
  for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
   cout <<"The sorted array is ";
    for (int i=0; i < n; i++){
         cout <<arr[i] <<" ";
    }

   return 0;
}

int main(){

char loop = true;
int n;
cout<< "Enter number of array - ";
cin >> n;

int arr[n];
for (int i=0; i<n; i++){
     cout <<"Enter number "<< i+1<< " - ";
     cin >>arr[i];
}

do {

cout <<"\n\n Choose what to do"<<endl;
cout <<"1. Searching"<<endl;
cout <<"2. Sorting"<<endl;
cout <<"3. Exit"<<endl;

int chs;
cout <<"Enter - ";
cin>>chs;
cin.ignore();


switch(chs){
   case 1:{
     int cho;
     cout <<"Which searching type"<<endl;
     cout<< "1. Linear searching "<<endl;
     cout<< "2. binary searching "<<endl;
    cout<< "Enter - ";
    cin >>cho;
    
   if (cho ==1){
       linear(arr, n);
    }
    
    else if (cho == 2){
       binary(arr, n);
    }
    
    
    break;
   }
   
  case 2:{
     int ch;
     cout <<"Which sorting type"<<endl;
     cout<< "1. Simple Sort "<<endl;
     cout<< "2. Bubble Sort "<<endl;
    cout<< "Enter - ";
    cin >>ch;
    
   if (ch ==1){
       simple(arr, n);
    }
    
    else if (ch == 2){
       bubble(arr, n);
    }
    
    break;
    
   }
  
  case 3: {
     loop = false;
     cout <<"Program Existed...";
  } 
   
}

  }while (loop);

  return 0;
 }