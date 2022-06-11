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

void insert_tail(Node** head, int val){
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
    insert_head(&head1, 3);
    print_list(&head1);

    insert_head(&head1, 1);
    print_list(&head1);

    insert_head(&head1, 5);
    print_list(&head1);

    insert_head(&head1, 7);
    print_list(&head1);

    insert_head(&head1, 9);
    print_list(&head1);


    // checking in diff manner, iterating twice over the same list to check circular property
    int c1=11;
    Node* h1 = head1;
    while(c1--)
    {
        cout<<h1->val<<" ";
        h1=h1->next;
    }
    cout<<endl<<endl;

    Node* head2 = NULL;
    insert_tail(&head2, 3);
    print_list(&head2);

    insert_tail(&head2, 1);
    print_list(&head2);

    insert_tail(&head2, 5);
    print_list(&head2);

    insert_tail(&head2, 7);
    print_list(&head2);

    insert_tail(&head2, 9);
    print_list(&head2);


    // checking in diff manner, iterating twice over the same list to check circular property
    int c2=16;
    Node* h2 = head2;
    while(c2--)
    {
        cout<<h2->val<<" ";
        h2=h2->next;
    }
    cout<<endl;

    return 1;
}
