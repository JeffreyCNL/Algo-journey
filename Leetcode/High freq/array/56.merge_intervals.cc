#include <iostream>
using namespace std;
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <unordered_map>
#include <numeric>
#include <bits/stdc++.h>
#include <unordered_set>

/*
    https://leetcode.com/problems/merge-intervals/

*/

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return {};
    int n = intervals.size();
    if (n == 1)
        return {intervals[0]};
    vector<vector<int>> ret;
    // sorted from the start time
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
        return a.front() < b.front();
    });
    ret.push_back(intervals[0]);
    for (int i = 1; i < n; ++i)
    {
        // if the end time from the back of the answer is smaller
        // there will be no intersection
        if (ret.back()[1] < intervals[i][0])
        {
            ret.push_back(intervals[i]);
            // other wise we need to decide which one should be the end time of
            // the merge interval.
        }
        else
        {
            ret.back()[1] = max(ret.back()[1], intervals[i][1]);
        }
    }
    return ret;
}

int main()
{

    return EXIT_SUCCESS;
}