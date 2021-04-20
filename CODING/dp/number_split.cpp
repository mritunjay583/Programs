#include<bits/stdc++.h>


using namespace std;

void print(vector<int> v)
{
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
        cout<<v[i]<<" ";
    }
    cout<<" : "<<sum;
    cout<<endl;
}
int cnt=0; // count number of ways that a number can be splitted
vector<vector<int> >res;
vector<int> v;
void find_min_ways(int arr[],int size,int target)
{
    if(target<0)
    {
        return;
    }
    if(target==0)
    {
        cnt++;  
        print(v);
        res.push_back(v);
        return;
    }
    for(int i=0;i<size;i++)
    {
        target-=arr[i];
        v.push_back(arr[i]);
        find_min_ways(arr,size,target);
        v.pop_back();
        target+=arr[i];
    }
}

int main()
{
    int a[]={3,2};
    int target=6;
    find_min_ways(a,2,target);
    cout<<cnt<<endl;
}