// https://www.interviewbit.com/problems/interleaving-strings/

#include<bits/stdc++.h>

using namespace std;
bool solve(string A,string B,string C,int i,int j,int k){
    //if all the string is empty then return true
    if(i==0 && j==0 && k==0){
        return true;
    }
    //if c is empty string and A or B is not empty then return false
    if(k==0)
        return false;
    return ((A[i-1]==C[k-1]) && solve(A,B,C,i-1,j,k-1)) ||
            ((B[j-1]==C[k-1]) && solve(A,B,C,i,j-1,k-1));
}
int isInterleave(string A, string B, string C) {
    
    return solve(A,B,C,A.size(),B.size(),C.size());
    
}

int main(){
    string A="aabcc";
    string B="dbbca";
    string C="aadbbcbcac";
    cout<<isInterleave(A,B,C);
}
