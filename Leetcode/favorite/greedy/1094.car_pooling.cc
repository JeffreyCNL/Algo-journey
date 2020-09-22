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
    https://leetcode.com/problems/car-pooling/
    We are given trips and capacity.trips, 
    trip[i] = [num_passengers, start_location, end_location]
    contains information about the i-th trip: the number of passengers 
    that must be picked up, and the locations to pick them up and drop them off.  
    The locations are given as the number of kilometers due east from 
    your vehicle's initial location.

    This is a similar problem with 253. meeting room
    A greedy algorithm approach will work.
    Sort by the start position and we have to take the passenger along the way.
    We need to know whether we can drop of somebody so we
    need a priority queue to store them.
    Keep in mind that we need to keep poping out the priority queue
    as long as the current start position is greater than the top one
    on the priotiry queue.

    The priority queue was sorted by the least end position on the top.
*/

class Solution
{
public:
    struct cmp
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.first > b.first;
        }
    };

    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        sort(trips.begin(), trips.end(), [&](vector<int> &a, vector<int> &b) {
            if (a[1] == b[1])
            {
                return a[2] < b[2];
            }
            else
            {
                return a[1] < b[1];
            }
        });
        int curCapacity = capacity - trips[0].front();
        // minimum endpoint, # passenger for that point
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        pq.push({trips[0][2], trips[0][0]});
        for (int i = 1; i < trips.size(); ++i)
        {
            int passenger = trips[i][0], start = trips[i][1], end = trips[i][2];
            // as long as the ith trip start later than the trip before
            // we can always take back the capacity along the way
            while (!pq.empty() && start >= pq.top().first)
            {
                curCapacity += pq.top().second;
                pq.pop();
            }
            curCapacity -= passenger;
            pq.push({end, passenger});
            // if we take the passenger on ith trip and it become negative, we can not complete the trip
            if (curCapacity < 0)
                return false;
        }
        return true;
    }

    // void print(priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq){
    //     stack<pair<int, int>> st;
    //     while(!pq.empty()){
    //         cout << pq.top().first << " " << pq.top().second << endl;
    //         st.push(pq.top());
    //         pq.pop();
    //     }
    //     while(!st.empty()){
    //         pq.push(st.top());
    //         st.pop();
    //     }
    // }
};

int main()
{

    return EXIT_SUCCESS;
}