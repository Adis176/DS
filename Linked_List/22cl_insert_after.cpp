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

void insert_after(Node** head, int val, int target) 
{
    // insert the val after the node with value target
    Node* n1 = new Node(val);
    if(*head == NULL)
    {
        cout<<"No node present, can not insert\n";
        return;
    }
    else 
    {
        bool c = true;
        Node* curr = *head;
        while(curr->next!= (*head))
        {
            if(curr->val == target)
            {
                c = false;
                n1->next = curr->next;
                curr->next = n1;
                break;
            }
            curr = curr->next;
        }

        // to prevent repeat of insertion, as if we have inserted once in the upper loop, we check 
        // whether c = true or not
        if(curr->val == target && c)
        {
            c = false;
            n1->next = curr->next;
            curr->next = n1;
        }
        if(c)
            cout<<"No such value exists\n";
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

int main()
{

    Node* head1 = NULL;
    insert_after(&head1, 7, 7);
    insert_tail(&head1, 1);
    print_list(&head1);

    insert_after(&head1, 7, 1);
    print_list(&head1);

    insert_after(&head1, 3, 7);
    print_list(&head1);

    insert_after(&head1, 0, 6);
    print_list(&head1);

    insert_after(&head1, 0, 1);
    print_list(&head1);

    insert_after(&head1, 2, 3);
    print_list(&head1);

    cout<<endl;
    return 1;
}
