/* Initialize LL with Class method
 Singly Linked list
*/

#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    Node* next;
    int data;

    Node()
    {
        this->next = NULL;
    }

    Node(int data1)
    {
        this->data = data1;
        this->next = NULL;
    }

    Node(int data1, Node* n1)
    {
        this->data = data1;
        this->next = n1;
    }
};

///             FULL ARTICLE @ https://stackoverflow.com/questions/20846904/in-c-what-is-this-for-node-head



// here Node* &head denotes reference to a pointer, i.e. reference to the node pointer head
// hence changes made to head will be reflected everywhere

// one alternative to this is to use pointer to pointer i.e. Node** head 
// but then we also have to write like c2->next = *head. As we assign a node(i.e. pointer to node object as 
// next to c1, and head is a pointer to pointer, so we dereference it once)
void insert_head(Node* &head, int value)
{
    Node* c1 = new Node(value);
    if(head!=NULL) 
        c1->next = head;
    head = c1;
}

void insert_tail(Node* &head, int value)
{
    Node* c1 = new Node(value);

    if(head==NULL) 
        head = c1;
    else
    {
        Node* curr = head;
        while(curr->next!=NULL)
            curr = curr->next;
        curr->next = c1;
    }   
}

void print_list(Node* &head)
{
    Node* curr = head;
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
    print_list(head1);

    // pass the value which we want to be added as the new head
    insert_head(head1, -1);
    print_list(head1);
    insert_head(head1, 3);
    insert_head(head1, -5);
    print_list(head1);



    Node* head2 = NULL;
    print_list(head2);

    // pass the value which we want to be added as the new head, at the end
    insert_tail(head2, -6);
    print_list(head2);
    insert_tail(head2, 4);
    insert_tail(head2, -8);
    print_list(head2);
    return 1;
}