// Doubly circular linked list - insert before user defined node

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

void insert_before(Node** head, int val, int target){
    Node* n1 = new Node(val);
    if(*head == NULL)
    {
        cout<<"No node present, cannot insert\n";
        return;
    }
    else
    {
        if((*head)->val == target)
        {
            insert_head(head, val);
        }
        else
        {
            Node* h1 = (*head)->next;
            while(h1->next->val != target && h1!=(*head))
            {
                h1=h1->next;
            }
            if(h1->next->val != target)
            {
                cout<<"Target not found\n";
                return;
            }
            h1->next->prev = n1;
            n1->next = h1->next;
            n1->prev = h1;
            h1->next= n1;
        }
        
    }
}

void print_list(Node** head)
{
    Node* h1 = *head;
    cout<<"The list elements are: ";
    if(!(*head)) return;
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
    insert_before(&head1, 1, 1);
    print_list(&head1);

    insert_head(&head1, 5);
    print_list(&head1);

    insert_before(&head1, 1, 5);
    print_list(&head1);

    insert_before(&head1, 7, 5);
    print_list(&head1);

    insert_before(&head1, 4, 0);
    print_list(&head1);

    insert_head(&head1, 0);
    print_list(&head1);

    insert_before(&head1, 9, 0);
    print_list(&head1);


    // iterating in reverse to check both prev and circular property
    int c2=13;
    Node* h2 = head1;
    while(c2--)
    {
        cout<<h2->val<<" ";
        h2=h2->prev;
    }    
    cout<<endl;

    return 1;
}
