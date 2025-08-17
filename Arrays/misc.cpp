/*

This file has some miscelleneous array questions
- Find max element in array
- Find second smallest and second largest element in array
- Check if array is sorted
- Check if array sorted and rotated
- Remove duplicated from sorted array
*/

#include<bits/stdc++.h>
using namespace std;

void print_arr(int arr[], int n) {
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void largestElementInArray(int arr[], int n) {
    if(n <= 0) return;

    int maxi = arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i] > maxi) maxi = arr[i];
    }

    cout<<maxi;
}

void largestElementInArrayRecursive(int arr[], int n, int index, int &maxi) {
    if(index == n) return;

    if(arr[index] > maxi) maxi = arr[index];

    largestElementInArrayRecursive(arr, n, index+1, maxi);
}

int findSecondLargest(int arr[], int n) {
    int large = INT_MIN;
    int secondLarge = INT_MIN;

    for(int i=0;i<n;i++) {
        if(arr[i] > large) {
            secondLarge = large;
            large = arr[i];
        }

        else if(arr[i] > secondLarge && arr[i] < large) {
            secondLarge = arr[i];
        }
    }

    return secondLarge == INT_MIN ? -1 : secondLarge;
}

int findSecondSmallest(int arr[], int n) {
    int small = INT_MAX;
    int secondSmall = INT_MAX;

    for(int i=0;i<n;i++) {
        if(arr[i] < small) {
            secondSmall = small;
            small = arr[i];
        }

        else if(arr[i] < secondSmall && arr[i] > small) {
            secondSmall = arr[i];
        }
    }

    return secondSmall == INT_MAX ? -1 : secondSmall;
}

void secondSmallestLargestElementInArray(int arr[], int n) {
    int secondLargest = findSecondLargest(arr, n);
    int secondSmallest = findSecondSmallest(arr, n);

    cout<<"Second largest: "<<secondLargest<<endl;
    cout<<"Second smallest: "<<secondSmallest;
}

bool checkIfArrayIsSorted(int arr[], int n) {
    
    for(int i=1;i<n;i++) {
        if(arr[i] < arr[i-1]) return false; 
    }
    
    return true;
}


bool checkIfArraySorted(vector<int> &nums, int index) {
    int n = nums.size();
    
    for(int i=index;i<n-1;i++) {
        if(nums[i] > nums[i+1]) return false;
    }

    return true;
}

bool checkIfSortedAndRotated(vector<int>& nums) {
    // int breakPt = -1;
    // int n = nums.size();

    // for(int i=0;i<n-1;i++) {
    //     if(nums[i] > nums[i+1]) {
    //         breakPt = i+1;
    //         break;
    //     }
    // }

    // if(breakPt == -1) return true; // array is sorted

    // return checkIfArraySorted(nums, breakPt) && nums[n-1] <= nums[0];

    // Approach 2: Find inversion counts

    int inversionCount = 0;
    int n = nums.size();

    if(n <= 1) return true;

    for(int i=1;i<n;i++) {
        if(nums[i] < nums[i-1]) {
            inversionCount++;
            if(inversionCount > 1) {
                return false;
            }
        }
    }

    if(nums[0] < nums[n-1]) {
        inversionCount++;
    }

    return inversionCount <= 1;
}

void leftRotateBy1(int arr[], int n) {
    int temp = arr[0];
    for(int i=0;i<n-1;i++) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
    
    print_arr(arr, n);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    //largestElementInArray(arr, n);
    
    //int maxi = INT_MIN;
    //largestElementInArrayRecursive(arr, n, 0, maxi);
    //cout<<maxi;

    //secondSmallestLargestElementInArray(arr, n);

    //cout<<checkIfArrayIsSorted(arr, n);

    //vector<int> nums = {2,7,4,1,2,6,2};
    //cout<<check(nums);

    leftRotateBy1(arr, n);
}
