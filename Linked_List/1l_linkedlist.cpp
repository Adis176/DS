// singly linked list 

// 1. what is Node* head, why do we write Node* head and not just Node head ?
// 2. why do we use pointer to pointer ?

// 1. as Node* head will be a pointer to a node object
// we can dereference this head with -> to access its elements, and even change them
// 2. but when we need to make changes to the head pointer itself, we need to pass its address 
// i.e. we pass address through pointer (of a pointer) hence we use Node** n1

// full article at https://stackoverflow.com/questions/55654934/what-is-the-difference-between-node-head-versus-node-head


// Node object has 2 properties, a variable that is named data, 
// that stores int value, and a next pointer that stores the address of the next node object

#include<bits/stdc++.h>

using namespace std;

struct Node{
    Node* next;
    int data;
};

int main()
{
    Node* n1 = new Node();
    n1->data = 1;

    Node* n2 = new Node();
    n2->data = 3;

    Node* n3 = new Node();
    n3->data = 7;

    Node* n4 = new Node();
    n4->data = 5;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Node* curr = n1;
    cout<<"The elements of linked list are: ";
    while(curr)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    return 1;
}