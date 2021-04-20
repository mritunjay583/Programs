
//Given a sorted array of positive integers

//input :1 2 3 4 5 6 7 8 9
//output ; 9 1 8 2 7 3 6 4 5


/*

/// very powerfull method
//with the help of this you can put two values in same index
//this method is useful when you can inplace rearranegment
//at any index i of an array

// old_value=(old_value%mx_val)+(new_val%mx_val)*mx_val;

// thus old_value=a[i]%mx_value
// new_value=a[i]/mx_value

// mx_val =value that is greater among all elements of the array


*/
#include<bits/stdc++.h>

using namespace std;

void reorder_2(long long int a[],int size)
{
    int j=size-1;
    int i=0;
    int k=0;
    int mx_val=*max_element(a,a+size)+1;
    while(i<=j)
    {
        if(k%2==0)
            a[k]=a[k]%mx_val+(a[j--]%mx_val)*mx_val;
        else
            a[k]=a[k]%mx_val+(a[i++]%mx_val)*mx_val;
        k++;
    }
    for(int i=0;i<size;i++)
        cout<<a[i]/mx_val<<" ";
    cout<<endl;

}

//time O(nlong)
//space O(n)
void reorder_1(int a[],int n)
{
    map<int,int> ma;
    for(int i=0;i<n;i++)ma[a[i]]=i;
    int k=0;
    for(auto x:ma)
    {
        a[ma[x.first]]=k++;
    }
    for(int i=0;i<n;i++)cout<<a[i]<<endl;

}
int main()
{
    long long int a[]={10,30,50,60,90};
    int size=sizeof(a)/sizeof(a[0]);
    // reorder_1(a,size);
    reorder_2(a,size);
}



