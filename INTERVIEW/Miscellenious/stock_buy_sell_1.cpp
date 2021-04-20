//as many transaction as you want
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A[] = {100, 180, 260, 310,
               40, 535, 695};

    int n = 7;
    int profit = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] < A[i + 1])
        {
            profit += A[i + 1] - A[i];
        }
    }

    cout << profit << endl;
}