#include<bits/stdc++.h>
#define MAX 1000004
using namespace std;

int arr[MAX];

void solution2(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[a[i]]++;
    }
    for (int i = MAX; i >= 0; i--)
    {
        int d = 0;
        for (int j = i; j <= MAX; j += i)
            d += arr[j];
        if (d > 1)
        {
            cout << i << endl;
            return;
        }
    }
}

void solution1(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= (int)sqrt(a[i]); j++)
        {
            if (a[i] % j == 0)
            {
                arr[j]++;
                if (j != a[i] / j)
                {
                    arr[a[i] / j]++;
                }
            }
        }
    }
    for (int i = MAX; i >= 0; i--)
    {
        if (arr[i] > 1)
        {
            cout << i << endl;
            return;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solution2(a, n);
    return 0;
}