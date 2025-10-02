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
* ------------------------------------------------------------
* Sources & Problem Links:
*   1. Square Root: https://leetcode.com/problems/sqrtx/
*   2. Nth Root: https://www.geeksforgeeks.org/find-nth-root-of-a-number/
*   3. Koko Eating Bananas: https://leetcode.com/problems/koko-eating-bananas/
*   4. Minimum Days to Make Bouquets: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
*   5. Smallest Divisor: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
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
 * Main function to run sample test cases and demonstrate binary search solutions.
 */
int main() {
    //cout<<squareRoot(89);
    cout<<findNthRoot(3, 8);
}