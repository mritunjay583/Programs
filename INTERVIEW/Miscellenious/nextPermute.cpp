#include<bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& nums) {
    if(nums.size()<=1)
        return;
    int n=nums.size();
    int i=n-2;
    while(i>=0){
        if(nums[i+1]>nums[i]){
            break;
        }
        i--;
    }
    if(i==-1){
        sort(nums.begin(),nums.end());
        return;
    }
    int j=i+1;
    int id=i+1;
    while(j<n){
        if(nums[i]<nums[j]){
            id=j;
        }
        j++;
    }
    swap(nums[i],nums[id]);
    sort(nums.begin()+i+1,nums.end());
}

int main(){
    vector<int> vs{1,2,3,5,3,2};
    nextPermutation(vs);
    for(auto x:vs)cout<<x<<" ";cout<<endl;
}