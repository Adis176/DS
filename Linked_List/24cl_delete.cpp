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

void delete_tail(Node** head)
{
    if(*head == NULL)
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
        while(curr->next->next != (*head))
        {
            curr = curr->next;
        }
        curr->next = curr->next->next;
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

    delete_head(&head1);
    print_list(&head1);

    cout<<"Random checking: ";
    int c1=9;
    Node* h1 = head1;
    while(c1--){
        cout<<h1->val<<" ";
        h1=h1->next;
    }
    cout<<endl;
    
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


    Node* head2 = NULL;
    insert_head(&head2, 3);
    insert_head(&head2, 1);
    insert_head(&head2, 5);
    insert_head(&head2, 7);
    insert_head(&head2, 9);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);
    
    delete_tail(&head2);
    print_list(&head2);

    cout<<"Random checking: ";
    int c2=11;
    Node* h2 = head2;
    while(c2--){
        cout<<h2->val<<" ";
        h2=h2->next;
    }
    cout<<endl;

    delete_tail(&head2);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);

    delete_tail(&head2);
    print_list(&head2);
    cout<<endl;
    return 1;
}
