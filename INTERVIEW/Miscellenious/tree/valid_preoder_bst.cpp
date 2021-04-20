
// https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
#include<bits/stdc++.h>

using namespace std;

bool helper(vector<int> &A,int st,int en){
    if(st>=en){
        return true;
    }
    
    int k=en+1;
    for(int i=st+1;i<=en;i++){
        if(A[i]>A[st]){
            k=i;
            break;
        }
    }
    
    for(int i=k;i<=en;i++){
        if(A[st]>A[i]){
            return false;
        }
    }
    
    return helper(A,st+1,k-1) && helper(A,k,en);

}

int solve(vector<int> &A) {
    return helper(A,0,A.size()-1);
}

///////////////////////////////////////////
// O(n)/////////////////////complexity
int solve2(vector<int> &A) {
    stack<int> st;
    int root=INT_MIN;
    for(int i=0;i<A.size();i++){
        if(root>A[i])
            return false;
        
        while(st.size()>0 && st.top()<A[i]){
            root=st.top();
            st.pop();
        }
        st.push(A[i]);
    }
    return true;
}

int main(){
    vector<int> v{5,1,2,4,6,8,3,9};
    cout<<solve(v)<<endl;
}