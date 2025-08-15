/*

This file includes various sorting algos
- Selection sort
- Bubble sort
- Insertion sort
- Quick sort
- Merge sort

*/

#include<bits/stdc++.h>
using namespace std;

void print_arr(int arr[], int n) {  
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

/*
TC = O(n*n)
SC = O(1), no additional memory, in place sorting
*/
void selection_sort(int arr[], int n) {

    for(int i=0;i<n-1;i++) {
        int pos = i;
        for(int j=i+1;j<n;j++) {
            if(arr[j] < arr[pos]) {
                pos = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }

    print_arr(arr, n);
}

/*
TC = O(n*n)
SC = O(1), no additional memory, in place sorting
*/
void bubble_sort(int arr[], int n) {

    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    print_arr(arr, n);
}

/*
TC = O(n*n), worst case
TC = O(n) - best case if the array is alread sorted
SC = O(1), no additional memory, in place sorting
*/
void insertion_sort(int arr[], int n) {
    
    for(int i=1;i<n;i++) {
        int j=i;
        while(j > 0 && arr[j] < arr[j-1]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }

    print_arr(arr, n);
}

int main() {
    int arr[] = {9, -1, -11, 1, 8, 8, 7, 2, 3, 6, 0, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    // selection_sort(arr, n);
    // bubble_sort(arr, n);
    insertion_sort(arr, n);
    // quick_sort(arr, n);
    // merge_sort(arr, n);

    return 0;
}