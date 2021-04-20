#include<bits/stdc++.h>

using namespace std;

void initializeRootArray(int rootArray[],int vertices)
{
    for(int i=0;i<vertices;i++)
    {
        rootArray[i]=i;
    }
}
int root(int v,int rootArray[])
{
    while(v!=rootArray[v])
    {
        rootArray[v]=rootArray[rootArray[v]];  // this is compressing path
        v=rootArray[v];
    }
    return v;
}

void doUnion(int rootArray[],int A,int B)
{
    int root_A=root(A,rootArray);
    int root_B=root(B,rootArray);
    rootArray[root_B]=root_A;
}

void findComponents(int rootArray[],int vertices)
{
    map<int,vector<int> > ma;
    for(int i=0;i<vertices;i++)
    {
        ma[root(i,rootArray)].push_back(i);
    }
    cout<<"---connected_components---"<<endl;
    for(auto x:ma)
    {
        for(auto y:x.second)
        {
            cout<<y+1<<" ";
        }
        cout<<endl;
    }
}
void unionFind(int vertices,int edges)
{
    int rootArray[vertices];
    initializeRootArray(rootArray,vertices); // intializing root Array

    int A,B;
    // taking input from user and doing union
    // 1 <= A,B <= vertices
    for(int i=0;i<edges;i++)
    {
        cin>>A>>B;
        doUnion(rootArray,A-1,B-1);
    }
    findComponents(rootArray,vertices);
}

void doWeightedUnion(int rootArray[],int size[],int A,int B)
{
    int root_A=root(A,rootArray);
    int root_B=root(B,rootArray);
    if(size[root_A]<size[root_B])
    {
        rootArray[root_A]=root_B;
        size[root_B]+=size[root_A];
    }
    else
    {
        rootArray[root_B]=root_A;
        size[root_A]+=size[root_B];
    }
    
}
void weightedUnionFind(int vertices,int edges)
{
    int rootArray[vertices];
    int size[vertices];
    initializeRootArray(rootArray,vertices); // intializing root Array
    for(int i=0;i<vertices;i++)size[i]=1;

    int A,B;
    // taking input from user and doing union
    // 1 <= A,B <= vertices
    for(int i=0;i<edges;i++)
    {
        cin>>A>>B;
        doWeightedUnion(rootArray,size,A-1,B-1);
    }
    findComponents(rootArray,vertices);
}

int main()
{
    int vertices,edges;
    cin>>vertices>>edges;
    unionFind(vertices,edges);
    // weightedUnionFind(vertices,edges);// it is faster than
                                    // simple unionFind
}

// input type

// number of vertices,number of edges
// next lines will be edges

//  input example

/*  5 2        
    4 2
    3 1  */

