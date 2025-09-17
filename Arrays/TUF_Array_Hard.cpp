/*
- Pascal's Triangle
- Majority Element greater than N/3 times
- 3 Sum, unique triplets
- Merge Overlapping Intervals
- Merge Two Sorted Arrays
- Maximum Product Subarray
- Reverse Pairs
*/

#include<bits/stdc++.h>
using namespace std;

// TC: O(N*N)
// SC: O(N*N)
// LC: https://leetcode.com/problems/pascals-triangle/
vector<vector<int>> generatePascalTriangle(int numRows) {
    vector<vector<int>> pascal(numRows);
    
    for(int i=0;i<numRows;i++) {
        pascal[i].resize(i+1);
        pascal[i][0] = pascal[i][i] = 1;
        
        for(int j=1;j<i;j++)
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
    }
    
    return pascal;
}

// TC: O(N)
// SC: O(1)
// LC: https://leetcode.com/problems/majority-element-ii/
vector<int> majorityElement(vector<int>& nums) {
    int num1 = INT_MAX, num2 = INT_MAX;
    int freq1 = 0, freq2 = 0;
    
    for(int i=0;i<nums.size();i++) {
        if(nums[i] == num1) {
            freq1++;
        }
        
        else if(nums[i] == num2) {
            freq2++;
        }
        
        else if(freq1 == 0) {
            num1 = nums[i];
            freq1 = 1;
        }
        
        else if(freq2 == 0) {
            num2 = nums[i];
            freq2 = 1;
        } 
        
        else {
            freq1--;
            freq2--;
        }
    }
    
    int c1=0, c2=0;
    
    for(int x: nums) {
        if(num1 == x) c1++;
        else if(num2 == x) c2++;
    }
    vector<int> ans;
    if(c1 > nums.size()/3) ans.push_back(num1);
    if(c2 > nums.size()/3) ans.push_back(num2);
    
    return ans;
}

// TC: O(N*N)
// SC: O(Number of unique triplets), ideally constant
// LC: https://leetcode.com/problems/3sum/
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int j = i+1;
        int k = n-1;
        while(j < k) {
            int num1 = nums[i], num2 = nums[j], num3 = nums[k];
            int sum = num1 + num2 + num3;
            if(sum < 0) {
                j++;
            } else if(sum > 0) {
                k--;
            } else {
                res.push_back({num1, num2, num3});
                j++;
                k--;
                while(j < k && nums[j] == num2) j++;
                while(j < k && nums[k] == num3) k--;
            }
        } 
    }

    return res;
}

// TC: O(N*N)
// SC: Constant, only 2D vector used for storing
// LC: https://leetcode.com/problems/4sum/
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int required = target - (nums[i]+nums[j]);
            
            int start = j+1;
            int end = n-1;
            
            while(start < end) {
                if(nums[start] + nums[end] > required) end--;
                
                else if(nums[start] + nums[end] < required) start++;
                
                else {
                    vector<int> quad(4,0);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[start];
                    quad[3] = nums[end];
                    res.push_back(quad);
                    
                    // handling duplicates for number 3
                    while(start < end && nums[start] == quad[2]) start++;
                    
                    // handling duplicates for number 4
                    while(start < end && nums[end] == quad[3]) end--;
                }
            }
            
            // handling duplicates for number 2
            while(j+1 < n && nums[j+1] == nums[j]) j++;
        }
        
        // handling duplicates for number 1
        while(i+1 < n && nums[i+1] == nums[i]) i++;
    }
    
    return res;
}

