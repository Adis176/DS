// doubly linked list insert head, tail

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

void insert_head(Node** head, int val){
    Node* n1 = new Node(val);
    if(*head==NULL)
        (*head)=n1;
    else
    {
        n1->next = *head;
        (*head)->prev = n1;
        *head = n1;
    }
}

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
    print_list(& head1);

    // pass the value which we want to be added as the new head
    insert_head(&head1, -1);
    print_list(&head1);

    insert_head(&head1, 3);
    print_list(&head1);

    insert_head(&head1, -5);
    print_list(&head1);



    Node* head2 = NULL;
    cout<<endl;
    print_list(&head2);

    // pass the value which we want to be added as the new head, at the end
    insert_tail(&head2, -6);
    print_list(&head2);

    insert_tail(&head2, 4);
    print_list(&head2);

    insert_tail(&head2, -8);
    print_list(&head2);

    // iterating in reverse, to check prev 
    cout<<endl<<"Reverse iteration: ";
    Node* curr3 = head2;
    while(curr3->next != NULL)
    {
        curr3 = curr3->next;
    }
    while(curr3 != NULL)
    {
        cout<<curr3->data<<" ";
        curr3=curr3->prev;
    }
    return 1;
}