//  https://www.tutorialspoint.com/cplusplus/cpp_references.htm

#include<bits/stdc++.h>

using namespace std;

void change1(vector<int> a1)
{
    for(int i=0; i<a1.size(); i++)
        a1[i] *= 2;
}

void change2(vector<int>& a1)
{
    for(int i=0; i<a1.size(); i++)
        a1[i] *= 3;
}

int main()
{
    // REFERENCE is just another name for an already existing variable

    // we cant have NULL references 
    // once we initialize a reference, w ecant change it to point to another object

    // a reference must be initialized when it is created, while we can just create a pointer, then initialize it
    // afterwards

    int a = 7;
    int& r = a;
    cout<<"Value of a = "<<a<<endl;
    cout<<"Value of its reference = "<<r<<endl;

    // vector has to be passed through reference as a parameter, to make the changes permanent
    vector<int> a1 = {1,3,5,7};
    cout<<"Elements of a1: ";
    for(int i=0; i<a1.size(); i++)
        cout<<a1[i]<<" ";
    cout<<endl<<endl;

    change1(a1);
    cout<<"Elements of a1: ";
    for(int i=0; i<a1.size(); i++)
        cout<<a1[i]<<" ";
    cout<<endl<<endl;

    change2(a1);
    cout<<"Elements of a1: ";
    for(int i=0; i<a1.size(); i++)
        cout<<a1[i]<<" ";
    cout<<endl<<endl;
    return 1;
}