//only one transaction allowed
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A[] = {100, 180, 260, 310,
               40, 535, 695}; //655

    int n = 7;

    int fb = INT_MIN, fs = 0;

    for (int i = 0; i < n; i++)
    {
        fb = max(fb, -A[i]);
        fs = max(fs, fb + A[i]);
    }

    cout << fs << endl;
}