/**************************************************************
* DSA-2025: Binary Search Problem Solutions
* ------------------------------------------------------------
* This file contains C++ implementations of classic binary search problems.
* Each function solves a different type of binary search problem, including:
*   1. Integer Square Root
*   2. Nth Root of a Number
*   3. Koko Eating Bananas
*   4. Minimum Days to Make Bouquets
*   5. Smallest Divisor Given a Threshold
*   6. Capacity To Ship Packages Within D Days
*   7. Kth missing positive number
*   8. Aggresive Cows
*   9. Split Array Largest Sum
* ------------------------------------------------------------
* Sources & Problem Links:
*   1. Square Root: https://leetcode.com/problems/sqrtx/
*   2. Nth Root: https://www.geeksforgeeks.org/find-nth-root-of-a-number/
*   3. Koko Eating Bananas: https://leetcode.com/problems/koko-eating-bananas/
*   4. Minimum Days to Make Bouquets: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
*   5. Smallest Divisor: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
*   6. Capacity To Ship Packages Within D Days: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*   7. Kth Missing Positive Number: https://leetcode.com/problems/kth-missing-positive-number/
*   8. Aggressive Cows: https://www.spoj.com/problems/AGGRCOW/ (SPOJ)
*   9. Split Array Largest Sum: https://leetcode.com/problems/split-array-largest-sum/
* ------------------------------------------------------------
* Author: Saurabh2699
* Last Updated: October 2, 2025
**************************************************************/

#include<bits/stdc++.h>
using namespace std;


/**
 * Finds the integer square root of N using binary search.
 * LeetCode: https://leetcode.com/problems/sqrtx/
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */
int squareRoot(int N) {
//     int ans = 1;

//     while(ans * ans <= N) {
//         ans++;
//     }

//     return ans-1;

    int low = 1;
    int high = N/2;
    int ans = 1;

    while(low <= high) {
        int mid = (low + high)/2;
        if((mid * mid) <= N) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }

    return ans;
}

/**
 * Helper function to compute mid^n and compare with m.
 * Used in findNthRoot.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int power(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

/**
 * Finds the integer Nth root of M using binary search.
 * GFG: https://www.geeksforgeeks.org/find-nth-root-of-a-number/
 * Time Complexity: O(log M * N)
 * Space Complexity: O(1)
 */
int findNthRoot(int N, int M) {
    int low = 1, high = M;

    while(low <= high) {
        int mid = (low + high)/2;
        int nthPower = power(mid, N, M);

        if(nthPower == 1) return mid;

        else if(nthPower == 0) low = mid+1;

        else high = mid-1;
    }

    return -1;
}

/**
 * Helper function for Koko Eating Bananas problem.
 * Calculates total hours needed at speed k.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
int findTimeToEatBananas(int k, vector<int> &piles) {
    int hours = 0;
    for(int pile : piles){
        int div = pile / k;
        hours += div;
        if(pile % k != 0) hours++;
    }
    return hours;
}

/**
 * Finds the minimum eating speed for Koko to finish bananas in h hours.
 * LeetCode: https://leetcode.com/problems/koko-eating-bananas/
 * Time Complexity: O(N log M)
 * Space Complexity: O(1)
 */
int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int maxi = INT_MIN;
    for(int x: piles) {
        maxi = max(maxi, x);
    }
    
    int low = 1;
    int high = maxi;

    while(low < high) {
        int mid = low + (high-low)/2;
        int hours = findTimeToEatBananas(mid, piles);
        if(hours <= h) {
            high = mid;
        } else {
            low = mid+1;
        }
    }

    return low;
}

/**
 * Helper function for Minimum Days to Make Bouquets problem.
 * Calculates number of bouquets possible by day.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
int calculateBouquets(int day, vector<int> &bloomDay, int M, int K) {
    int bouquets = 0;
    int flowers = 0;

    for(int bd: bloomDay) {
        if(bd <= day) {
            flowers++;
            if(flowers == K) {
                bouquets++;
                flowers = 0;
            }
        } else {
            flowers = 0;
        }
    }

    return bouquets;
}

/**
 * Finds the minimum number of days to make m bouquets of k flowers each.
 * LeetCode: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
 * Time Complexity: O(N log D), D = max-min bloomDay
 * Space Complexity: O(1)
 */
int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int x: bloomDay) {
        mini = min(mini, x);
        maxi = max(maxi, x);
    }

    int low = mini, high = maxi, ans = -1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        int bouquets = calculateBouquets(mid, bloomDay, m, k);
        if(bouquets >= m) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return ans;
}

