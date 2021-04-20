#include<bits/stdc++.h>

using namespace std;

double find_median(double arr1[],double arr2[],int size)
{
    

}

int main()
{
    double arr1[] = {1, 12, 15, 26, 38}; 
    double arr2[] = {2, 13, 17, 30, 45};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    double median=find_median(arr1,arr2,n1);
    cout<<"median : "<<median<<endl;
}