// https://www.geeksforgeeks.org/find-the-two-numbers-with-odd-occurences-in-an-unsorted-array/
// https://practice.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences/0
#include<iostream>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        
        int xor2=a[0];
        int rightMostSet;
        int x=0;
        int y=0;
        for(int i=1;i<n;i++){
            xor2=xor2^a[i];
        }
        
        rightMostSet=xor2 & ~(xor2-1);
        
        for(int i=0;i<n;i++){
            if(a[i]&rightMostSet)
                x=x^a[i];
            else
                y=y^a[i];
        }
        
        if(x>y)
            cout<<x<<" "<<y<<endl;
        else
            cout<<y<<" "<<x<<endl;
    }
	return 0;
}