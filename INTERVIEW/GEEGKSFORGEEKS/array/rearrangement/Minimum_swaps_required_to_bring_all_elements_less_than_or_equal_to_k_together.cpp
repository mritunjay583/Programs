
// Minimum swaps required 
// to bring all elements less than or equal to k together
#include<bits/stdc++.h>

using namespace std;

void number_of_swaps(vector<int> &v,int k)
{

    int cnt=count_if(v.begin(),v.end(),[k](int x)
    {
        return x<=k;
    });

    int i=0;
    int j=0;

    int bad=0;
    int mi=INT_MAX;
    while(j<cnt)
    {
        if(v[j]>k)
            bad++;
        j++;
    }
    mi=min(mi,bad);
    while(j<v.size())
    {
        if(v[i]>k)
            bad--;
        if(v[j]>k)
            bad++;
        mi=min(mi,bad);
        j++;
        i++;
    }
    cout<<"number of swaps required "<<min(mi,bad)<<endl;

}
int main()
{
    vector<int> v{2, 1, 5, 6, 3};
    int k=3;
    number_of_swaps(v,k);
}