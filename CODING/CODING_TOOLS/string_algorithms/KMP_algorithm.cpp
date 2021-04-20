#include<bits/stdc++.h>

using namespace std;

vector<int> getlps(string pattern)
{
    vector<int> lps(pattern.size());
    lps[0]=0;
    int j=0;
    int i=1;
    while(i<pattern.size())
    {
        if(pattern[i]==pattern[j])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
            
        }
        
        return lps;
    }
}

void KMP(string text,string pattern,vector<int> &v)
{
    vector<int> lps(pattern.size());
    lps=getlps(pattern);
    int i=0;
    int j=0;
    while(i<text.size())
    {
        if((j==pattern.size()-1) && (pattern[j]==text[i]))
        {
                v.push_back(i-pattern.size()+1);
                j=0;
                i++;
        }
        else if(pattern[j]==text[i])
        {
            i++;
            j++;
            
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
            
        }
    }
    
}

int main()
{
    string text="xabcdey";
    string pattern="ad*d";
    vector<int> v;
    KMP(text,pattern,v);
    for(auto x:v)cout<<x<<" ";cout<<endl;
}