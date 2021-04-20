#include<iostream>
using namespace std;
pair<int,int> flrAndceil(int a[],int n,int x){
    int low=0;
    int high=n-1;
    int flr=-1;
    int cil=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        ////////////////////////
        if(a[mid]<x){
            flr=mid;
            low=mid+1;
        }
        //////////////////////
        else if(a[mid]==x){
            cil=flr=mid;
            break;
        }
        else{
            cil=mid;
            high=mid-1;
        }
    }
    return make_pair(flr,cil);
}
int main(){
    int a[]={0,1,2,3,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    int x=-1;
    pair<int,int> res=flrAndceil(a,n,x);
    cout<<a[res.first]<<" "<<a[res.second]<<endl;
	return 0;
}