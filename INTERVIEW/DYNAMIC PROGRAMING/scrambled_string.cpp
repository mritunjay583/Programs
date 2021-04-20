#include<bits/stdc++.h>

using namespace std;


bool solve(string x,string y){
    if(x==y)    //same strings are scramble 
        return true; 
    if(x.size()==0)   // strings of 0 length are scramble
        return true;
    
    //check if x and y are anagrams if they are not anagrams then return false
    string copy_x=x;
    string copy_y=y;
    sort(copy_x.begin(),copy_x.end());
    sort(copy_y.begin(),copy_y.end());
    if(copy_x!=copy_y)
        return false;
    
    int n=x.size();
    
    for(int i=1;i<=n-1;i++){
        if(solve(x.substr(0,i),y.substr(0,i)) && solve(x.substr(i,n-i),y.substr(i,n-i))||
           solve(x.substr(0,i),y.substr(n-i,i))&& solve(x.substr(i,n-i),y.substr(0,n-i))){
               return true;
           }
    }
    return false;
}

int isScramble(const string A, const string B) {
    string x=A;
    string y=B;
    return solve(x,y);
}


int main(){
    string A="coder";
    string B="ocder";
    cout<<isScramble(A,B)<<endl;
}