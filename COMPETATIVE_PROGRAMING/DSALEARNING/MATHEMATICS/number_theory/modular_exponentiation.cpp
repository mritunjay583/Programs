// power(a,b)%c=?

#include<bits/stdc++.h>
using namespace std;

/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(int x, int y, int p)  
{  
    int res = 1;     // Initialize result  
    x = x % p; // Update x if it is more than or  
                // equal to p  

    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
            
        x = (x*x) % p;
        // y must be even now  
        y = y>>1; // y = y/2    
    }  
    return res;  
}  

int modExp(int a,int b,int c)
{
    if(a==0)
        return 0;
    if(b==0)
        return 1;
    
    long long temp=modExp(a,b/2,c);
    long ans;
    if(b&1)
    {
        ans= ((a%c)*((temp*temp)%c))%c;
        
    }
    else
    {
        ans=(temp*temp)%c;
    }
    return int((ans+c)%c);

}

int main()
{
    int a=3;
    int b=4;
    int c=5;
    int res=modExp(a,b,c);
    cout<<res<<endl;
    cout<<power(a,b,c)<<endl;
    
}