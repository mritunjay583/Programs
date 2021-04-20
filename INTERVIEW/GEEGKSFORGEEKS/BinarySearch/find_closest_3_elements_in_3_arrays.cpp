//Find three closest elements from given three sorted arrays
// Given three sorted arrays A[], B[] and C[], find 3 elements i, j and k from A, B and C respectively such that 
// max(abs(A[i] – B[j]), abs(B[j] – C[k]), abs(C[k] – A[i])) is minimized


#include<bits/stdc++.h>

using namespace std;
void method_1(int a[],int na,int b[],int nb,int c[],int nc){
    int mi=INT_MAX;
    int p,q,r;
    for(int i=0;i<na;i++){
        for(int j=0;j<nb;j++){
            for(int k=0;k<nc;k++){
                int temp=max(abs(a[i]-b[j]),max(abs(b[j]-c[k]),abs(c[k]-a[i])));
                if(mi>temp){
                    p=i;
                    q=j;
                    r=k;
                    mi=temp;
                }
            }
        }
    }
    cout<<a[p]<<" "<<b[q]<<" "<<c[r]<<endl;
}
void method_2(int a[],int na,int b[],int nb,int c[],int nc){

    // main idea 
    //max(abs(A[i] – B[j]), abs(B[j] – C[k]), abs(C[k] – A[i])) = max(a[i],b[j],c[k])-min(a[i],b[j],c[k]);
    //complexity of this method is time:O(na+nb+nc)
    int mx_diff=INT_MAX;
    int i=0;
    int j=0;
    int k=0;
    int res_i,res_j,res_k;
    while(i<na && j<nb && k<nc){
        int minimum=min(a[i],min(b[j],c[k]));
        int maximum=max(a[i],max(b[j],c[k]));
        if(abs(maximum-minimum)<mx_diff){
            res_i=i;
            res_j=j;
            res_k=k;
            mx_diff=abs(maximum-minimum);
        }
        if(mx_diff==0)break;
        if(minimum==a[i])i++;
        else if(minimum==b[j])j++;
        else k++;
    }
    cout<<a[res_i]<<" "<<b[res_j]<<" "<<c[res_k]<<endl;

}
int main(){
    int a[] = {20, 24, 100};
    int na=sizeof(a)/sizeof(a[0]);
    int b[] = {2, 19, 22, 79, 800};
    int nb=sizeof(b)/sizeof(b[0]);
    int c[] = {10, 12, 23, 24, 119};
    int nc=sizeof(c)/sizeof(c[0]);
    method_1(a,na,b,nb,c,nc);
    method_2(a,na,b,nb,c,nc);
}