#include<bits/stdc++.h>

using namespace std;

void zalgorithm(string zstring,vector<int> &zarray)
{
    zarray[0]=0;
    int j=0;
    int k=1;
    int i=1;
    while(i<zstring.size())
    {
        if(zstring[j]==zstring[i])
        {
            i++;
            j++;
        }
        else
        {
            zarray[k]=i-k;
            k++;
            i=k;
            j=0;
        }
        
    }
    if(zstring[j]=='$')
    {
        zarray[k]=i-k;
    }
}

int main()
{
    string text="CWUBBWUBWUBWUBEWUBWUBWUBQWUBWUBWUB";
    string pattern="WUB";
    string zstring=pattern+"$"+text;
    vector<int> zarry(zstring.size(),0);
    zalgorithm(zstring,zarry);
    cout<<"pattern matched at : ";
    for(int i=0;i<zarry.size();i++)
    {
        if(zarry[i]==pattern.size())
        {
            cout<<i-pattern.size()-1<<" , ";
        }
    }
}