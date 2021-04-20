#include<bits/stdc++.h>

using namespace std;

void find_square_root(int n)
{
    int low=1;
    int high=n/2;
    int mid=(low+high)/2;
    int lowerB=mid;
    while(low<=high)
    {
        int mid=(low+high)/2;

        int sqr=mid*mid;  // this may cause integer overflow
        
        if(sqr==n)
        {   
            lowerB=mid;
            break;
        }
        if(sqr<n)
        {
            low=mid+1;
            lowerB=mid;  // this giver lower bound
        }
        else if(sqr>n)
        {
            high=mid-1;
        }
        
    }
    cout<<"floor(sqrt("<<n<<")) = "<<lowerB<<endl;
    cout<<"ceil(sqrt("<<n<<")) = "<<lowerB+1<<endl;
}

int main()
{
    int n=4;
    // cin>>n;
    find_square_root(n);
}