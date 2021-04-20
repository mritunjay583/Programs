#include<bits/stdc++.h>
using namespace std;
int main() {

	int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int min=1;
        int max=v[v.size()-1];
        int cnt=0;
        int prev;
        int i,j;
        int flag=0;
        ////////////////////you can use binary search also to reduce time complexity 
        for(i=min;i<=max;i++){
            cnt=0;
            for(j=0;j<v.size();j++){
                cnt+=v[j]/i;
                if(cnt>=k){
                    break;
                }
            }
            if(j==v.size() && cnt<k){
                break;
            }
            prev=i;
            
        }
        cout<<prev<<endl;
        
    }
}