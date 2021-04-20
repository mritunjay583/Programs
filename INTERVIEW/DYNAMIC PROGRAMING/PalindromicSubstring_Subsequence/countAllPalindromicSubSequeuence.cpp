// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
#include<bits/stdc++.h> 
using namespace std; 


/*You are required to complete below method */
int count_lps_2(string seq,int n){
    
    int dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=0;
        }
    }
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
                dp[i][j]=dp[i+1][j]+dp[i][j-1]+1;
            }
            else{
                dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            }
            ///////

        }
    }
    return dp[0][n-1];


}

///////////////////////////////////////////////////////////////////////////////////////////
///recursive solution
int count_lps(char seq[],int i,int j){
	if(i>j){
		return 0;
	}
	if(i==j){
		return 1;
	}
	if(seq[i]==seq[j]){
		return count_lps(seq,i+1,j)+count_lps(seq,i,j-1)+1;
	}
	else{
		return count_lps(seq,i+1,j)+count_lps(seq,i,j-1)-count_lps(seq,i+1,j-1);
	}
}

///////////////////////////////////////////////////////////////////////////////////////
int main() {
	char seq[] ="aaa"; 
	int n = strlen(seq);
	int res1=count_lps(seq,0,n-1); 
	int res2=count_lps_2(seq,n);
	cout<<res1<<endl;
	cout<<res2<<endl;
	return 0; 
} 
