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

void delete_before(Node** head, int val){
    if(*head == NULL)
    {
        cout<<"No element in list, hence can't delete\n";
    }
    else if( (*head)->data==val)
    {
        cout<<"Can't delete something before head\n";
    }
    else if( (*head)->next && (*head)->next->data==val){
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
    else
    {
        bool c = false;
        Node* curr = *head;
        while(curr->next)
        {
            if(curr->next->data == val)
            {
                c = true;
                curr->prev->next=curr->next;
                curr->next->prev = curr->prev;
                break;
            }
            curr=curr->next;
        }
        if(!c)
            cout<<"Node with req value doesn't exist"<<endl;
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
    insert_tail(&head1, 0);
    insert_tail(&head1, 2);
    insert_tail(&head1, 4);
    insert_tail(&head1, 6);
    insert_tail(&head1, 9);
    print_list(&head1);

    delete_before(&head1, 0);
    print_list(&head1);

    delete_before(&head1, 2);
    print_list(&head1);

    delete_before(&head1, 9);
    print_list(&head1);

    delete_before(&head1, 4);
    print_list(&head1);

    delete_before(&head1, 4);
    print_list(&head1);

    delete_before(&head1, 9);
    print_list(&head1);

    delete_before(&head1, 9);
    print_list(&head1);
    return 1;
}