// array is right rotated


#include<bits/stdc++.h>

using namespace std;
void print(vector<int> &v)
{
    for(auto x:v)cout<<x<<" ";cout<<endl;
}
int get_pivot(vector<int> &v)
{
    int low=0;
    int high=v.size()-1;
    while(low<high)
    {
        int mid=(low+high)/2;
        if((mid==0 && v[mid]>v[mid+1]) ||
            (mid==v.size()-1 && v[mid]>v[mid-1]))
        return mid;
        else if(v[mid]>v[mid+1] && v[mid]>v[mid-1])
            return mid;
        else if(v[mid-1]>v[mid] && mid-1>=0)
            high=mid-1;
        else if(v[mid+1]>v[mid] && mid+1<v.size())
            low=mid+1;
    }
}

int main()
{
    // cout<<"hello"<<endl;
    vector<int> v{11, 15, 6, 8, 9, 10};
    int target=26;
    int pivot=get_pivot(v);
    int h=pivot;
    int l=(pivot+1)%v.size();
    while(l!=h)
    {
        if(v[l]+v[h]>target)
        {
            h=((h-1)+v.size())%v.size();
        }
        else if(v[l]+v[h]<target)
        {
            l=(l+1)%v.size();
        }
        else
            break;
    }
    if(l==h)
        cout<<"not found"<<endl;
    else
        cout<<v[l]<<" + "<<v[h]<<" = "<<target<<endl;
}