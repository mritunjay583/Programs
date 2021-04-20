#include<bits/stdc++.h>
using namespace std;


// power function to calulate power of x^y
long long int power(int x,int y)
{
    long long int res=1;
    while(y)
    {
        if(y&1)
        {
            res*=x;
        }
        x*=x;
        y/=2;
    }
    return res;

}
int main()
{
  int x=3,y=729;
  int temp=x;
  int i=1;
  if(x==1)
  {
      cout<<y<<" is not power of "<<x;
  }
  else if(y==1)
  {
      cout<<temp<<" ^ "<<0<<" = "<<y;
  }
  else
  {
  while(x<y)
  {
      x=power(temp,i);
      i*=2;
  }
  i/=2;
  if(x==y)
  {
  cout<<temp<<" ^ "<<i<<" = "<<y;
  }
  else
  {
      int low=i/2;
      int high=i;
      int mid=(low+high)/2;
      int flag=0;
      
      // binary search

      while(low<high)
      {
          mid=(low+high)/2;
          if(power(temp,mid)==y)
          {
              flag=1;
              break;
          }
          else
          {
              if(power(temp,mid)>y)
              high=mid;
              else
              low=mid;
          }
      }

      //finding condition

      if(flag=1)
      {
          cout<<temp<<" ^ "<<mid<<" = "<<y;
      }
      else
      {
          cout<<y<<" is not power of "<<x;
      }

  }
  }
    
}