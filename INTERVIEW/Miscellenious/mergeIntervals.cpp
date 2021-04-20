// https://leetcode.com/problems/merge-intervals/submissions/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() <= 1)
        return intervals;

    sort(intervals.begin(), intervals.end()); // first sort the intervals

    vector<vector<int>> res;
    for (int i = 0; i < intervals.size() - 1; i++)
    {
        //if intervals[i] and intervals[i+1] does not overlap then store intervals[i] in res vector
        if (max(intervals[i][0], intervals[i + 1][0]) > min(intervals[i][1], intervals[i + 1][1]))
        {
            res.push_back(intervals[i]);
        }
        else
        { //if intervals[i] and intervals[i+1] overlaps then merge intervals and store in intervals[i+1]
            intervals[i + 1][0] = min(intervals[i][0], intervals[i + 1][0]);
            intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
        }
    } //store last interval in res vector
    res.push_back(intervals[intervals.size() - 1]);
    return res;
}

int main()
{
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res = merge(intervals);
    cout << "{";
    for (auto x : res)
    {
        cout << "{" << x[0] << "," << x[1] << "}";
        cout << ",";
    }
    cout << "}" << endl;
}