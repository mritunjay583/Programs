// https://www.interviewbit.com/problems/jump-game-array/
// https://www.youtube.com/watch?v=muDPTDrpS28

#include<bits/stdc++.h>

using namespace std;

int canJump(vector<int> &A) {
    int max_reachable=0;
    for(int i=0;i<A.size();i++){
        if(max_reachable<i)
            return false;
        max_reachable=max(max_reachable,A[i]+i);
    }
    return true;
}


int main(){
    vector<int> v{3,2,1,2,4};
    cout<<canJump(v)<<endl;
}
