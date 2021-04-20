#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[]={5,7,12,1,5,3,9,3,0};
    set<int> se;
    for(auto x:a)se.insert(x);
    for(auto x:se)cout<<x<<" ";cout<<endl;
    int f1=10;
    auto x=se.lower_bound(f1);
    if(x==se.end())
        cout<<"Not found : all elements are less than "<<f1<<endl;
    else
        cout<<*x<<endl;

    int f2=10;
    auto y=se.upper_bound(f2);
    if(y==se.end())
        cout<<"Not found : all elements are less than "<<f1<<endl;
    else
        cout<<*y<<endl; 
}


//se.lower_bound(x);
// this method returns iterator pointing to the element >=x;
// if all the elements in set are less than x
// then this method returns iterator pointing to se.end();



// se.upper_bound(x);
// is same as lower bound but it return iterator pointing to the 
// element >x;