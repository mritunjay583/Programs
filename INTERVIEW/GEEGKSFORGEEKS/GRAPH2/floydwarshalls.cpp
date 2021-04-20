#include<bits/stdc++.h>
using namespace std;

void all_pair(int **g,int v,int st){
    if(st>=v){
        return;
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            g[i][j]=min(g[i][j],g[i][st]+g[st][j]);
        }
    }
    all_pair(g,v,st+1);
    
}


int main()
 {
    int t;
    cin>>t;
    while(t--){
        int v;
        cin>>v;
        int **g=new int*[v];
        for(int i=0;i<v;i++){
            g[i]=new int[v];
            for(int j=0;j<v;j++){
                cin>>g[i][j];
            }
        }
        all_pair(g,v,0);
        
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
	return 0;
}