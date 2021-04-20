// https://www.geeksforgeeks.org/stepping-numbers/

#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n=10,m=1000;

    int cnt=0;//store count of stepping number in range [n,m]
    queue<int> q; //for BFS
    if(n==0)
        cnt=1;
    for(int i=1;i<=9;i++)
        q.push(i);
    while(q.size()>0){
        int num=q.front();q.pop();
        
        if(num==0 || num > m)
            continue;
        if(num>=n && num<= m)
            cnt++;
        
        int last=num%10;
        int numA=num*10+last+1;
        int numB=num*10+last-1;
        
        if(last==0)
            q.push(numA);
        else if(last==9)
            q.push(numB);
        else{
            q.push(numA);
            q.push(numB);
        }
    }
    cout<<cnt<<endl;
	return 0;
}