int largestSubarrayLengthWithSum0(vector<int> &nums) {
    int n = nums.size();
    int len = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    
    for(int i=0; i<n; i++) {
        sum += nums[i];
        if(sum == 0) len = i+1;

        // This means we found a subarray with zero sum
        if(mp.find(sum) != mp.end()) {
            len = max(len, i-mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    return len;
}

// TC: O(NlogN) + O(N) + O(N)
// SC: O(N)
// LC: https://leetcode.com/problems/merge-intervals/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // vector<vector<int>> res;
    // stack<vector<int>> st;

    // sort(intervals.begin(), intervals.end());

    // st.push(intervals[0]);

    // for(int i=1; i<intervals.size(); i++) {
    //     auto top = st.top();
    //     if(intervals[i][0] <= top[1]) {
    //         st.pop();
    //         intervals[i][0] = top[0];
    //         intervals[i][1] = max(intervals[i][1], top[1]);
    //         st.push(intervals[i]);
    //     } else {
    //         st.push(intervals[i]);
    //     }
    // }

    // while(!st.empty()) {
    //     auto top = st.top();
    //     st.pop();
    //     res.push_back(top);
    // }
    
    // return res;

    // Alternate approach without using stack
    // int n = intervals.size();
    // vector<vector<int>> res;

    // sort(intervals.begin(), intervals.end());

    // res.push_back(intervals[0]);
    // for(int i=1; i<n; i++) {
    //     // check if current interval can be merged with previous
    //     if(intervals[i][0] <= res.back()[1]) {
    //         res.back()[1] = max(res.back()[1], intervals[i][1]);
    //     } else {
    //         res.push_back(intervals[i]);
    //     }
    // }

    // return res;
}

// TC: O(M + N)
// SC: Constant
// LC: https://leetcode.com/problems/merge-sorted-array/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    // Approach 1:  Where 0s are present at the end of the array 1 to accommodate array 2 elements

    // int i = m - 1;
    // int j = n - 1;
    // int len = m + n - 1;

    // while(i >= 0 && j >= 0) {
    //     if(nums1[i] >= nums2[j]) {
    //         nums1[len] = nums1[i];
    //         i--;
    //     } else {
    //         nums1[len] = nums2[j];
    //         j--;
    //     }
    //     len--;
    // }

    // while(i >= 0) {
    //     nums1[len] = nums1[i];
    //     i--;
    //     len--;
    // }

    // while(j >= 0) {
    //     nums1[len] = nums2[j];
    //     j--;
    //     len--;
    // }

    // Approach 2: Where no additional space is present in the array 1 to accommodate array 2 elements
    // Problem Link: https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/

    int left = m-1;
    int right = 0;

    while(left >= 0 && right < n) {
        if(nums1[left] > nums2[right]) {
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        } else {
            // this condition means both the arrays have desired elements
            break;
        }
    }

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    cout<<"Array 1: ";
    for(int x: nums1) cout<<x<<" ";
    cout<<"\nArray 2: ";
    for(int x: nums2) cout<<x<<" ";
}

// TC: O(N)
// SC: O(1)
// LC: https://leetcode.com/problems/maximum-product-subarray/
int maxProduct(vector<int>& nums) {
    int n = nums.size();    
    double prefix = 1;
    double suffix = 1;
    double ans = INT_MIN;

    for(int i=0; i<n; i++) {
        if(prefix == 0) prefix = 1;

        if(suffix == 0) suffix = 1;
        
        prefix = prefix * nums[i];
        suffix = suffix * nums[n-i-1];

        ans = max(ans, max(prefix, suffix));
    }

    return ans;
}

void merge(vector<int> &nums, int low, int mid, int high) {
    vector<int> temp;
    int i=low, j=mid+1;

    while(i <= mid && j <= high) {
        if(nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    while(j <= high) {
        temp.push_back(nums[j]);
        j++;
    }

    for(int i=low; i<=high; i++) {
        nums[i] = temp[i-low];
    }
}

int countPairs(vector<int> &nums, int low, int mid, int high) {
    int right = mid+1;
    int cnt = 0;

    for(int i=low; i<=mid; i++) {
        while(right <= high && nums[i] > (long long)2*nums[right]) right++;
        cnt += (right - (mid+1));
    }

    return cnt;
}

int mergeSort(vector<int> &nums, int low, int high) {
    int cnt = 0;

    if(low >= high) return cnt;
    
    int mid = (low + high)/2;
    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid+1, high);
    cnt += countPairs(nums, low, mid, high);
    merge(nums, low, mid, high);

    return cnt;
}

// TC: O(2N*logN)
// SC: O(N)
// LC: https://leetcode.com/problems/reverse-pairs/
int reversePairs(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size()-1);
}

int mergeArrs(vector<int> &nums, int low, int mid, int high) {
    int i = low; 
    int j = mid+1;
    int cnt = 0;
    vector<int> temp;

    while(i <= mid && j <= high) {
        if(nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            cnt += (mid-i+1);
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    while(j <= high) {
        temp.push_back(nums[j]);
        j++;
    }

    for(int i=low; i<=high; i++) {
        nums[i] = temp[i-low];
    }
    
    return cnt; 
}

int cntInversions(vector<int> &nums, int low, int high) {
    int cnt = 0;
    
    if(low >= high) return cnt;

    int mid = (low + high)/2;
    cnt += cntInversions(nums, low, mid);
    cnt += cntInversions(nums, mid + 1, high);
    cnt += mergeArrs(nums, low, mid, high);

    return cnt;
}

// TC: O(N*logN)
// SC: O(N)
// TUF: https://takeuforward.org/data-structure/count-inversions-in-an-array/
int countInversion(vector<int> &nums) {
    return cntInversions(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> v1 = {1, 3, 5, 7};
    vector<int> v2 = {0, 2, 6, 8, 9};

    merge(v1, v1.size(), v2, v2.size());

    //cout<<largestSubarrayLengthWithSum0(v);
}