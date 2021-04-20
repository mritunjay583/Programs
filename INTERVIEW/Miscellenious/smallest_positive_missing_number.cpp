// Smallest Positive missing number
// https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number/0

#include <bits/stdc++.h>
using namespace std;

int segregate(int a[], int n)
{
    int j = 0;
    int i;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    return j;
}

int solve(int a[], int n)
{
    //segregate positive and negative
    int id = segregate(a, n);

    a = a + id; //separting positive and negative part of array
    n = n - id; // size of array must be reduced
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i]) - 1 < n)
        { // if abs(a[i])-1 lies in range
            if (a[abs(a[i]) - 1] > 0)
            {
                a[abs(a[i]) - 1] = -a[abs(a[i]) - 1]; //visiting the particular index
            }
        }
    }
    int i=0;
    for (i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            return i + 1; //missing number
        }
    }
    return i + 1; //missing number
}
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int res = solve(a, n);
        cout << "smallest missing number : " << res << endl;
    }
    return 0;
}

// input sample
// //2
// 5
// 1 2 3 4 5
// 5
// 0 -10 1 3 -20