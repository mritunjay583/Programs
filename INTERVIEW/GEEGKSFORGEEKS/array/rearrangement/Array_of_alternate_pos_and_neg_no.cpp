#include<bits/stdc++.h>

using namespace std;




//space O(1)
//time O(n)
//this will not preserve relative order of elments
//using quick partition
void rearrange_2(vector<int> v)
{
    // this is stl partition mechanism 
    //you can use partiotion algorithm of Quick Sort
    //this is not stable
    partition(v.begin(),v.end(),[](int x)
    {
        return x>=0;
    });
    int x=partition_point(v.begin(),v.end(),[](int x)
    {
        return x>=0;
    })-v.begin();
    
    // swapping starts
    int i=0;
    int j=x;
    for(int i=1;i<v.size() && j<v.size();i+=2)
    {
        swap(v[i],v[j]);
        j++;
    }
    for(auto x:v)cout<<x<<" ";cout<<endl;

}


//this will maintain relative order of elment
// space O(n)
//time O(n)
void rearrange_1(vector<int> v)
{
        vector<int> pos;
	    vector<int> neg;
	    for(int i=0;i<v.size();i++)
	    {
	        if(v[i]>=0)
	            pos.push_back(v[i]);
	        else
	            neg.push_back(v[i]);
	    }
	    int i=0;
	    int j=0;
	    int k=0;
	    while(i<pos.size()&&j<neg.size())
	    {
	        if(k%2==0)
	            v[k++]=pos[i++];
	       else
	            v[k++]=neg[j++];
	    }
	    while(i<pos.size())
	        v[k++]=pos[i++];
        while(j<neg.size())
	        v[k++]=neg[j++];
	   for(auto x:v)cout<<x<<" ";cout<<endl;
}


void rearrange_3(vector<int> v)
{
    
}
int main()
{
    vector<int> v{-1,-1,-2,5,5,5,5,4};
    // rearrange_1(v);
    // rearrange_2(v);
    rearrange_3(v);
}