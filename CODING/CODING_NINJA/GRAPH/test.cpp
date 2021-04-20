#include<bits/stdc++.h>

using namespace std;

void print(char s[])
{
    if(s[0]=='\0')
    return;
    print(s+1);
    cout<<s[0];
}
int main()
{
    char s[]="sahil";
    print(s);
}