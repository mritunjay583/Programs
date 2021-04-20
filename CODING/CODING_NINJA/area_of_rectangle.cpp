#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x1=1,y1=1,x2=3,y2=4;
    int x3=2,y3=3,x4=6,y4=7;
    int ar1=abs(x1-x2)*abs(y1-y2);
    int ar2=abs(x3-x4)*abs(y3-y4);
    int ar3=abs(max(x1,x3)-min(x2,x4))*abs(max(y1,y3)-min(y2,y4));
    cout<<ar1+ar2-ar3<<endl;
}