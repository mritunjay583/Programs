#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &v){
    int n=v.size();
    vector<int> tail(n,0);
    int len=1;
    tail[0]=v[0];
    for(int i=1;i<n;i++){
        auto it=lower_bound(tail.begin(),tail.begin()+len,v[i])-tail.begin();
        if(it==len){
            tail[len++]=v[i];
        }else{
            tail[it]=v[i];
        }
    }
    return len;
}
int main()
 {
    
    vector<int> v{0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    int len=solve(v);
    cout<<len<<endl;
	return 0;
}