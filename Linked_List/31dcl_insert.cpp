// Doubly circular linked list - insert at tail & head

#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;

    Node() 
    {
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int dataa)
    {
        this->val = dataa;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_head(Node** head, int val){
    Node* n1 = new Node(val);
    if(*head == NULL)
    {
        *head = n1;
        (*head)->next = *head;
        (*head)->prev = *head;
    }
    else
    {
        ((*head)->prev)->next = n1;
        n1->next = *head;
        n1->prev = (*head)->prev;
        (*head)->prev = n1;
        *head = n1;
    }
}

void insert_tail(Node** head, int val){
    Node* n1 = new Node(val);
    if(*head == NULL)
    {
        *head = n1;
        (*head)->next = *head;
        (*head)->prev = *head;
    }
    else
    {
        (*head)->prev->next = n1;
        n1->next = *head;
        n1->prev = (*head)->prev;
        (*head)->prev = n1;
    }
}

void print_list(Node** head)
{
    Node* h1 = *head;
    cout<<"The list elements are: ";
    while(h1->next!=*head)
    {
        cout<<h1->val<<" ";
        h1=h1->next;
    }
    cout<<h1->val;
    cout<<endl;
}

int main()
{
    Node* head1 = NULL;
    insert_tail(&head1, 3);
    print_list(&head1);

    insert_head(&head1, 1);
    print_list(&head1);

    insert_head(&head1, 5);
    print_list(&head1);

    insert_tail(&head1, 7);
    print_list(&head1);

    insert_head(&head1, 0);
    print_list(&head1);

    insert_tail(&head1, 9);
    print_list(&head1);


    // checking in diff manner, iterating twice over the same list to check circular property
    int c1=17;
    Node* h1 = head1;
    while(c1--)
    {
        cout<<h1->val<<" ";
        h1=h1->next;
    }
    cout<<endl<<endl;

    // iterating in reverse to check both prev and circular property
    int c2=15;
    Node* h2 = head1;
    while(c2--)
    {
        cout<<h2->val<<" ";
        h2=h2->prev;
    }    
    cout<<endl;

    return 1;
}
