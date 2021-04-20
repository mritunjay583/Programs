#include<bits/stdc++.h>

using namespace std;

//time  O(n) and space O(n)
int find_pair_with_sum_k_2(int a[],int n,int k){
    unordered_map<int,int> ma;
    for(int i=0;i<n;i++){
        ma[a[i]]++;
    }
    for(int i=0;i<n;i++){
        if(ma.count(k-a[i])>0){
            if(k==2*a[i]){
                if(ma[a[i]]>1){
                    return 1;
                }
            }else{
                return 1;
            }
        }
    }
    return 0;
}


//time O(nlogn) spaace O(1)
int find_pair_with_sum_k_1(int a[],int n,int k){
    sort(a,a+n);
    int i=0;
    int j=n-1;
    while(i<j){
        if((a[i]+a[j])<k){
            i++;
        }else if((a[i]+a[j])>k){
            j--;
        }else return 1;
    }
    return 0;
}

int main(){
    int a[]={1,2,2,6,7};
    int k=4;
    int n=sizeof(a)/sizeof(a[0]);
    int res1=find_pair_with_sum_k_1(a,n,k);
    if(res1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    int res2=find_pair_with_sum_k_2(a,n,k);
    if(res2)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}