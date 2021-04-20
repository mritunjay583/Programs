// https://practice.geeksforgeeks.org/problems/points-in-straight-line/1

#include<bits/stdc++.h>
using namespace std; 

int maxPoints(int X[],int Y[],int );              
int main() {
     
     int t;
     cin>>t;
     while(t--)
     {
        int n;
        cin>>n;
        int x[n];
        int y[n];
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
        }


        for(int i=0;i<n;i++)
        {
            cin>>y[i];
        }

     
    cout << maxPoints(x,y,n) << endl;
     }
    
     
   
    return 0;
}// } Driver Code Ends
/*You are required to complete this method */
#include<bits/stdc++.h>

int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int maxPoints(int X[], int Y[],int n) {
    map<pair<int,int>,int> ma;
    int gmax=0; // global max to store max points in line
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;//a line cannot pass through a single line
            
            int x1=X[i];
            int y1=Y[i];
            int x2=X[j];
            int y2=Y[j];
            int y=y2-y1;
            int x=x2-x1;
            
            if(x==0 && y==0){
                ma[make_pair(0,0)]++;
            }else if(x==0){
                ma[make_pair(INT_MAX,0)]++;
            }else if(y==0){
                ma[make_pair(0,INT_MAX)]++;
            }else{
                int gc=gcd(abs(x),abs(y));
                y=y/gc;
                x=x/gc;
                ma[make_pair(y,x)]++;
            }
        }
        int mx=0; //store max points in a line which passes through (X[i],Y[i])
        for(auto x:ma){
            mx=max(x.second,mx);
        }
            gmax=max(gmax,mx);
            ma.clear();
    }
    return gmax+1;
}


//sample input
// 2
// 2
// 1 1
// 2 2
// 3
// 0 0 0
// 4 5 6