/*

** All questions are from Binary Search **

- Find square root of a number
- Find Nth root of a number
- Koko eating banana
- Minimum days to make m bouquets   
*/

#include<bits/stdc++.h>
using namespace std;


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

int power(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

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

int findTimeToEatBananas(int k, vector<int> &piles) {
    int hours = 0;
    for(int pile : piles){
        int div = pile / k;
        hours += div;
        if(pile % k != 0) hours++;
    }
    return hours;
}

// LC: https://leetcode.com/problems/koko-eating-bananas/
// TC: O(MLogN) -> M is the maximum array element and N is size of array
// SC: O(1)
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

// LC: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// TC: O(MLogN) -> M (difference between max and min element of array), N (size of array)
// SC: O(1)
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

int main() {
    //cout<<squareRoot(89);
    //cout<<findNthRoot(3, 8);
}