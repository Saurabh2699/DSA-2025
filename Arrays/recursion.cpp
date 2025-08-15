#include<bits/stdc++.h>
using namespace std;

void printAllDivisors(int n) {
    vector<int> v;
    
    for(int i=1;i*i<=n;i++) {
        if(n%i == 0) {
          v.push_back(i);
            if(n/i != i) {
                v.push_back(n/i);
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    for(auto x: v) cout<<x<<" ";
}

void printNto1(int n) {
    if(n == 0) return;

    cout<<n<<" ";

    printNto1(n-1);
}

int sumOfN(int n) {
    if(n == 0) return 0;

    return n + sumOfN(n-1);
}

void reverseArray(int arr[], int n, int index) {
   if(index == n/2) return;
   
   //swap(arr[index], arr[n-index-1]);

   int temp = arr[index];
   arr[index] = arr[n-index-1];
   arr[n-index-1] = temp;

   reverseArray(arr, n, index+1);
}

void reverseArrayIterative(int arr[], int n) {
    int i=0, j=n-1;

    while(i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

bool checkPallindrome(string s, int i) {
    int len = s.length();

    if(i >= len/2) return true;

    if(s[i] != s[len-i-1]) return false;

    return checkPallindrome(s, i+1);
}
 
int main() {
    //printAllDivisors(36);
    //printNto1(10);
    //cout<<sumOfN(10);

    //int arr[] = {1, 2, 3, 4, 5};
    //reverseArray(arr, 5, 0);
    //reverseArrayIterative(arr, 5);

    //for(int i=0;i<5;i++) cout<<arr[i]<<" ";

    cout<<checkPallindrome("abcbaa", 0);
}   