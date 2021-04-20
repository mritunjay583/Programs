#include<bits/stdc++.h>

using namespace std;

int assign(int cost[4][4],int n,int ithperson,int mask,int min_cost,unordered_map<int,int> &dp)
{
    if(ithperson>=4)
    {
        return 0;
    }
    if(dp.count(mask)>0)
    {
        return dp[mask];
    }
    for(int i=0;i<n;i++)
    {
        if(!((1<<i)&mask))
        {
            int next_person=ithperson+1;
            int res=assign(cost,n,next_person,mask|(1<<i),min_cost,dp)+cost[ithperson][i];
            dp[mask]=res;
            if(min_cost>res)
            {
                min_cost=res;
            }
        }
    }
    return min_cost;
}

int main()
{
    int cost[4][4]={{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};
    int number_of_person=4;
    int min_cost=INT_MAX;
    unordered_map<int,int> dp;  //for memoization
    int mask=0; // initial mask is 0000
    int first_person=0;
    min_cost=assign(cost,number_of_person,first_person,mask,min_cost,dp);
    cout<<min_cost<<endl;
}

/*
        JOBS
       j1 | j2 | j3 | j4
  p1  |10 | 2  | 6  | 5                
  p2  |1  | 15 | 12 | 8                // persons
  p3  |7  | 8  | 9  | 3                 
  p4  |15 | 13 | 4  | 10                 

  */