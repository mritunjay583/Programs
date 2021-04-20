#include<bits/stdc++.h>
using namespace std;

int longest_K_unique_chars_subarray(string s,int k){
    unordered_map<char,int> ma;//map to store frequency of charaters in a string
    //the same technique compress(left) and expand(right)
    int i=0;
    int j=0;
    int len=0;//variable to store the subarray that has k distinct character and has maximum length
    int n=s.size();
    while(j<n){
        //expansion
        while(ma.size()<=k && j<=n){//keep incrementing j even if there is k distinct character in window
            ma[s[j]]++;
            j++;
        }
        if(ma.size()<k)//if j==n but there is still not k distinct characters then return -1
        {
            return -1;
        }
        len=max(len,j-i-1); // store maximum length so far
        //compression
        while(ma.size()>k && i<n){//if there is k+1 characters in window then keep incrementing i and decrementing
                                 //count of characters in map  untill there are total k distinct characters in window
            ma[s[i]]--;
            if(ma[s[i]]==0){
                ma.erase(s[i]);
            }  
            i++;
        }
    }
    return len;

}
int main()
{
    string s="aaaaaaaaaa";
    int k=1;
    longest_K_unique_chars_subarray(s,k);
    return 0;
}