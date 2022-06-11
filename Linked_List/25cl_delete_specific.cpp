#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next;

    Node() {this->next = NULL;}

    Node(int dataa)
    {
        this->val = dataa;
    }
};

void insert_head(Node** head, int val){
    Node* n1 = new Node(val);
    if(*head == NULL)
    {
        *head = n1;
        (*head)->next = *head;
    }
    else
    {
        Node* curr = *head;
        while(curr->next!=(*head)){
            curr = curr->next;
        }
        curr->next = n1;
        n1->next = *head;
        *head = n1;
    }
}

void delete_head(Node** head)
{
    if( !(*head))
    {
        cout<<"Can not delete as no node present\n";
        return; 
    }
    else if((*head)->next == (*head))
    {
        (*head) = NULL;
        return;
    }
    else
    {
        Node* curr = (*head);
        while(curr->next != (*head))
        {
            curr = curr->next;
        }
        (*head) = curr->next->next;
        curr->next = curr->next->next;
    }
}

void delete_specific(Node** head, int target){
    if(*head == NULL)
    {
        cout<<"No elements in linked list\n";
        return;
    }
    else if( (*head)->next == (*head)){
        if((*head)->val == target)
        {
            (*head)=NULL;
        }
        else
        {
            cout<<"No such value found\n";
        }
    }
    else if( (*head)->val == target)
    {
        delete_head(head);
    }
    else
    {
        bool c = true;
        Node* curr = (*head);
        while(curr->next != (*head))
        {
            if(curr->next->val == target)
            {
                curr->next = curr->next->next;
                c = false;
                break;
            }
            curr = curr->next;
        }
        if(curr->next->val == target)
        {
            curr->next = curr->next->next;
            c = false;
        }
        if(c)
            cout<<"No such value exists\n";
    }
}

void print_list(Node** head)
{
    if(!(*head)) {cout<<"Empty List\n"; return;}
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
    insert_head(&head1, 3);
    insert_head(&head1, 1);
    insert_head(&head1, 5);
    insert_head(&head1, 7);
    insert_head(&head1, 9);
    print_list(&head1);

    delete_specific(&head1, 9);
    print_list(&head1);

    cout<<"Random checking: ";
    int c1=9;
    Node* h1 = head1;
    while(c1--){
        cout<<h1->val<<" ";
        h1=h1->next;
    }
    cout<<endl;

    delete_specific(&head1, 9);
    print_list(&head1);

    delete_specific(&head1, 3);
    print_list(&head1);

    delete_specific(&head1, 3);
    print_list(&head1);

    delete_specific(&head1, 7);
    print_list(&head1);

    delete_specific(&head1, 5);
    print_list(&head1);

    delete_specific(&head1, 5);
    print_list(&head1);

    delete_specific(&head1, 1);
    print_list(&head1);

    delete_specific(&head1, 5);
    print_list(&head1);
    cout<<endl;
    return 1;
}
