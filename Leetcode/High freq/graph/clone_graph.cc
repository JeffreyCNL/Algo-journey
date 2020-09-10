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
https://leetcode.com/problems/clone-graph/
We are given a graph that are undirected graph. We need to make a deep copy of the graph
The graph is given as adjencency list.
*/
class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
/* BFS
The key idea is to make a map to map the orignal one with the copy one.
If already copy, we simply push neighbor into the values' neighbor vector.
*/
class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        // iterative BFS. Using a hash map to determine it traverse throu or not
        if (!node)
            return NULL;
        // clone the root
        Node *clone = new Node(node->val);
        // put in the queue
        queue<Node *> q{{node}};
        unordered_map<Node *, Node *> m;
        // set the clone mapping with root
        m[node] = clone;

        while (!q.empty())
        {
            Node *n = q.front();
            q.pop();
            for (Node *neighbor : n->neighbors)
            {
                if (!m.count(neighbor))
                { // if didn't clone before
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                //after we clone the node itself, it's neighbor list is not
                // completed, we need to push the neighbor inside the value's
                // neighbors array to make it a complete object
                m[n]->neighbors.push_back(m[neighbor]);
            }
        }
        return clone;
    }
};

// DFS
class Solution
{
public:
    Node *dfs(Node *node, unordered_map<Node *, Node *> &m)
    {
        if (!node)
            return NULL;
        if (m.count(node))
            return m[node];
        Node *clone = new Node(node->val);
        m[node] = clone;
        for (Node *neighbor : node->neighbors)
        {
            clone->neighbors.push_back(dfs(neighbor, m));
        }
        return clone;
    }
    Node *cloneGraph(Node *node)
    {
        // recursive DFS
        unordered_map<Node *, Node *> m;
        return dfs(node, m);
    }
};

int main()
{

    return EXIT_SUCCESS;
}