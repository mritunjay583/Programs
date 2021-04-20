#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        unordered_set<int> se;
        for(auto x:strs){
            if(x=="")
                return "";
            se.insert(x.size());
        }
        int i=0;
        string res="";
        while(1){
            char x=strs[0][i];
            int f=0;
            for(int j=0;j<strs.size();j++){
                if(x!=strs[j][i]){
                    f=1;
                    break;
                }
            }
            if(f==1)
                break;
            res+=x;
            i++;
            //if one of the string is exhausted
            if(se.count(i)>0){
                break;
            }
        }
        return res;
    }

int main(){
    vector<string> vs{"flower","flow","flight"};
    cout<<longestCommonPrefix(vs)<<endl;
}