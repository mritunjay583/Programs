//https://practice.geeksforgeeks.org/problems/euler-totient-function/0


#include<iostream>
#define MAX 100001
using namespace std;

int phi[MAX]; /// storing value till phi(MAX)

void init()
{
    for(int i=0;i<MAX;i++)
        phi[i]=i;   // initially

    for(int i=2;i<=MAX;i++)  
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;  // if i is prime then phi(i)=i-1

            for(int j=2*i;j<=MAX;j+=i)
            {
                phi[j]=(phi[j]*(i-1))/i;
            }
        }
    }
}
int main()
 {
    init();
    int n=5434;
    cout<<"phi("<<n<<") = "<<phi[n]<<endl;
	return 0;
}
