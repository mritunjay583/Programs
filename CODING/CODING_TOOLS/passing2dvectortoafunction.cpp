#include<bits/stdc++.h>


using namespace std;

void print(vector<vector<int> > &v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int> > v(5,vector<int> (5,2));
    print(v);
}