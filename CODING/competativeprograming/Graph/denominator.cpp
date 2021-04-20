#include<bits/stdc++.h>

using namespace std;

void print(int n)
{
    cout<<"+";
    for(int i=0;i<2*n-1;i++)
    cout<<"-";
    cout<<"+";
    cout<<endl;
}
void solve(vector<int> g[],int n,unordered_map<int,int> &ma)
{
    for(int i=0;i<n;i++)
    {
        print(n);
        cout<<"|";
        for(int j=0;j<n;j++)
        {
            if(ma[j]==1 && g[i][j]==1 || i==0 || i==j)
            cout<<"Y|";
            else
            cout<<"N|";
        }
        cout<<endl;
    }
    print(n);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> g[n];
        int x;
        unordered_map<int,int> ma;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>x;
                g[i].push_back(x);
                if(g[i][j]==1)
                {
                    ma[j]++;
                }
            }
        }
        solve(g,n,ma);
    }

}