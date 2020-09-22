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
    https://leetcode.com/problems/meeting-rooms-ii/
    Given an array of meeting time intervals consisting of start and end times 
    [[s1,e1],[s2,e2],...] (si < ei), 
    find the minimum number of conference rooms required.

    A classic greedy algorithm problem. The gist idea is always taking
    the earliest start events so that we can use the least rooms.

    My approach is to use priority queue to store the minimum end time
    so that when the next event comes in, we are aware of where this
    event can be place. If the upcoming event happen earlier than
    the minimum end time event. We need another room.

    The idea can be use by TreeMap to store the value since it is already sorted.
*/

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            if (a.front() == b.front())
            {
                return a.back() < b.back();
            }
            else
            {
                return a.front() < b.front();
            }
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        int ans = 1;
        for (int i = 1; i < intervals.size(); ++i)
        {
            // minmum end time greater than the start time
            if (intervals[i].front() < pq.top())
            {
                ans++;
            }
            else
            {
                pq.pop();
            }
            pq.push(intervals[i].back());
        }
        return ans;
    }
};
int main()
{

    return EXIT_SUCCESS;
}