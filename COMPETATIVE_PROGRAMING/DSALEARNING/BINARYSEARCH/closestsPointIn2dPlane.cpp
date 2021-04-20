/*input
5
0 0
1 1
-1 -1
2 40
100 3
*/

#include <bits/stdc++.h>
using namespace std;
struct point
{
    int id;
    int x, y;
};

float dis(point A, point B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

tuple<int, int, float> closestDistance(vector<point> &P, int st, int en)
{
    if (abs(st - en) <= 3)
    {
        float mi = FLT_MAX;
        int m, n;
        for (int i = st; i <= en; i++)
        {
            for (int j = i + 1; j <= en; j++)
            {
                if (mi > dis(P[i], P[j]))
                {
                    mi = dis(P[i], P[j]);
                    m = P[i].id;
                    n = P[j].id;
                }
            }
        }
        return make_tuple(m, n, mi);
    }
    int mid = (st + en) / 2;
    tuple<int, int, float> leftMin = closestDistance(P, st, mid);
    tuple<int, int, float> rightMin = closestDistance(P, mid + 1, en);
    float d;
    int m, n;
    if ((get<2>(leftMin)) < (get<2>(rightMin)))
    {
        d = get<2>(leftMin);
        m = get<0>(leftMin);
        n = get<1>(leftMin);
    }
    else
    {
        d = get<2>(rightMin);
        m = get<0>(rightMin);
        n = get<1>(rightMin);
    }

    vector<point> strip;
    int median = P[mid].x;   
    for (int i = st; i <= en; i++)
    {
        if (abs(P[i].x - median) < d)
        {
            strip.push_back(P[i]);
        }
    }
    sort(strip.begin(), strip.end(), [](point A, point B) -> bool {
        return A.y < B.y;
    });

    float minLeftRight = FLT_MAX;
    int r, s;
    for (int i = 0; i < strip.size(); i++)
    {
        for (int j = i + 1; j < strip.size() && strip[j].y - strip[i].y < d; j++)
        {
            if (minLeftRight > dis(strip[i], strip[j]))
            {
                minLeftRight = dis(strip[i], strip[j]);
                r = strip[i].id;
                s = strip[j].id;
            }
        }
    }
    if (d < minLeftRight)
        return make_tuple(m, n, d);
    else
        return make_tuple(r, s, minLeftRight);
}
int main()
{
    int n;
    cin >> n;
    vector<point> P;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        P.push_back({i, x, y});
    }
    sort(P.begin(), P.end(), [](point A, point B) -> bool {
        return A.x < B.x;
    });
    tuple<int, int, float> res = closestDistance(P, 0, P.size() - 1);
    cout << get<0>(res) << " " << get<1>(res) << " ";
    cout << std::fixed;
    cout << get<2>(res) << endl;
    return 0;
}
