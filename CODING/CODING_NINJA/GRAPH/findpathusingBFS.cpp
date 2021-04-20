#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool BFS(vector<vector<int> > graph,int V,int v1,int v2)
{
    queue<int> q;
    vector<bool> visited(V,false);
    map<int,int> m;
    q.push(v1);
    m[v1]=v1;
    visited[v1]=true;
    int flag=0;
    while(q.empty()!=true)
    {
        int temp=q.front();
        q.pop();
        for(int i=0;i<V;i++)
        {
            if(i==temp)
                continue;
            if(graph[temp][i]==1)
            {
                if(visited[i]==false)
                {
                    m[i]=temp;
                    if(i==v2)
                    {
                        flag=1;
                        break;
                    }
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
        if(flag==1)
        {
            break;
        }
        
    }
    int itr=v2;
    cout<<"path in reverse order : -> ";
    while(1)
    {
        if(m.find(itr)==m.end())
        {
            break;
        }
        cout<<itr<<" ";
        if(itr==v1)
            break;
        itr=m[itr];
     }
    
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    vector<vector<int> >  graph(V , vector<int> (V,0));
    for(int i=0;i<E;i++)
    {
        cin>>tempX>>tempY;
        graph[tempX][tempY]=1;
        graph[tempY][tempX]=1;
    }
    int v1,v2;
    cin>>v1>>v2;
    BFS(graph,V,v1,v2);

  return 0;
}


/* input

4 4
0 1
0 3
1 2
2 3
1 3


*/