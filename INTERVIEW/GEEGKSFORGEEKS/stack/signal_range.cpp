// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/signal-range/description/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        stack<pair<int,int> > st;
        vector<int> v(n,1);
        
        for(int i=0;i<n;i++){
            int cnt=0;
            while(st.size()>0 && a[i]>=st.top().first){
                cnt+=st.top().second;
                st.pop();
            }
            st.push(make_pair(a[i],cnt+1));
            // cout<<a[i]<<" "<<cnt+1<<endl;
            v[i]+=cnt;
        }
        for(auto x:v)cout<<x<<" ";cout<<endl;

    }
}

//input exapmle
// 1
// 7
// 100 80 60 70 60 75 85