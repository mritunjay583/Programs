#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int i=0;
int search(int arr[],int x,int st,int en){
    int res=0;
    for(int i=st;i<=en;i++){
        if(arr[i]==x){
            res=i;
            break;
        }
    }
    return res;
}

void printPost(int arr[],int pre[],int st,int en){
    if(st>en)
        return;
    
    int id=search(arr,pre[i++],st,en);
    printPost(arr,pre,st,id-1);
    printPost(arr,pre,id+1,en);
    cout<<arr[id]<<" ";
}

int main()  
{  
    int arr[] = {4, 2, 5, 1, 3, 6};  
    int pre[] = {1, 2, 4, 5, 3, 6};  
    int len = sizeof(arr)/sizeof(arr[0]);  
    printPost(arr, pre, 0, len - 1);  
}