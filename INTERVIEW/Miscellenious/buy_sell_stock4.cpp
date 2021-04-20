// /K transction transaction allowed
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A[] = {3, 2, 6, 5, 0, 3}; //655

    int n = 6;

    int k = 2;

    int buy[k] = {INT_MIN};
    int sell[k] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            buy[j] = max(buy[j], j == 0 ? 0 - A[i] : sell[j - 1] - A[i]);
            sell[j] = max(sell[j], buy[j] + A[i]);
        }
    }

    cout << sell[k - 1] << endl;
}