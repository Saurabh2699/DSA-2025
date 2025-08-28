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

/*

    1
    01
    101
    0101
    10101

*/

void pattern3(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            if((i+j) % 2 == 0) cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
}

/*
    1          1
    12        21
    123      321
    1234    4321
    12345  54321
    123456654321
*/

void pattern4(int n) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cout<<j;
        }
        
        int spaces = 2 * (n-i);
        for(int j=0;j<spaces;j++) {
            cout<<" ";
        }

        for(int j=i;j>=1;j--) {
            cout<<j;
        }

        cout<<endl;
    }
}

/*
    A
    AB
    ABC
    ABCD
    ABCDE
*/
void pattern5(int n) {
    for(int i=0;i<n;i++) {
        char ch = 'A';
        for(int j=0;j<=i;j++) {
            cout<<ch;
            ch += 1;
        }
        cout<<endl;
    }
}

/*
    ABCDE
    ABCD
    ABC
    AB
    A
*/
void pattern6(int n) {
    for(int i=n;i>0;i--) {
        char ch = 'A';
        for(int j=0;j<i;j++) {
            cout<<ch;
            ch += 1;
        }
        cout<<endl;
    }
}

/*
    A
    BB
    CCC
    DDDD
    EEEEE
*/

void pattern7(int n) {
    for(int i=0;i<n;i++) {
        char ch = 'A' + i;
        for(int j=0;j<=i;j++) {
            cout<<ch;
        }
        cout<<endl;
    }
}

/*
    A    
   ABA   
  ABCBA  
 ABCDCBA 
ABCDEDCBA

*/
void pattern8(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            cout<<" ";
        }

        int breakPoint = ((2*i)+1)/2;
        char ch = 'A';
        for(int j=1;j<=(2*i)+1;j++) {
            cout<<ch;
            if(j <= breakPoint) ch++;
            else ch--;
        }

        for(int j=0;j<n-i-1;j++) {
            cout<<" ";
        }  

        cout<<endl;
    }
}

/*
    E
    DE
    CDE
    BCDE
    ABCDE
*/
void pattern9(int n) {
    for(int i=0;i<n;i++) {
        char ch = 'A' + (n-i-1);
        for(int j=0;j<=i;j++) {
            cout<<ch;
            ch++;
        }
        cout<<endl;
    }
}

/*

    **********
    ****  ****
    ***    ***
    **      **
    *        *
    *        *
    **      **
    ***    ***
    ****  ****
    **********

*/
void pattern10(int n) {
    for(int i=0;i<2*n;i++) {
        if(i < n) {
            for(int j=0;j<(n-i);j++) cout<<"*";
            for(int j=0;j<2*i;j++) cout<<" ";
            for(int j=0;j<(n-i);j++) cout<<"*";
            cout<<endl;
        } else {    
            for(int j=0;j<=(i-n);j++) cout<<"*";
            for(int j=0;j<((2*n)-2*((i-n)+1));j++) cout<<" ";
            for(int j=0;j<=(i-n);j++) cout<<"*";
            cout<<endl;
        }       
    }
}

/*
    *        *
    **      **
    ***    ***
    ****  ****
    **********
    ****  ****
    ***    ***
    **      **
    *        *
*/

void pattern11(int n) {
    for(int i=1;i<2*n;i++) {
        if(i <= n) {
            int stars = 2*i;
            int spaces = 2*n - stars;
            for(int j=1;j<=(stars/2);j++) cout<<"*";
            for(int j=1;j<=spaces;j++) cout<<" ";
            for(int j=1;j<=(stars/2);j++) cout<<"*";
            cout<<endl;
        } else {
            int stars = 2*n - 2*(i-n);
            int spaces = 2*n - stars;
            for(int j=1;j<=(stars/2);j++) cout<<"*";
            for(int j=1;j<=spaces;j++) cout<<" ";
            for(int j=1;j<=(stars/2);j++) cout<<"*";
            cout<<endl;
        }
    }
}

/*
    *****
    *   *
    *   *
    *   *
    *****
*/
void pattern12(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i == 0 || i == n-1 || j == 0 || j == n-1) cout<<"*";
            else cout<<" ";
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
    // pattern2(5);
    // pattern3(5);
    // pattern4(10);
    // pattern5(5);
    // pattern6(5);
    // pattern7(5);
    // pattern8(5);
    // pattern9(5);
    // pattern10(5);
    // pattern11(5);
    // pattern12(5);

    return 0;
}
