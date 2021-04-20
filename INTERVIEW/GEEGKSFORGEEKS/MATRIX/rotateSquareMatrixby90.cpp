// https://practice.geeksforgeeks.org/problems/rotate-by-90-degree/0

#include<bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int> > &mat,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-------------"<<endl;
}

void rotateMatrix_2(vector<vector<int> > &a,int n){
    printMatrix(a,n);
    int low=0;
    int high=n-1;
    while(low<=high){
        int i=low;
        while(i<=high-1){
            //swapping
            // cout<<"hello"<<endl;
            int temp=a[low][high-i];
            a[low][high-i]=a[high-i][high];
            a[high-i][high]=a[high][i];
            a[high][i]=a[i][low];
            a[i][low]=temp;
            i++;
        }
        low++;
        high--;
    }
    printMatrix(a,n);
}

//method 1

void rotateMatrix_1(vector<vector<int> > &matrix,int n){
    //creating temprory matrix
    vector<vector<int> > mat(n,vector<int>(n,0));
    //main logic
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            mat[n-1-j][i]=matrix[i][j];
        }
    }
    
    printMatrix(mat,n);
}
int main()
 {
     int a[]={1, 2, 3 , 4,  5 , 6 , 7 , 8,  9, 10, 11, 12, 13, 14, 15, 16};
     int size=sizeof(a)/sizeof(a[0]);
     int n=(int)sqrt(size);
    vector<vector<int> > mat(n,vector<int>(n,0));
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=a[k++];
        }
    }
    // rotateMatrix_1(mat,n);
    rotateMatrix_2(mat,n);
	return 0;
}

//input format
// 2
// 3
// 1 2 3 4 5 6 7 8 9
// 2
// 5 7 10 9