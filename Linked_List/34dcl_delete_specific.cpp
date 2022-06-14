// Doubly circular linked list - delete a specific position

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

void delete_head(Node** head)
{
    if((*head) == NULL)
    {
        cout<<"\nNo node present, cannot delete";
        return;
    }
    else if( (*head)->next == (*head))
    {
        *head = NULL;
        return;
    }
    else
    {
        Node* c1 = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        (*head)->prev->next = (*head)->next;
        *head = c1;
    }
}

void delete_specific(Node** head, int target)
{
    if(*head == NULL)
    {
        cout<<"No node present, cannot delete\n";
        return;
    }
    else if((*head)->next == (*head))
    {
        if((*head)->val == target)
        {
            *head = NULL;
        }
        else
        {
            cout<<"Target not found\n";
        }
        return;
    }
    else
    {
        Node* h1 = (*head);
        if(h1->val==target)
        {
            delete_head(head);
            return;
        }
        while( (h1->next != (*head)) && h1->val!=target)
        {
            h1=h1->next;
        }
        if(h1->val!=target)
        {
            cout<<"Target not found\n";
        }
        else
        {
            h1->prev->next = h1->next;
            h1->next->prev = h1->prev;
        }
    }
}

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

void print_list(Node** head)
{
    Node* h1 = *head;
    cout<<"The list elements are: ";
    if(!(*head)) 
        return;
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

    insert_head(&head1, 8);
    insert_head(&head1, 6);
    insert_head(&head1, 4);
    insert_head(&head1, 2);
    insert_head(&head1, 0);
    insert_head(&head1, 1);
    print_list(&head1);

    delete_specific(&head1, 9);
    print_list(&head1);

    delete_specific(&head1, 1);
    print_list(&head1);

    // iterating in reverse to check both prev and circular property
    int c2=13;
    Node* h2 = head1;
    cout<<"Reverse iteration: ";
    while(c2--)
    {
        cout<<h2->val<<" ";
        h2=h2->prev;
    }    
    cout<<endl;

    delete_specific(&head1, 8);
    print_list(&head1);

    delete_specific(&head1, 6);
    print_list(&head1);

    delete_specific(&head1, 4);
    print_list(&head1);

    delete_specific(&head1, 7);
    print_list(&head1);

    delete_specific(&head1, 0);
    print_list(&head1);

    delete_specific(&head1, 0);
    print_list(&head1);

    delete_specific(&head1, 2);
    print_list(&head1);

    delete_specific(&head1, 2);
    print_list(&head1);

    

    return 1;
}
