#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > allSubarray(int arr[],int size)
{
    unordered_map<int,vector<int> > ma;
    vector<pair<int,int> > ans;
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
        if(sum==0)
        {
            ans.push_back(make_pair(0,i));
        }
        if(ma.count(sum)>0)
        {
            vector<int> v=ma[sum];   
            for(auto x:v)
            {
                ans.push_back(make_pair(x+1,i));
            }
        }
        ma[sum].push_back(i);
    }
    return ans;
}

int main()
{
    int arr[]={0,0,5,5,0,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    vector<pair<int,int> > res=allSubarray(arr,size);
    for(auto x:res)cout<<x.first<<" "<<x.second<<endl;
}