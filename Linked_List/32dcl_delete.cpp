// Doubly circular linked list - delete tail & head

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

void delete_tail(Node** head)
{
    if( (*head) == NULL)
    {
        cout<<"\nNo node present, cannot delete";
        return;
    }
    else if( (*head)->next == (*head))
    {
        *head = NULL;
    }
    else
    {
        (*head)->prev->prev->next = (*head);
        (*head)->prev = (*head)->prev->prev;
    }
}

void print_list(Node** head)
{
    Node* h1 = *head;
    if(!(*head)) return;
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
    insert_head(&head1, 3);
    insert_head(&head1, 1);
    insert_head(&head1, 5);
    insert_head(&head1, 7);
    insert_head(&head1, 0);
    insert_head(&head1, 9);
    print_list(&head1);

    delete_head(&head1);
    print_list(&head1);

    delete_head(&head1);
    print_list(&head1);

    delete_head(&head1);
    print_list(&head1);

    delete_head(&head1);
    print_list(&head1);

    delete_head(&head1);
    print_list(&head1);

    delete_head(&head1);
    print_list(&head1);

    delete_head(&head1);
    print_list(&head1);

    delete_head(&head1);
    print_list(&head1);
    // iterating in reverse to check both prev and circular property
    int c1=15;
    cout<<endl<<"Reverse iteration: ";
    Node* h1 = head1;
    while(c1-- && h1)
    {
        cout<<h1->val<<" ";
        h1=h1->prev;
    }    

    Node* head2 = NULL;
    insert_head(&head2, 2);
    insert_head(&head2, 8);
    insert_head(&head2, 6);
    insert_head(&head2, 4);
    insert_head(&head2, 0);
    insert_head(&head2, 5);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);

    delete_head(&head2);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);

    delete_tail(&head1);
    print_list(&head1);

    delete_tail(&head2);
    print_list(&head2);
    // iterating in reverse to check both prev and circular property
    int c2=15;
    cout<<endl<<"Reverse iteration: ";
    Node* h2 = head2;
    while(c2-- && h2)
    {
        cout<<h2->val<<" ";
        h2=h2->prev;
    }
    cout<<endl;
    return 1;
}
