#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > allSubarray(int arr[],int size,int k)
{
    unordered_map<int,vector<int> > ma;
    vector<pair<int,int> > ans;
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
        if((sum-k)==0)
        {
            ans.push_back(make_pair(0,i));
        }
        if(ma.count(sum-k)>0)
        {
            vector<int> v=ma[sum-k];
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
    int arr[]={135,101,170,125,79,159,163,65,106,146,82, 28, 162, 92, 196, 143, 28, 37, 192, 5, 103, 154, 93, 183, 22, 117, 119, 96, 48, 127, 172, 139, 70, 113, 68, 100, 36, 95, 104, 12, 123, 134};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=468;
    vector<pair<int,int> > res=allSubarray(arr,size,k);
    for(auto x:res)cout<<x.first<<" "<<x.second<<endl;
}