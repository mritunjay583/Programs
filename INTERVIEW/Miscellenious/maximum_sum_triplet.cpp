// https://www.interviewbit.com/problems/maximum-sum-triplet/
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A)
{
    int mx_val[A.size()];
    mx_val[A.size() - 1] = 0; //max_val[i] stores max value just righof A[i]
    int mx = A[A.size() - 1];
    for (int i = A.size() - 2; i >= 0; i--)
    {
        mx_val[i] = mx;
        mx = max(mx, A[i]);
    }

    int g_max = INT_MIN;       //contain global max
    set<int, greater<int>> se; //this stores A[k] where k<i in decreasing order
    se.insert(A[0]);
    for (int i = 1; i < A.size() - 1; i++)
    {
        //if A[i] is less than the greatest value to the right side of i
        if (mx_val[i] > A[i])
        {
            int just_less_than_A_i = *se.upper_bound(A[i]);
            int A_i = A[i];
            int greatest_value_to_right_of_A_i = mx_val[i];
            g_max = max(g_max, just_less_than_A_i + A_i + greatest_value_to_right_of_A_i);
            se.insert(A[i]);
        }
    }
    return g_max;
}

int main()
{
    vector<int> v{2,5,3,1,4,9};
    cout<<solve(v)<<endl;
}