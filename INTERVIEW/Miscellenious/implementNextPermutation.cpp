// https://www.interviewbit.com/problems/next-permutation/
#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &A) {
    int n=A.size();
    if(n==1)return A; //is size of array is 1 return
    

    //find first position i from end where A[i]<A[i+1]
    int pos=n;
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            pos=i;
            break;
        }
    }
    if(pos==n){ //if position is n means number is greatest
        sort(A.begin(),A.end()); //so next permutation will be the smallest one
        return A; // return result
    }
    
    int nearMx=pos+1;//this will store index of an element which is just greater than A[pos]
                    // index will be form pos+1 to n
    for(int i=pos+1;i<n;i++){
        if(A[i]>A[pos]){
            nearMx=A[nearMx]>A[i]?i:nearMx;
        }
    }
    swap(A[pos],A[nearMx]); // swap
    pos++;
    if(pos>=n)return A;
    sort(A.begin()+pos,A.end()); // sort the array after swapping after index pos+1 till the end
    return A;
}


int main(){
    vector<int> nums{5,4,3,2,1};
    vector<int> res=nextPermutation(nums);
    for(auto x:res){
        cout<<x;
    }
    cout<<endl;
}