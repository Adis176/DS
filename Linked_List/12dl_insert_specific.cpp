// doubly linked list insert after first instance of target element

#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node()
    {
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_tail(Node** head, int val){
    Node* n1 = new Node(val);
    if(*head==NULL)
        (*head)=n1;
    else
    {
        Node* curr = *head;
        while(curr->next)
        {
            curr = curr->next;
        }
        curr->next=n1;
        n1->prev = curr;
    }
}

void insert_specific(Node** head, int val, int target)
{
    Node* n1 = new Node(val);
    bool c = false;
    if(*head == NULL) 
    {
        cout<<"No element present\n";
        return;
    }

    Node* curr = *head;
    while(curr)
    {
        if(curr->data==target)
        {
            n1->next=curr->next;
            n1->prev=curr;
            if(curr->next)
                (curr->next)->prev = n1;
            curr->next=n1;
            c=true;
            break;
        }
        curr=curr->next;
    }
    if(!c)
        cout<<"Req target value doesn't exist in list\n";

}

void print_list(Node** head)
{
    Node* curr = *head;
    cout<<"The elements of linked list are: ";
    while(curr)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

int main()
{
    // defining just a head of the linked list, initially NULL
    Node* head1 = NULL;
    insert_specific(&head1, 4, 5);
    insert_tail(&head1, 7);
    print_list(&head1);

    insert_specific(&head1, 9, 7);
    print_list(&head1);

    insert_specific(&head1, 8, 8);
    print_list(&head1);

    insert_specific(&head1, 5, 7);
    print_list(&head1);
    
    insert_specific(&head1, 1, 9);
    print_list(&head1);
    
    // printing with prev to check whether all elements have been connected properly
    Node* h1 = head1;
    while(h1->next)
    {
        h1=h1->next;
    }
    while(h1)
    {
        cout<<h1->data<<" ";
        h1=h1->prev;
    }
    return 1;
}