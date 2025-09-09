/*
Problems covered in this file:
- 2 Sum
- Sort an array of 0s, 1s and 2s
- Majority Element that appears > n/2 times
- Maximum sum subarray - (Kadane's Algorithm)
- Stock buy and sell
- move all positves to left and all negatives to right
- Next Permutation
- Find leaders in the array
*/ 


#include<bits/stdc++.h>
using namespace std;

// TC: O(N)
// SC: O(N)
// LC: https://leetcode.com/problems/two-sum/description/
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    int n = nums.size();

    for(int i=0;i<n;i++) {
        if(mp.find(target-nums[i]) != mp.end()) {
            return {i, mp[target-nums[i]]};
        }
        mp[nums[i]] = i;
    }
    return {-1, -1};
}

// TC: O(N)
// SC: Constant in place
// LC: https://leetcode.com/problems/sort-colors/
void sortColors(vector<int>& nums) {
        // Brute force
        // TC: O(2N)
        // SC: O(3) ~= constant

        // int n = nums.size();
        // vector<int> v(3, 0);

        // for(int i=0;i<n;i++) {
        //     if(nums[i] == 0) {
        //         v[0]++;
        //     } else if(nums[i] == 1) {
        //         v[1]++;
        //     } else {
        //         v[2]++;
        //     }
        // }

        // int index = 0;
        // for(int i=0;i<v.size();i++) {
        //     int count = v[i];
        //     for(int j=0;j<count;j++) {
        //         nums[index] = i;
        //         index++;
        //     }
        // }

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high) {
            if(nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            } 

            else if(nums[mid] == 1) {
                mid++;
            }

            else {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
        }
    }


// TC: O(N)
// SC: O(1)
// LC: https://leetcode.com/problems/majority-element/
int majorityElement(vector<int>& nums) {
    // TC: O(N)
    // SC: O(N)
    // unordered_map<int, int> mp;
    // int n = nums.size();

    // for(int x: nums) {
    //     mp[x]++;

    //     if(mp[x] > (n/2)) return x;
    // }

    // return INT_MAX;

    int n = nums.size();
    int count = 0;
    int candidate = nums[0];

    for(int x: nums) {
        if(x == candidate) count++;

        else count--;
        
        if(count == 0) {
            count = 1;
            candidate = x;
        }
    }

    return candidate;    
}

// TC: O(N)
// SC: O(1)
// LC: https://leetcode.com/problems/maximum-subarray/ 
// Kadane's Algorithm
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int max_sum = INT_MIN;

    for(int i=0;i<n;i++) {
        sum += nums[i];
        max_sum = max(max_sum, sum);
        if(sum < 0) {
            sum = 0;
        }
    }

    return max_sum;
}

void printMaxSubArraySum(vector<int> &nums) {
    int n = nums.size();
    int sum = 0;
    int max_sum = INT_MIN;
    int start = 0, end = 0;

    for(int i=0;i<n;i++) {
        sum += nums[i];
        if(sum > max_sum) {
            max_sum = sum;
            end = i;
        }
        if(sum < 0) {
            sum = 0;
            start = i+1;
        }
    }

    cout<<start<<" -> "<<end<<endl;

    for(int i=start;i<=end;i++) cout<<nums[i]<<" ";
}

// TC:O(N)
// SC: O(1)
// LC: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int maxProfit = 0;
    int minStockPrice = prices[0];

    for(int i=0;i<n;i++) {
        minStockPrice = min(minStockPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minStockPrice);
    }

    return maxProfit;
}

// Move all the positives towards left side and negatives to the right side
void seggragateArray(vector<int> &nums) {
    // int n = nums.size();
    // int i = 0, j = n-1;

    // while(i < j) {
    //     if(nums[i] >= 0) i++;

    //     else {
    //         swap(nums[i], nums[j]);
    //         j--;
    //     }
    // }

    // for(int x: nums) cout<<x<<" ";

    // another approach
    int n = nums.size();
    int i = 0;
    int j = 0;

    while(j < n) {
        while(j < n && nums[j] < 0) j++;

        if(j >= n) break;

        swap(nums[i], nums[j]);
        i++;
        j++;
    }

    for(int x: nums) cout<<x<<" ";
}

// TC: O(N) overall though multiple passes but approx
// SC: O(1) in place modification
// LC: https://leetcode.com/problems/next-permutation/
void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    // The solution follows 3 steps:

    // Step 1 - Traverse from end and find first element less the next element i.e nums[i] < nums[i+1]
    int brkPoint = -1;
    for(int i = n-2 ; i >= 0 ; i--) {
        if(nums[i] < nums[i+1]) {
            brkPoint = i;
            break;
        }        
    }

    // Means arrays is sorted in decreasing order
    // No next permutation can be found
    // reverse the array
    if(brkPoint == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 2 - Find out first element greater than brkPoint element in right side of array and swap
    for(int i = n-1 ; i > brkPoint ; i--) {
        if(nums[i] > nums[brkPoint]) {
            swap(nums[i], nums[brkPoint]);
            break;
        }
    }

    // Step 3 - Reverse array from brkPoint+1 to n
    reverse(nums.begin() + brkPoint + 1, nums.end());
}

// TC: O(N)
// SC: O(1)
// TUF: https://takeuforward.org/data-structure/leaders-in-an-array/
void printAllLeadersInTheArray(vector<int> &nums) {
    int n = nums.size();
    int maxi = INT_MIN;

    for(int i = n-1; i >= 0; i--) {
        if(nums[i] > maxi) {
            cout<<nums[i]<<" ";
            maxi = nums[i];
        }
    }
}


// TUF: https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/
// Check TC and SC from the article
void longestConsecutiveSequence(vector<int> &nums) {
    int n = nums.size();
    int len = 1;
    int maxLen = INT_MIN;
    int lastNumber = nums[0];

    // Approach: O(NLogN)

    sort(nums.begin(), nums.end());

    for(int i=1; i<n; i++) {
        if(nums[i]-1 == lastNumber) {
            len++;
            lastNumber = nums[i]; 
        } else if(nums[i] != lastNumber) {
            len = 1;
            lastNumber = nums[i];
        }
        maxLen = max(maxLen, len);
    }

    // unordered_set<int> st;

    // for(int x: nums) st.insert(x);

    // for(int i=0; i<n; i++) {
    //     int start = nums[i];
    //     int len = 1;
    //     while(true) {
    //         if(st.find(start+1) != st.end()) {
    //             len++;
    //             maxLen = max(len, maxLen);
    //             start = start+1;
    //         } else {
    //             break;
    //         }
    //     }
    // }

    cout<<"Max Length: "<<maxLen;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 4, 5, 5, 6};
    //seggragateArray(v);
    //printMaxSubArraySum(v);
    //printAllLeadersInTheArray(v);

    longestConsecutiveSequence(v);
}