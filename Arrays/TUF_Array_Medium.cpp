/*
Problems covered in this file:
- 2 Sum
- Sort an array of 0s, 1s and 2s
*/ 

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