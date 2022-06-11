#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ab = 5;
    cout<<"Value of ab: "<<ab<<endl;
    cout<<"Address of ab: "<<&ab<<endl;

    // &used to get the address of a particular variable
    // now it can not just be stored, the datatype of the variablethat stores it also changes the address
    int* add1 = &ab;
    cout<<"Address of ab through variable: "<<add1<<endl;

    // then * used to dereference the variable, that is we can enter an address, then * will extract the 
    // value present at that particular address
    cout<<"Value of variable ab through its address: "<<*add1<<endl;

    // we can also update the value of the original variable i.e. ab through its address
    // as changes are made throug the address and not to a copy, they will be permanent
    *add1 = 10;
    cout<<endl<<"ab now: "<<ab<<endl;
    cout<<"*add1 now: "<<*add1<<endl;
    cout<<"add1 actual value - i.e. address of ab: "<<add1;
    return 1;
}