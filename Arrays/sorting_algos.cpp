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

void bubble_sort_recursive(int arr[], int index, int n) {
    if(index == n-1) return;

    for(int j=0;j<n-index-1;j++) {
        if(arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }

    bubble_sort_recursive(arr, index+1, n);
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

void merge(int arr[], int start, int mid, int end) {
    int len = end-start+1;
    int temp[len] = {0};
    int i = start;
    int j = mid+1;
    int k = 0;
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    while(j <= end) {
        temp[k++] = arr[j++];
    }

    for(int i=0;i<len;i++) arr[i+start] = temp[i];
}

void mergeSort(int arr[], int start, int end) {
    if(start >= end) return;

    int mid = (start + end)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

/*
TC = O(nlog2n)
SC = O(n), temporary array for merging
*/
void merge_sort(int arr[], int n) {
    mergeSort(arr, 0, n-1);    
    print_arr(arr, n);
}


int getPartitionIndex(int arr[], int low, int high) {
    int pivot = low;
    int i = low;
    int j = high;

    while(i < j) {
        while(i <= high && arr[i] <= arr[pivot]) i++;
        while(j >= low && arr[j] > arr[pivot]) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);

    return j;
}

/*
TC = O(nlog2n)
TC = O(n*n), worst case when the array is sorted and the pivot is the first/last element
this results in skewed recursion tree making the time complexity quadratic
SC = O(1), temporary array for merging
*/
void quick_sort(int arr[], int start, int end) {
    if(start < end) {
        int PI = getPartitionIndex(arr, start, end);
        quick_sort(arr, start, PI-1);
        quick_sort(arr, PI+1, end);
    }
}

int main() {
    int arr[] = {9, -1, -11, 1, 8, 8, 7, 2, 3, 6, 0, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    // selection_sort(arr, n);
    // bubble_sort(arr, n);
    // bubble_sort_recursive(arr, 0, n);
    // insertion_sort(arr, n);
    // quick_sort(arr, 0, n-1);
    // merge_sort(arr, n);
    // print_arr(arr, n);

    return 0;
}