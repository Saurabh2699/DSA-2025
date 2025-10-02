#include<bits/stdc++.h>
using namespace std;

// Refer Take You Forward's DSA Sheet
// Binary Search on 1D Arrays Questions
/*
- Lower Bound
- Upper Bound
- Search Insert Position
- Floor/Ceil in Array
- First and Last Occurence of Number
- Count occurences of the given number
- Search in a sorted and rotated array ( unique elements)
- Search in a sorted and rotated array ( duplicates present ) 
- Find minimum in the sorted array
- Find out how many times the sorted array is rotated
- Find single element in the sorted array
- Find peak element in the array with multiple peaks possible
*/

int lower_bound(vector<int> &nums, int x) {
    // First element which is greater than equal to x
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high) {
        int mid = (low + high)/2;
        if(nums[mid] >= x) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid + 1;
        }
    } 

    return ans;
}

int upper_bound(vector<int> &nums, int x) {
    // First element which is greater than x
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high) {
        int mid = (low + high)/2;
        if(nums[mid] > x) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid + 1;
        }
    } 

    return ans;
}


int searchInsertPosition(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high) {
        int mid = (low + high)/2;
        if(nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int ceilOfNumber(vector<int> &nums, int x) {
    return lower_bound(nums, x);
}

int floorOfNumber(vector<int> &nums, int x) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high)/2;
        if(nums[mid] <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans == -1 ? -1 : nums[ans];   
}

int firstOccurence(vector<int> &nums, int x) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high)/2;
        if(nums[mid] == x) {
            ans = mid;
            high = mid-1;
        } else if(nums[mid] > x) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return ans;
}

int lastOccurence(vector<int> &nums, int x) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high)/2;
        if(nums[mid] == x) {
            ans = mid;
            low = mid+1;
        } else if(nums[mid] > x) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return ans;
}

int countOccurences(vector<int> &nums, int x) {
    // Last Occurence - First Occurence + 1
    int fo = firstOccurence(nums, x);
    int lo = lastOccurence(nums, x);
    
    if(fo == -1 || lo == -1) return -1;

    return lo - fo + 1;
}

// Unique elements
int seachInRotatedSortedArray1(vector<int> &nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    
    while(low <= high) {
        int mid = (low + high)/2;
        
        if(nums[mid] == target) return mid;

        // left sorted part
        if(nums[mid] >= nums[low]) {
            // check if target lies in this half
            if(target >= nums[low] && target <= nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else { // right sorted part
            // check if target lies in this half
            if(target >= nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid-1;
            }
        }
    }

    return -1;
}

// duplicates present
int seachInRotatedSortedArray2(vector<int> &nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = (low + high)/2;

        if(nums[mid] == target) return true;

        if(nums[mid] == nums[low] && nums[mid] == nums[high]) {
            low++;
            high--;
        }

        else if(nums[mid] >= nums[low]) {
            if(target >= nums[low] && target <= nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        else {
            if(target >= nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid-1;
            }
        }
    }

    return false;
}

int findMinInSortedRotatedArr(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;

    while(low <= high) {

        // this condition indicates the array is already sorted
        // compute the ans and break the loop
        if(nums[low] <= nums[high]) {
            ans = min(ans, nums[low]);
            break;
        }

        int mid = (low + high)/2;

        // Left half of array is sorted
        if(nums[mid] >= nums[low]) {
            ans = min(ans, nums[low]);
            low = mid + 1;
        } else { // right half of array is sorted
            ans = min(ans, nums[mid]);
            high = mid-1;
        }
    }

    return ans;
}

// Sorted array rotations
int sortedArrayRotationCount(vector<int> &nums) {
    // This returns min element instead return the index of min element
    return findMinInSortedRotatedArr(nums);
}

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    
    if(n == 1) return nums[0];

    if(nums[0] != nums[1]) return nums[0];

    if(nums[n-1] != nums[n-2]) return nums[n-1];

    int low = 1;
    int high = n-2;

    while(low <= high) {

        int mid = (low + high)/2;

        if((nums[mid] != nums[mid-1]) && (nums[mid] != nums[mid+1])) return nums[mid];

        if(((mid % 2 == 1) && (nums[mid] == nums[mid-1])) || ((mid % 2 == 0) && (nums[mid] == nums[mid+1]))) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    if(n == 1) return 0;

    if(nums[0] > nums[1]) return 0;

    if(nums[n-1] > nums[n-2]) return n-1;

    int low = 1, high = n-2;

    while(low <= high) {
        int mid = (low + high)/2;

        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

        else if(nums[mid] < nums[mid+1]) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {3, 4, 4, 4, 4, 7, 8, 10};
    // cout<<lower_bound(nums, 9);
    // cout<<upper_bound(nums, 9);
    // cout<<ceilOfNumber(nums, 8);
    // cout<<floorOfNumber(nums, 8);
    // cout<<firstOccurence(nums, 9);
    // cout<<lastOccurence(nums, 4);
    // cout<<countOccurences(nums, 11);
}