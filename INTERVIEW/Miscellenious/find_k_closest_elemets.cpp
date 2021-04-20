// https://leetcode.com/problems/find-k-closest-elements/

#include <bits/stdc++.h>

using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int l = lower_bound(arr.begin(), arr.end(), x) - arr.begin(); //getting value closest to x
    if (l >= 0 && l < arr.size())
    { //if x if not present in array the it will return element just greater than x
        if (arr[l] != x)
            l--; //so if x is not present in array the decrement l
    }
    int m = l + 1; //second pointer just after l
    vector<int> res;
    int cnt = 0;                                //count the number of elements near to x till now
    while (l >= 0 && m < arr.size() && cnt < k) //move l to left direction and m to right direction
    {
        if (abs(x - arr[l]) <= abs(x - arr[m]))
        {
            res.push_back(arr[l]);
            l--;
        }
        else
        {
            res.push_back(arr[m]);
            m++;
        }
        cnt++;
    }
    while (l >= 0 && cnt < k) //if right pointer is totally exhausted and count is still less than k
    {
        res.push_back(arr[l]);
        l--;
        cnt++;
    }
    while (m < arr.size() && cnt < k) //if left pointer is totally exhausted and count is still less than k
    {
        res.push_back(arr[m]);
        m++;
        cnt++;
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> arr{0, 0, 1, 2, 3, 3, 4, 7, 7, 8};
    int k = 3;
    int x = 5;
    vector<int> output = findClosestElements(arr, k, x);
    for (auto x : output)
    {
        cout << x << " ";
    }
    cout << endl;
}