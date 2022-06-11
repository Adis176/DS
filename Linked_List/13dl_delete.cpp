// doubly linked list delete head, tail

#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

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

void delete_head(Node** head)
{
    if(*head == NULL) {
        cout<<endl<<"Can not delete NULL node"<<endl;
    }
    else if((*head)->next == NULL) {
        (*head)=NULL;
    }
    else
    {
        (*head) = ((*head)->next);
        (*head)->prev = NULL;
    }
}

void delete_tail(Node **head)
{
    if(*head == NULL) {
        cout<<endl<<"Can not delete NULL node"<<endl;
    }
    else if((*head)->next == NULL) {
        (*head)=NULL;
    }
    else
    {
        Node* curr = (*head);
        while(curr->next->next)
        {
            curr = curr->next;
        }
        curr->next=NULL;
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
    // pass the value which we want to be added as the new head, at the end
    insert_tail(&head1, 0);
    insert_tail(&head1, 2);
    insert_tail(&head1, 4);
    insert_tail(&head1, 6);
    insert_tail(&head1, 9);
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


    cout<<endl<<endl;
    Node* head2 = NULL;
    insert_tail(&head2, -2);
    insert_tail(&head2, 1);
    insert_tail(&head2, 3);
    insert_tail(&head2, 5);
    insert_tail(&head2, 8);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);

    return 1;
}