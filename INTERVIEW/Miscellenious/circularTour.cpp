// https://practice.geeksforgeeks.org/problems/circular-tour/1
// https://leetcode.com/problems/gas-station/discuss/319512/O(n)-complexity-solution.
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
// } Driver Code Ends


/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/

int tour(petrolPump p[],int n)
{
    int x=0;
    int y=0;
    for(int i=0;i<n;i++){
        x+=p[i].petrol;
        y+=p[i].distance;
    }
    if(x<y) //if total petrol is less than total distance then journey cannot complete
        return -1;
    int st=0;
    int bal=0;
    for(int i=0;i<n;i++){
        bal+=(p[i].petrol-p[i].distance);
        if(bal<0){
            st=i+1;
            bal=0;
        }
    }
    return st;
}

