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
    https://leetcode.com/problems/is-graph-bipartite/
    We have to know bipartite first.
    Recall that a graph is bipartite if we can split it's set of nodes into
    two independent subsets A and B such that every edge in the graph has one 
    node in A and another node in B.

    
*/

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        // the method is to color the nodes
        vector<int> colors(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i)
        {
            // if we have already color the node before,
            // there's no need to check it again.
            if (colors[i] != 0)
                continue;
            // color the node we face to be 1
            colors[i] = 1;
            queue<int> q{{i}};
            while (!q.empty())
            {
                int t = q.front();
                q.pop();
                for (auto a : graph[t])
                {
                    // the one we face and the one it connects in the same group
                    if (colors[a] == colors[t])
                        return false;
                    if (colors[a] == 0)
                    {
                        // make it the oppsite color
                        colors[a] = -1 * colors[t];
                        q.push(a);
                    }
                }
            }
        }
        return true;
    }
};

int main()
{

    return EXIT_SUCCESS;
}