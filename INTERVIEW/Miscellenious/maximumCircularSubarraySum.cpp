#include <bits/stdc++.h>

using namespace std;

int maxSubarraySumCircular(vector<int> &v)
{

    int sum = v[0];
    int maxsum = v[0];
    int tempsum = v[0];
    if (tempsum < 0)
        tempsum = 0;

    //calculating maximum sum
    for (int i = 1; i < v.size(); i++)
    {
        sum += v[i];
        tempsum = max(v[i], tempsum + v[i]);
        maxsum = max(maxsum, tempsum);
        if (tempsum < 0)
            tempsum = 0;
    }

    //calculating mimimum sum
    int minsum = v[0];
    tempsum = v[0];
    if (tempsum > 0)
        tempsum = 0;
    for (int i = 1; i < v.size(); i++)
    {
        tempsum = min(v[i], tempsum + v[i]);
        minsum = min(minsum, tempsum);
        if (tempsum > 0)
            tempsum = 0;
    }
    if (sum == minsum) //this is the condition if all the elements are negative or positive
        return maxsum;
    return max(maxsum, sum - minsum); //return max of wraped sum and unwraped sum
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &x : v)
        {
            cin >> x;
        }

        int res = maxSubarraySumCircular(v);
        cout << res << endl;
    }
    return 0;
}
