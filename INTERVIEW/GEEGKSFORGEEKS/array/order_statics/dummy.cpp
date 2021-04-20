#include<bits/stdc++.h>

using namespace std;


int main()
{
    int prime=7;
    int n=10;
    int total = 1, prev = 1;
    while(1){
        int current = 0;
        prev *= prime;
        cout<<prev<<endl;
        current = n/prev;
        if(current==0)
        {
            break;
        }
        total += current;
    }
}