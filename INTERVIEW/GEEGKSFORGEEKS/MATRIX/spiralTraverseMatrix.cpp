#include<bits/stdc++.h>
using namespace std;

void spirallyTraverse(vector<vector<int>> &mat,int n,int m){
	int min_col=0;
	int max_col=m-1;
	int min_row=0;
	int max_row=n-1;
	while(min_col<=max_col && min_row<=max_row){

		for(int i=min_col;i<max_col;i++){
			cout<<mat[min_row][i];
		}
		min_row++;

		for(int i=min_row;i<max_row;i++){
			cout<<mat[i][max_col];
		}
		max_col--;

		if(min_col<=max_col){
			for(int i=max_col;i>=min_col;i--){
				cout<<mat[max_row][i];
			}
			max_row--;
		}
		
		if(min_row<=max_row){
			for(int i=max_row;i>=min_row;i--){
				cout<<mat[i][max_col];
			}
			min_col++;
		}
	}
    
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int> > mat(n,vector<int>(m,0));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>mat[i][j];
	        }
	    }
	    spirallyTraverse(mat,n,m);
	    cout<<endl;
	    
	}
	return 0;
}