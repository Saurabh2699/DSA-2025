/*
- Pascal's Triangle
- Majority Element greater than N/3 times
- 3 Sum, unique triplets
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

int main() {
    vector<int> v = {1, 0, -5};

    cout<<largestSubarrayLengthWithSum0(v);
}