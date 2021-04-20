#include <bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX], int n);

int main()
{
    int T;
    cin >> T;
    int M[MAX][MAX];
    while (T--)
    {
        int N;
        cin >> N;
        memset(M, 0, sizeof M);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> M[i][j];
            }
        }
        cout << getId(M, N) << endl;
    }
}

#include <bits/stdc++.h>
int getId(int mat[MAX][MAX], int n)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (mat[i][j] == 1)
        {
            i++;
        }
        else
            j--;
    }

    for (int k = 0; k < n; k++)
    {
        if ((i != k) && (mat[i][k] == 1 || mat[k][i] == 0))
            return -1;
    }

    return i;
}
