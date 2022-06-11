// check if palindrome or not

// we will reverse the second half, then compare both halves

#include<bits/stdc++.h>

using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode()
    {
        this->next = NULL;
    }

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_tail(ListNode** head, int val){
    ListNode* n1 = new ListNode(val);
    if(*head==NULL)
        (*head)=n1;
    else
    {
        ListNode* curr = *head;
        while(curr->next)
        {
            curr = curr->next;
        }
        curr->next=n1;
    }
}

void print_list(ListNode** head)
{
    ListNode* curr = *head;
    cout<<"The elements of linked list are: ";
    while(curr)
    {
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
}



bool isPalindrome(ListNode* head) 
{
        if(!(head->next))
            return true;
        ListNode *s=head, *f=head;
        while(f)
        {
            if(f->next)
                f=f->next;
            else
                break;
            s=s->next;
            if(f->next)
                f=f->next;
            else
                break;
            
        }
        
        ListNode* s1 = s, *d1=NULL;
        while(s1)
        {
            ListNode* d2 = s1->next;
           
            s1->next=d1;
            d1=s1;
            s1=d2;
        }
        print_list(&d1);

        ListNode* a2 = head;
        while(d1)
        {
            if(d1->val!=a2->val)
                return false;
            d1=d1->next;
            a2=a2->next;
        }
        return true;
}

int main()
{
    ListNode* head2 = NULL;

    // pass the value which we want to be added as the new head, at the end
    insert_tail(&head2, 1);
    insert_tail(&head2, 2);
    insert_tail(&head2, 3);
    insert_tail(&head2, 3);
    insert_tail(&head2, 2);
    insert_tail(&head2, 1);
    print_list(&head2);

    if(isPalindrome(head2))
        cout<<"Yes";
    else
        cout<<"No";
    return 1;
}