#include<bits/stdc++.h>
using namespace std;

// PS: Count digits
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

// PS: Count Digits
// TC: O(1)
// SC: O(1)
// Source: TUF
int countOfDigitsOptimized(int n) {
    return (int)(log10(n) + 1);
}

// PS: Reverse number
// TC: O(log10^N + 1)
// SC: O(1)
// Source: TUF
int reverseNumber(int n) {
    int rev_num = 0;
    int num = n;

    while(num > 0) {
        int rem = num % 10;
        rev_num = rev_num * 10 + rem;
        num = num/10;
    }

    return rev_num;
}

// PS: Check if number is palindrome
// TC: O(log10^N + 1)
// SC: O(1)
// Source: TUF
bool isPalindrome(int n) {
    return reverseNumber(n) == n;
}

// PS: GCD of 2 numbers
// TC: O(min(N1, N2))
// SC: O(1)
// Source: TUF
int findGCD(int a, int b) {
    int result = min(a, b);

    while(result > 0) {
        if((a % result == 0) && (b % result == 0)) {
            break;
        }

        result--;
    }

    return result;
}

// PS: GCD of 2 numbers
// TC: O(log(min(N1, N2)))
// SC: O(1)
// Source: TUF
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Triangle Pattern
/*
        *
      * * *
    * * * * *
  * * * * * * *

*/
void pattern1(int n) {
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<2*n;j++) {
            int j1 = n - i - 1;
            int j2 = n + i - 1;

            if(j >= j1 && j <= j2) {
                cout<<"*";
            } else {
                cout<<" ";
            }
        }
        cout<<"\n";
    }
}

// Inverted Triangle Pattern
/*
  * * * * * * *
    * * * * *
      * * *
        *
*/
void invertPattern1(int n) {
    
    for(int i=n-1;i>=0;i--) {
        for(int j=0;j<2*n;j++) {
            int j1 = n - i - 1;
            int j2 = n + i - 1;

            if(j >= j1 && j <= j2) {
                cout<<"*";
            } else {
                cout<<" ";
            }
        }
        cout<<"\n";
    }
}

// Diamond Pattern
/*
        *
      * * *
    * * * * *
  * * * * * * *
   * * * * * * *
    * * * * *
      * * *
        *
*/
void printDiamond(int n) {
    pattern1(n);
    invertPattern1(n);
}

/*

*
**
***
****
*****
****
***
**
*

*/
void pattern2(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=n-1;i>0;i--) {
        for(int j=i;j>0;j--) {
            cout<<"*";
        }
        cout<<endl;
    }
}


int main() {
    
    //cout<<countOfDigits(211000)<<endl;
    //cout<<countOfDigitsOptimized(211000);

    // cout<<reverseNumber(1002345)<<endl;
    // cout<<reverseNumber(76567575)<<endl;
    // cout<<reverseNumber(54312);

    // cout<<isPalindrome(1234)<<endl;
    // cout<<isPalindrome(243423)<<endl;
    // cout<<isPalindrome(441144)<<endl;
    // cout<<isPalindrome(111111);

    // cout<<gcd(20, 28)<<endl;
    // cout<<gcd(20, 15)<<endl;
    // cout<<gcd(13, 17);

    // pattern1(6);
    // invertPattern1(6);
    // printDiamond(6);

    pattern2(5);

    return 0;
}