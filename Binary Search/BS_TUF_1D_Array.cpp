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