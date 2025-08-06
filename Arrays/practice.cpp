#include<bits/stdc++.h>
using namespace std;

// TC: O(log10^N + 1)
// SC: O(1)
// Source: TUF
int countOfDigits(int n) {
    int num = n;
    int digits = 0;

    if(n < 0) {
        num = -1 * n;
    }

    while(num > 0) {
        digits++;
        num = num/10;
    }

    return digits;
}

// TC: O(1)
// SC: O(1)
// Source: TUF
int countOfDigitsOptimized(int n) {
    return (int)(log10(n) + 1);
}

int main() {
    
    cout<<countOfDigits(211000)<<endl;
    cout<<countOfDigitsOptimized(211000);

    return 0;
}