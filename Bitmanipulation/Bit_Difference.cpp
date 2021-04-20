// https://www.geeksforgeeks.org/swap-bits-in-a-given-number/
// https://practice.geeksforgeeks.org/problems/bit-difference/0

#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    
	    int x=a^b;
	    
	    int cnt=0;
	    while(x>0){
	        cnt++;
	        x &=(x-1);
	    }
	    cout<<cnt<<endl;
	}
	return 0;
}