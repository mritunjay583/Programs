// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

#include<bits/stdc++.h>

using namespace std;


//brute force complexity O(n*n*n)
vector<int> old_smallestRange(vector<vector<int>>& a) {
    int k=a.size();
    vector<pair<int,int> > t;
        
    for(int i=0;i<k;i++){
        t.push_back(make_pair(0,a[i].size()));
    }
        
    int min_range=INT_MAX;
    int left;
    int right;
    vector<int> res;
    int flag=0;
    while(1){
        int minind=-1;
        int min_val=INT_MAX;
        int max_val=INT_MIN;
        for(int i=0;i<k;i++){
            
            if(t[i].first==t[i].second){
               flag=1;
               break; 
            }
            
            if(t[i].first<t[i].second && a[i][t[i].first]>max_val){
                max_val=a[i][t[i].first];
            }
            
            if(t[i].first<t[i].second && a[i][t[i].first]<min_val){
                minind=i;
                min_val=a[i][t[i].first];
            }
        
        }
        if(flag==1)
            break;
        t[minind].first++;
        if(max_val-min_val<min_range){
            left=min_val;
            right=max_val;
            min_range=max_val-min_val;
        }
    }
        res.push_back(left);
        res.push_back(right);
        return res;
}

//optimized O(n*logn)
vector<int> smallestRange(vector<vector<int>>& a) {
        multiset<array<int,4> > se; // 0 value 1 start 2 end 3 ith

        for(int i=0;i<a.size();i++){
            se.insert({a[i][0],0,(int)a[i].size(),i});
        }

        int min_range=INT_MAX;//to compare min range
        int low,high; // to store range
        while(1){ //run this loop untill one of the list exhaust

            array<int,4> x=*se.begin(); //get minimum value 
            array<int,4> y=*se.rbegin(); //get maximum value
            if(min_range>y[0]-x[0]){ //update minrange, low and high
                low=x[0];
                high=y[0];
                min_range=y[0]-x[0];
            }
            se.erase(x); //erase minimum from array 
            if(x[1]==x[2]-1) //if one of the list exhausted break out from the loop
                break;
            se.insert({a[x[3]][x[1]+1],x[1]+1,x[2],x[3]});  // increment pointer minimum element list
        } 
        return vector<int>({low,high});
}

int main(){
    vector<vector<int> > input{{4,10,15,24,26}, 
                                {0,9,12,20}, 
                                {5,18,22,30}};
    
    vector<int> res=smallestRange(input);
    cout<<res[0]<<" "<<res[1]<<endl;

}