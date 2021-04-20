
// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station-set-2-map-based-approach/
// https://practice.geeksforgeeks.org/problems/minimum-platforms/0
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int b[n];
        for(int i=0;i<n;i++)cin>>b[i];
        
        int platform[2400]={0};
        int mx=0;
        for(int i=0;i<n;i++){
            platform[a[i]]++;
            platform[b[i]+1]--;
        }
        for(int i=1;i<2400;i++){
            platform[i]+=platform[i-1];
            mx=max(mx,platform[i]);
        }
        cout<<mx<<endl;
    }
}