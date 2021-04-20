#include<bits/stdc++.h>

using namespace std;

void printgraph(vector<vector<int> > g){
    for(int i=0;i<g.size();i++){
        for(int j=0;j<g[i].size();j++){
            cout<<i<<" -> "<<g[i][j]<<endl;
        }
    }
}

int main()
{
    vector<vector<int> > g(4);
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(3);
    g[2].push_back(3);
    printgraph(g);
}