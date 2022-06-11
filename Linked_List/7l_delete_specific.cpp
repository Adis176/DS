/* 
Delete element at specific position
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

void delete_specific(Node** head, int val)
{
    if(*head==NULL)
    {
        cout<<"Can't delete as head is NULL"<<endl;
    }
    else if( (*head)->data==val)
    {
        *head=(*head)->next;
    }
    else if((*head)->next==NULL)
    {
        if((*head)->data == val)
        {
            *head=NULL;
        }
        else
        {
            cout<<endl<<"The req value doesn't exist"<<endl;
        }
    }
    else
    {
        Node* c = *head;
        while(c->next)
        {
            if(( (c->next)->data == val))
                break;
            c=c->next;
        }
        if(!c->next)
        {
            cout<<"Req value does not exist!"<<endl;
        }
        else
        {
            c->next=c->next->next;
        }
    }
}

void print_list(Node* head)
{
    Node* curr1 = head;
    cout<<"The elements of linked list are: ";
    while(curr1)
    {
        cout<<curr1->data<<" ";
        curr1 = curr1->next;
    }
    cout<<endl<<endl;
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
    print_list(head);
    delete_specific(&head, 5);
    print_list(head);

    delete_specific(&head, 6);
    print_list(head);

    delete_specific(&head, 2);
    print_list(head);

    delete_specific(&head, 1);
    print_list(head);

    delete_specific(&head, 3);
    print_list(head);

    delete_specific(&head, 4);
    print_list(head);

    delete_specific(&head, 4);
    print_list(head);

    return 1;
}