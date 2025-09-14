/*

This file has some miscelleneous array questions
- Find max element in array
- Find second smallest and second largest element in array
- Check if array is sorted
- Check if array sorted and rotated
- Remove duplicates from sorted array
- Move zeroes to end
- Union of Two sorted arrays
- Find max consecutive ones in boolean array
- Find missing number in an array [1..N]
- Find the number which appear once and other numbers appears twice
- Maximum length subarray with sum k (only positives)
- Maximum length subarray with sum k (both positives and negatives)
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

void moveAllZeroesToEnd(int arr[], int n) {
    int i=0, j=0;

    while(j < n) {
        while(j < n && arr[j] == 0) j++;

        if(j >= n) break;

        swap(arr[j], arr[i]);
        i++;
        j++;
    }

    print_arr(arr, n);
}

void unionOfTwoSortedArrays(int arr1[], int arr2[], int n, int m) {

    vector<int> unionArray = {};
    int i=0, j=0;

    while(i < n && j < m) {
        if(arr1[i] <= arr2[j]) {
            if(unionArray.size() == 0 || unionArray.back() != arr1[i]) 
                unionArray.push_back(arr1[i]);
            i++;
        } else {
            if(unionArray.size() == 0 || unionArray.back() != arr2[j])
                unionArray.push_back(arr2[j]);
            j++;
        }
    }

    while(i < n) {
        if(unionArray.back() != arr1[i])
            unionArray.push_back(arr1[i]);
        i++;
    }

    while(j < m) {
        if(unionArray.back() != arr2[j])
            unionArray.push_back(arr2[j]);
        j++;
    }
   
    for(auto x: unionArray) cout<<x<<" ";
}

void removeDuplicatesFromSortedArray(int arr[], int n) {
    // int i=0, j=0;

    // while(j < n) {
    //     if(arr[i] != arr[j]) {
    //         i++;
    //         arr[i] = arr[j];
    //     }
    //     j++;
    // }

    int index = 0;
    for(int i=0; i<n; i++) {
        if(i > 0 && arr[i] != arr[i-1]) {
            index++;
            arr[index] = arr[i];
        }
    }

    print_arr(arr, n);
}

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxi = 0;
    int count = 0;
    int n = nums.size();

    for(int i=0;i<n;i++) {
        if(nums[i] == 1) {
            count++;
            maxi = max(maxi, count);
        } else {
            count = 0;
        }
    }

    return maxi;
}

void findMissingNumber(int arr[], int n) {
    // Approach 1: make use of map/set/frequency counter
    // Approach 2: Sum of [1..N] - Sum of array elements 
    // Approach 3: xor method
    /*
        xor1 = Find xor of all array elements
        xor2 = Find xor of numbers from 1..N
        return xor1 ^ xor2

        Why this works..?

        xor properties:

        1. xor of same numbers = 0 i.e a^a = 0;
        2. xor of a number with 0 = number i.e a^0 = a;
        
    */

    int xor1 = 0, xor2 = 0;

    for(int i=0;i<n-1;i++) {
        xor1 = xor1 ^ arr[i];
        xor2 = xor2 ^ (i+1);
    }
    xor2 = xor2 ^ (n);

    int result = xor1 ^ xor2;

    cout<<result;
}

void findNumberAppearingOnce(int arr[], int n) {
    // Approach 1: frequency counter/hashmap
    // Appoach 2: xor all elements

    int missingNumber = 0;
    for(int i=0;i<n;i++) {
        missingNumber ^= arr[i];
    }

    cout<<missingNumber;
}

/*
Given: an array of size n and a sum k
Find: Need to find out the maximum length of subarray of sum k
*/
// Works for both positive and negative elements
void longestSubarrayWithSumK(int arr[], int n, int k) {
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sum = 0;
    int maxLen = 0;

    for(int i=0;i<n;i++) {
        sum += arr[i];
        if(mp.find(sum-k) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum-k]);
        }
        if(mp.find(sum) == mp.end())
            mp[sum] = i;
    }

    cout<<maxLen;
}

// Works for only positive elements
void longestSubarrayWithSumKInPlace(int arr[], int n, int k) {
    int i=0, j=0;
    int sum = 0;
    int maxLen = 0;

    while(j < n) {
        sum += arr[j];
        
        if(sum == k) {
            maxLen = max(maxLen, j-i+1);
        }

        else {
            while(sum > k) {
                sum -= arr[i];
                i++;
            }
        }

        j++;
    }

    cout<<maxLen;
}

int main() {
    int arr[] = {1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 7, 8};
    //int arr[] = {1, 1, 3, 2, 3, 1, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    //largestElementInArray(arr, n);
    
    //int maxi = INT_MIN;
    //largestElementInArrayRecursive(arr, n, 0, maxi);
    //cout<<maxi;

    //secondSmallestLargestElementInArray(arr, n);

    //cout<<checkIfArrayIsSorted(arr, n);

    //vector<int> nums = {2,7,4,1,2,6,2};
    //cout<<check(nums);

    //leftRotateBy1(arr, n);

    //moveAllZeroesToEnd(arr, n);
    // int n = 10, m = 7;
    // int arr1[] = {1,2,3,4,5,6,7,8,9,10}; 
    // int arr2[] = {2,3,4,4,5,11,12};
    // unionOfTwoSortedArrays(arr1, arr2, n, m);

    removeDuplicatesFromSortedArray(arr, n);

    //findMissingNumber(arr, n+1);

    //findNumberAppearingOnce(arr, n);

    //longestSubarrayWithSumK(arr, n, 5);
    //longestSubarrayWithSumKInPlace(arr, n, 5);
}

