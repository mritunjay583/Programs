/*

[ capture clause ] (parameters) -> return-type  
{   
    definition of method   
} 

*/


#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v{3,4,20,23,22,3};
    

    // lambda used in comprator function
    sort(v.begin(),v.end(),[](int x,int y)->bool{return x<y;});
    for(auto x:v)cout<<x<<" ";cout<<endl;
    
    //lambda used in accumulator
    int product=accumulate(v.begin(),v.end(),1,[](int x,int y)->int
    {
        return x*y;
    });
    cout<<product<<endl;
        
    // used with count_if function to get elements of vector 
    //greater than 5
    int N=2;
    int M=2;
    int cnt=count_if(v.begin(),v.end(),[=](int x)->bool
    {
        return x>=N+M;
    });
    cout<<cnt<<endl;

    cnt=count_if(v.begin(),v.end(),[N](int x)
    {
        return x>N;
    });

    cout<<cnt<<endl;

    //making small function and can be defined inside other
    //function
    auto square=[](int x){return x*x;};
    cout<<square(5);
}