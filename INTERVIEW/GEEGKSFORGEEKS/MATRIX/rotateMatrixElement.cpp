#include<bits/stdc++.h>

using namespace std;


void rotateMatrix(int **mat,int n,int m){
    
}

int main(){
    int n,m;
    cin>>n>>m;
    int **mat=new int*[n];
    for(int i=0;i<n;i++){
        mat[i]=new int[m];
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    rotateMatrix(mat,n,m);
}