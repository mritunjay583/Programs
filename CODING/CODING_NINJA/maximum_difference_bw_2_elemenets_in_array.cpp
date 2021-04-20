#include<bits/stdc++.h>

using namespace std;
/////////////////METHOD 1 ///////////////////////////////////////////
//////////////time O(n^2)///////////////////////////////////////////
//////////////space O(1) /////////////////////////////////////////

// int max_difference(int a[],int size)
// {
//     int max_diff=a[1]-a[0];
//     for(int i=0;i<size-1;i++)
//     {
//         for(int j=i+1;j<size;j++)
//         {
//             if(max_diff<(a[j]-a[i]))
//             {
//                 max_diff=a[j]-a[i];
//             }

//         }
//     }
//     return max_diff;
// }



//////////////////////METHOD 2 //////////////////////////////////////
////////////////time complexity O(n) ///////////////////////////////
////////////////space O(1) ////////////////////////////////////////
// int max_difference(int a[],int size)
// {
//     int max_diff=a[1]-a[0];
//     int min_ele=a[0];
//     for(int i=0;i<size;i++)
//     {
//         if((a[i]-min_ele)>max_diff)
//         {
//             max_diff=a[i]-min_ele;
//         }
//         if(min_ele>a[i])
//         {
//             min_ele=a[i];
//         }
//     }
//     return max_diff;
// }

//////////////////////METHOD 3  //////////////////////////////////////
////////////////time complexity O(n) ///////////////////////////////
////////////////space O(1) ////////////////////////////////////////

int main()
{
    int a[]={4,2,16,2,5,10,1};
    int size=sizeof(a)/sizeof(a[0]);
    int res=max_difference(a,size);
    cout<<res<<endl;
}