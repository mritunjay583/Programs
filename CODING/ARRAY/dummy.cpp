#include<bits/stdc++.h>
using namespace std;
int MissingNumber(int arr[], int size){
    sort(arr,arr+size);
    for(int i=0;i<size;i++){
        if(arr[i]!=i){
            return i;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<MissingNumber(a,n);
	return 0;
}
