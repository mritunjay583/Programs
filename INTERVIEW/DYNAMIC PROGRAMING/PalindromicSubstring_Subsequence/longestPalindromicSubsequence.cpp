// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

#include<bits/stdc++.h> 
using namespace std; 

//longest palindromic subsequence cam be found using LCS(str,reverse(str));


//////////////////////////////////////////////////////////////////////////////////
//
int lps_2(char seq[],int n){
    
    vector<vector<int> > dp(n,vector<int>(n,0));
    //string of length 1 will be palindrome
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }

    //storing result in dp table of string of length greater than equal to 2
    for(int k=2;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j=i+k-1;
            ///////
            if(seq[i]==seq[j]){
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
            ///////
        }
    }
    return dp[0][n-1];


}
//////////////////////////////////////////////////////////////////////////////////////////
int lpsUtil(char seq[],int i,int j,int **dp){
    if(i>j){
        return 0;
    }
    if(i==j){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(seq[i]==seq[j]){
        dp[i][j] = 2+lpsUtil(seq,i+1,j-1,dp);
        return dp[i][j];
    }
    else{
        dp[i][j]=max(lpsUtil(seq,i+1,j,dp),lpsUtil(seq,i,j-1,dp));
        return dp[i][j];
    }
}
int lps(char seq[],int i,int j){
    int len=j-i+1;
    int **dp=new int*[len];
    for(int k=0;k<len;k++){
        dp[k]=new int[len];
        for(int p=0;p<len;p++){
            dp[k][p]=-1;
        }
    }
    return lpsUtil(seq,i,j,dp);
}
///////////////////////////////////////////////////////////////////////////////////////
int main() {
	char seq[] = "bebdeeedaddecebbbbbabebedc"; 
	int n = strlen(seq); 
    int res1=lps(seq, 0, n-1);
    int res2=lps_2(seq,n);
	cout << "The length of the LPS is "
		<< res1<<endl;
    cout << "The length of the LPS is "
		<< res2<<endl; 

	return 0; 
} 
