// https://practice.geeksforgeeks.org/problems/circle-of-strings/0

#include<bits/stdc++.h>
using namespace std;

void DFS(int i,string s[],vector<bool> &visited,int n){

    for(int j=0;j<n;j++){
        if(visited[j]==false && s[i][s[i].size()-1]==s[j][0]){
            visited[j]=true;
            DFS(j,s,visited,n);
        }
    }
}

bool isCycle(string s[],int n){
    vector<bool> visited(n,false);
    
    DFS(0,s,visited,n);

    //if any string is not visited after DFS then all string will not form a circle
    for(int i=0;i<n;i++){ 
        if(visited[i]==false){
            return false;
        }
    }
    return true;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s[n];
	    for(int i=0;i<n;i++)cin>>s[i];
	    cout<<isCycle(s,n)<<endl;
	}
	return 0;
}

//input sample
// 2
// 3
// abc bcd cdf
// 4
// ab bc cd da