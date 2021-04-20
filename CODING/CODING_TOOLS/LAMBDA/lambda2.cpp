#include<bits/stdc++.h>

using namespace std;
int main()
{
    
    auto greater=[](auto x,auto y)->bool{
        return x>y;
    };

    auto print=[](const auto &vt)
    {
          for(auto x:vt)cout<<x<<" ";cout<<endl;
    };
    vector<int> v1{5,2,8,12,8,4,3,7};
    vector<float> v2{6.2,6.4,1.2,7.2};
    vector<string> v3={"sahil","ankur","rishika","avantika"};

    sort(v1.begin(),v1.end(),greater);
    sort(v2.begin(),v2.end(),greater);
    sort(v3.begin(),v3.end(),greater);
    print(v1);
    print(v2);
    print(v3);

    vector<int> v{1,2,3,4,5};
    vector<int> cum_sum(v.size());

    partial_sum(v.begin(),v.end(),cum_sum.begin(),[](int x,int y)
    {
        return x*y;
    });
    // here you can use same container's beginning iterator
    //in third parameter
    print(cum_sum);

    vector<int> nums{1,2,3,4,5};
    int to_add=5;
    transform(nums.begin(),nums.end(),nums.begin(),[to_add](int x){return x+to_add;});
    print(nums);


    //// partion using stl partition
    vector<int> nums2{5,2,3,1,6,7,1,6,3};
    int x=nums2[0];
    auto in=partition(nums2.begin(),nums2.end(),[x](int y)
    {
        return y<x;
    });
    print(nums2); // array/vector after partioned
    cout<<*in; // partitioned element in which all elments
                //greater and equal to x on right side
                // and all lesser than x on left side
}