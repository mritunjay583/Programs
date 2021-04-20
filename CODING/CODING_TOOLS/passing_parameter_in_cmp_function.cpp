#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr1[]={2,1,2,5,7,1,9,3,6,8,8};
    int arr2[]={2,1,8,3};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);

    unordered_map<int,int> ma;
    for(int i=0;i<size2;i++){ma[arr2[i]]=i;}

    sort(arr1,arr1+size1,[&ma](int a,int b)
    {
        return ma[a]<ma[b];
    });
}