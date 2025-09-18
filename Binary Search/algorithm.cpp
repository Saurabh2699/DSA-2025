#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// SC: O(1) 
int binarySearch(vector<int> &nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = (low + high)/2;
        if(target == nums[mid]) return mid;

        else if(target < nums[mid]) {
            high = mid-1;
        }

        else {
            low = mid+1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    cout<<binarySearch(nums, 2)<<endl;
    cout<<binarySearch(nums, 10);
}