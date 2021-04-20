#include<bits/stdc++.h>

using namespace std;
////////////////////////////////////////////////////////
/////brute force ////// O(n^2) ///////////////////////////
// int pair_of_variation(vector<long long > v,int k){
//     int cnt=0;
//     for(int i=0;i<v.size()-1;i++){
//         for(int j=i+1;j<v.size();j++){
//             if(abs(v[i]-v[j])>=k){
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }
///////////////////////////////////////////////////////
//////////O(nlogn)//////////////////////////////////
int pair_of_variation(vector<long long > v,int k){
    int cnt=0;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++){
        int value=lower_bound(v.begin()+i+1,v.end(),(k+v[i]))-v.begin();
        if(value>=v.size()){
            break;
        }
        cnt+=(v.size()-value);
    }
    return cnt;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<long long > v;
    long long x;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    int res=pair_of_variation(v,k);
    cout<<res<<endl;
}

// test cases//////////////
/*

8 5
2 3 6 7 8 10 12 13


                            
                            */