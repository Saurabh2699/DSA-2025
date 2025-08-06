/*
This is just a test file
*/

#include<bits/stdc++.h>
using namespace std;

// struct Node {
//     int val;
//     Node *left;
//     Node *right;

//     Node(int val) {
//         this->val = val;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// void preOrder(Node *node) {
//     if(node == NULL) return;

//     cout<<node->val<<" ";
//     preOrder(node->left);
//     preOrder(node->right);
// }

// int main() {
//     Node *node = new Node(1);
//     node->left = new Node(2);
//     node->right = new Node(3);
//     node->left->left = new Node(4);
//     node->left->right = new Node(5);

//     preOrder(node);
//     return 0;
// }

// Function overriding, virtual functions
// class Base {
//     public:
//         virtual void print() = 0; // pure virtual function aka abstract method
        
//         virtual void display() {
//             cout<<"\nBase class display";
//         }
// };

// class Derived : public Base {
//     public:
//         void display() {
//             cout<<"\nDerived class display";
//         }

//         void print() {
//             cout<<"\nOverriding print method in derived class";
//         }
// };


// int main() {
    
//     Base *obj = new Derived();
//     obj->display();  
//     obj->print();
//     return 0;
// }

// void print(int arr[], int len) {
//     for(int i=0; i<len; i++) {
//         cout<<arr[i]<<" ";
//     }
// }

// void modify(int arr[], int len) {
//     for(int i=0; i<len; i++) {
//         arr[i] = i+10;
//     }
// }

// void func(int *a, int *b) {
//     *a = 100;
//     *b = 200;
// }

// void swap(int &a, int &b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// int main() {
//     // int arr[] = {1, 2, 3, 4, 5};
//     // int len = sizeof(arr)/sizeof(arr[0]);

//     // print(arr, len);

//     // modify(arr, len);

//     // printf("\n");

//     // print(arr, len);

//     // return 0;

//     int a = 10;
//     int b = 20;

//     cout<<a<<" "<<b<<endl;

//     swap(a, b);

//     cout<<a<<" "<<b;
// }


// STL - Standard Template Library C++

// Generic function that works with any data type
// template <typename T> T findMaxGeneric(T a, T b) {
//     return a > b ? a : b;
// }

// int findMax(int a, int b) {
//     return a > b ? a : b;
// }

// int findMaxFromArray(int arr[], int n) {
//     if(n <= 0) return 0;

//     int max = arr[0];
//     for(int i=1;i<n;i++) {
//         if(arr[i] > max) {
//             max = arr[i];
//         }
//     }

//     return max;
// }

//int main() {


    // cout<<findMaxGeneric(100, 20)<<endl;
    // cout<<findMaxGeneric(11.45, 9.999)<<endl;
    // cout<<findMaxGeneric('a', 'b')<<endl;

    // int arr[5] = {3,6,1,8,4};
    // cout<<findMaxFromArray(arr, 5);

    // return 0;
//}

int main() {
    
    //vector<int> v({1, 2, 3, 4, 5});
 
    // for(int x: v) cout<<x<<" ";

    // vector<int> v(5, 0);
    // v.push_back(6);
    // v.pop_back();
    // for(int x: v) cout<<x<<" ";

    // 2d vector
    // vector<vector<int>> v(5, vector<int>(10, 1));

    // for(int i=0;i<5;i++) {  
    //     for(int j=0;j<10;j++) {
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //vector<int> v({2, 1, 7, 5, 9});

    //v.resize(3);

    //cout<<v.front()<<endl;
    //cout<<v.back()<<endl;

    // set<int> st({3, 4, 1, 2, 9});

    // // check if a element is present in the set
    // if(st.find(10) != st.end()) {
    //     cout<<"Element present\n";
    // } else {
    //     cout<<"Not present\n";
    // }
    
    // st.insert(-19);

    // for(auto x: st) cout<<x<<" ";

    // cout<<endl;

    // for(auto it = st.rbegin(); it != st.rend(); it++) cout<<*it<<" ";

    map<int, string> mp{{1, "saurabh"}, {8, "luffy"}, {2, "zoro"}};

    cout<<mp.size()<<endl;
    cout<<mp.empty()<<endl;

    mp.insert({-8, "sanji"});

    mp.erase(8);
    
    for(auto it: mp) {
        cout<<it.first<<" -> "<<it.second<<endl;
    }

    return 0;
}