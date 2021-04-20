#include<bits/stdc++.h>

using namespace std;

void decodeHelper(int code,string s)
{
    if(code<=0)
    {
        cout<<s<<endl;
        return;
    }
    int x=code%10;
    s="#"+s;
    if(x!=0)
    {
    
    char c=(x-1)+'A';
    s[0]=c;
    decodeHelper(code/10,s);
    }
    int y=code%100;
    if(10<=y && y<=26)
    {
        char d=(y-1)+'A';
        s[0]=d;
        decodeHelper(code/100,s);
    }

}


void decode(int code)
{
    decodeHelper(code,"");
}

int main()
{
    int code=1123;
    decode(code);
}