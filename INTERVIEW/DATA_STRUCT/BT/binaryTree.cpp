#include<bits/stdc++.h>
#include"Btree1.h"

using namespace std;

int main()
{
    Btree t;
    for(int i=1;i<=10;i++)
        t.insert(i);
    t.print(t.root);
}