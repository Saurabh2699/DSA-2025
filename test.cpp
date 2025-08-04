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

void print(int arr[], int len) {
    for(int i=0; i<len; i++) {
        cout<<arr[i]<<" ";
    }
}

void modify(int arr[], int len) {
    for(int i=0; i<len; i++) {
        arr[i] = i+10;
    }
}

void func(int *a, int *b) {
    *a = 100;
    *b = 200;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    // int arr[] = {1, 2, 3, 4, 5};
    // int len = sizeof(arr)/sizeof(arr[0]);

    // print(arr, len);

    // modify(arr, len);

    // printf("\n");

    // print(arr, len);

    // return 0;

    int a = 10;
    int b = 20;

    cout<<a<<" "<<b<<endl;

    swap(a, b);

    cout<<a<<" "<<b;
}