/**
 * Helper function for Smallest Divisor problem.
 * Calculates the sum of ceil division of each element by divisor.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
int calculateSumOfDivision(vector<int> &nums, int divisor) {
        int sum = 0;
        for(int num: nums) {
            sum += ceil((double)num/(double)divisor);
        }
        return sum;
    }

int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    int maxi = INT_MIN;
    for(int num: nums) {
        maxi = max(maxi, num);
    }
    
    int low = 1;
    int high = maxi;
    int ans = maxi;
    while(low <= high) {
        int mid = (low + high)/2;
        int sum = calculateSumOfDivision(nums, mid);
        if(sum <= threshold) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    
    return ans;
}

/**
 * Helper function for Capacity To Ship Packages Within D Days problem.
 * Calculates the number of days needed to ship all packages with given capacity.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
int getDaysToShip(vector<int> &weights, int capacity) {
    int currCapacity = 0;
    int days = 1;

    for(int wt: weights) {
        if(currCapacity + wt > capacity) {
            days++;
            currCapacity = wt;
        } else {
            currCapacity += wt;
        }
    }

    return days;
}

/**
 * Finds the minimum capacity to ship packages within given days using binary search.
 * LeetCode: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 * Time Complexity: O(N log S), S = sum of weights
 * Space Complexity: O(1)
 */
int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int maxi = INT_MIN;
    int sum = 0;
    
    for(int wt: weights) {
        maxi = max(maxi, wt);
        sum += wt;
    }
    
    int low = maxi;
    int high = sum;
    int ans = sum;

    while(low <= high) {
        int mid = (low + high)/2;
        int noOfDays = getDaysToShip(weights, mid);
        if(noOfDays <= days) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return ans;
}

/**
 * Finds the kth missing positive number in a sorted array using binary search.
 * LeetCode: https://leetcode.com/problems/kth-missing-positive-number/
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */
int findKthPositive(vector<int>& arr, int k) {
    // Brute Force Approach
    // int n = arr.size();

    // if(k < arr[0]) return k;

    // int prev = 0;
    // for(int i=0; i<n; i++) {
    //     int ms = arr[i] - prev - 1;
    //     if(ms < k) {
    //         k = k-ms;
    //         prev = arr[i];
    //     } else {
    //         return prev + k;
    //     }
    // }

    // return arr.back() + k;

    // Optimized Approach - Binary Search
    int n = arr.size();
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = (low + high)/2;
        int gap = arr[mid] - mid - 1;
        if(gap < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return k + low;
}

/**
 * Helper function for Aggressive Cows problem.
 * Counts how many cows can be placed with at least 'distance' apart.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
int countCows(vector<int> &stalls, int distance) {
    int cows = 1;
    int prev = stalls[0];

    for(int i=1; i<stalls.size(); i++) {
        int diff = stalls[i] - prev;
        if(diff >= distance) {
            cows++;
            prev = stalls[i];
        }
    }

    return cows;
}

/**
 * Finds the largest minimum distance to place k cows in stalls using binary search.
 * SPOJ: https://www.spoj.com/problems/AGGRCOW/
 * Time Complexity: O(N log D), D = stalls[n-1] - stalls[0]
 * Space Complexity: O(1)
 */
int agressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size();

    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls[n-1]-stalls[0];
    int ans = 1;

    while(low <= high) {
        int mid = (low + high)/2;
        int cows = countCows(stalls, mid);
        if(cows >= k) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}


/**
 * Helper function for Split Array Largest Sum problem.
 * Counts how many subarrays are needed if the maximum allowed sum is 'sum'.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
int getSubArraysCount(vector<int> &nums, int sum) {
    int curr_sum = 0;
    int subarrays = 1;

    for(int i=0; i<nums.size(); i++) {
        if(curr_sum + nums[i] > sum) {
            subarrays++;
            curr_sum = nums[i];
        } else {
            curr_sum += nums[i];
        }
    }

    return subarrays;
}

/**
 * Splits the array into k subarrays such that the largest sum among them is minimized.
 * LeetCode: https://leetcode.com/problems/split-array-largest-sum/
 * Time Complexity: O(N log S), S = sum of array elements
 * Space Complexity: O(1)
 */
int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;
    int maxi = INT_MIN;

    for(int x: nums) {
        maxi = max(maxi, x);
        sum += x;
    }

    int low = maxi;
    int high = sum;
    int ans = maxi;

    while(low <= high) {
        int mid = (low + high)/2;
        int subarrays = getSubArraysCount(nums, mid);

        if(subarrays <= k) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return ans;
}

/**
 * Main function to run sample test cases and demonstrate binary search solutions.
 */
int main() {
    //cout<<squareRoot(89);
    //cout<<findNthRoot(3, 8);

    vector<int> v = {4,2,1,3,6};
    cout<<agressiveCows(v, 2);
}