#include<bits/stdc++.h>
using namespace std;
void smallest_distinct_subarray(string s){
    int n=s.size();
    unordered_set<char> st;//to count all distinct characters
    for(int i=0;i<n;i++){
        st.insert(s[i]);
    }
    int total_distinct_chars=st.size();

    //keep count of the characters of current window 
    unordered_map<char,int> ma;
    int start=0,end=0;
    int len=INT_MAX;
    int cnt=0;
    for(end=0;end<n;end++){
        ma[s[end]]++;
        
        //count for distinct characters 
        if(ma[s[end]]==1){
            cnt++;
        }
        if(cnt==total_distinct_chars){
            //all characters are found in window so try to compress the window from left side so that all the
            //charaters are present in window of minimum length
            while(ma[s[start]]>1){
                ma[s[start]]--;
                start++;
            }
            len=min(len,end-start+1);
        }
    }
    cout<<len<<endl;
}
int main() {
    string s="aabcbcdbca";
    smallest_distinct_subarray(s);//this function will calculate smallest subarray that has all charachters unique
    return 0;
}