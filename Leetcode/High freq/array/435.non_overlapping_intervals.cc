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
    https://leetcode.com/problems/non-overlapping-intervals/
    Given a collection of intervals, find the minimum number of intervals you 
    need to remove to make the rest of the intervals non-overlapping.
    Greedy question.
*/
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int ans = 0, n = intervals.size(), last = 0;
        // just different ways to sort
        // we sort for the acending order of start time in the intervals.
        // sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
        //     return a[0] < b[0];
        // });

        auto cmp = [](vector<int> &a, vector<int> &b) {
            return a.front() < b.front();
        };
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 1; i < n; ++i)
        {
            // if the start time is less than the last one's end time
            // we bound to have an overlap, therefore, we need to increment the ans
            if (intervals[i][0] < intervals[last][1])
            {
                ans++;
                // we want to remove the intervals with maximum end time to minimize the
                // intervals we need to remove. Instead of actually removing it, we use a
                // pointer to point out where is the last point we iterate
                if (intervals[i][1] < intervals[last][1])
                    last = i;
            }
            else
            {
                last = i;
            }
        }
        return ans;
    }
};

int main()
{

    return EXIT_SUCCESS;
}