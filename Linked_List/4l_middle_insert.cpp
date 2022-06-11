/* Insert at middle of linked list 
 If n is even, then insert the new node after the (n/2)th node, else insert the new node after the (n+1)/2th node.
 */
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void middle1(Node** head, int val)
{
    Node* insrt = new Node(val);
    if(*head==NULL) 
    {
        *head = insrt;
        return;
    }
    int len=0;
    Node* curr = *head;
    while(curr)
    {
        curr = curr->next;
        len++;
    }

    curr = *head;
    int mid = (len+1)/2;
    while(mid-- > 1)
    {
        curr = curr->next;
    }
    insrt->next = curr->next;
    curr->next = insrt;
}

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;


    Node* head = n1;
    Node* curr1 = head;
    cout<<"The elements of linked list were: ";
    while(curr1)
    {
        cout<<curr1->data<<" ";
        curr1 = curr1->next;
    }
    cout<<endl<<endl;

    middle1(&head, 0);
    Node* curr2 = head;
    cout<<"The elements of linked list now are: ";
    while(curr2)
    {
        cout<<curr2->data<<" ";
        curr2 = curr2->next;
    }
}