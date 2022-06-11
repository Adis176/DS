/* Initialize LL with Class method
 Singly Linked list
*/

#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    Node* next;
    int data;

    // through this method, whenever we initialize a node without passing any value, by default its next pointer 
    // is set to NULL
    Node()
    {
        this->next = NULL;
    }

    // when we pass an int value during node creation, it will be set as the new node's data value
    // constructor used here 
    Node(int data1)
    {
        this->data = data1;
        this->next = NULL;
    }

    // when we pass an int value and a node during node creation, it will be set as the new node's data value, and
    // the passed node will be set as the new node's next 
    Node(int data1, Node* n1)
    {
        this->data = data1;
        this->next = n1;
    }
};

int main()
{
    Node* n1 = new Node();
    n1->data = 2;

    Node* n2 = new Node();
    n2->data = 4;

    Node* n3 = new Node(6);
    n3->data = 6;

    Node* n4 = new Node(8);

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
    cout<<endl<<endl; 

    Node* n6 = new Node(12);

    // so now the next of the new node n5 will be n6
    Node* n5 = new Node(10, n6);
    n4->next = n5;
    Node* curr2 = n1;
    cout<<"The elements of linked list are: ";
    while(curr2)
    {
        cout<<curr2->data<<" ";
        curr2 = curr2->next;
    }
    return 1;
}