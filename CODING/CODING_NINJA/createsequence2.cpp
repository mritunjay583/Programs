// this program will create numbers using 
//only 2 and 5 in increasing order which is less than n

#include<bits/stdc++.h>

using namespace std;

int stringtonum(string s)  // this will convert string to number
{
   if(s=="")
       return 0;
   int res=0;
   int pow10=1;
    for(int i=s.size()-1;i>=0;i--)
   {
        res+=((s[i]-'0')*pow10);   
        pow10*=10;
   }
    return res;
}

void createSeqHelper(int n,string s)
{
    if(s!="")
    {
        if(stringtonum(s)<n)
        {
            cout<<s<<endl; // print if number is less than n
        }
    }
    if(stringtonum(s)>n)
    {
        return;
    }
    createSeqHelper(n,s+"2");
    createSeqHelper(n,s+"5");
}

void createSeq(int n)
{
    createSeqHelper(n,"");
}
int main()
{
    int n=23411;
    createSeq(n);
}