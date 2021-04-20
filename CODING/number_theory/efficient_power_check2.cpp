
#include<bits/stdc++.h>
using namespace std;
//
        // Complexity of these algorithms is O(logx(y))
// 
//////  Second Method
bool isPower(int x, long int y) 
{ 
    // The only power of 1 is 1 itself 
    if (x == 1) 
        return (y == 1); 
  
    // Repeatedly comput power of x 
    long int pow = 1; 
    while (pow < y) 
        pow *= x; 
  
    // Check if power of x becomes y 
    return (pow == y); 
} 

//First Method

bool check(int x,long long int y)
{
    int flag=0;
    int count=0;
    while(y)
    {
        if(y%x == 0)
        {}
        else if(y%x==1)
        {
            count++;
        }
        else
        {
            flag=1;
            break;
        }
        y/=x;
    }
    if(flag==1)
    {
        return false;
    }
    else
    {
        if(count==1)
        return true;
        else
        return false;
    }
}

int main()
{
    int x=8;
    long long int y=3423223;
    if(x==1)
    {
        cout<<"Yes"<<endl;
    }
    else if(y==1)
    {
         cout<<"No"<<endl;
    }
    else
    {
        if(check(x,y))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}