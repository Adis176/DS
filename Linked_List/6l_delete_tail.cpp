/* 
Delete element at tail
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

void delete_tail(Node** head)
{
    if(*head==NULL)
    {
        cout<<"Can't delete as head is NULL"<<endl;
    }
    else if((*head)->next==NULL)
    {
        *head=NULL;
    }
    else
    {
        Node* c = *head;
        while(c->next->next != NULL)
        {
            c=c->next;
        }
        c->next = NULL;
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
    delete_tail(&head);
    print_list(head);

    delete_tail(&head);
    print_list(head);

    delete_tail(&head);
    print_list(head);

    delete_tail(&head);
    print_list(head);

    delete_tail(&head);
    print_list(head);

    delete_tail(&head);
    print_list(head);

    return 1;
}