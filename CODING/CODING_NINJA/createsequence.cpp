// this program will create numbers using only 2 and 5 in increasing order

#include<bits/stdc++.h>

using namespace std;

int cnt=0;
void createSeq(int n,string s)
{
    if(s.size()==n)
    {
        cnt++;
        cout<<s<<endl;
        return;
    }
    createSeq(n,s+"2");
    createSeq(n,s+="5");

}
int main()
{
    int n=4;
    createSeq(n,"");
    cout<<cnt;
}