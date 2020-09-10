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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
The question is to find all the node that is K distance away than the target node.
My approach is to find the target first, and build a map between child->parent.
And use the target node to do the BFS to find the layer that is K distance away.
The usage of the map is to link child back to parent since we don't have access for it/
*/
class Solution
{
public:
    void clear(queue<TreeNode *> &q)
    {
        while (!q.empty())
        {
            q.pop();
        }
    }

    /* find the target in the node and construct the map
     the map is for getting the access from child to parent, so 
     so it's <child->parent>
  */
    void findTarget(queue<TreeNode *> &q, TreeNode *&target, unordered_map<TreeNode *, TreeNode *> &m)
    {
        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            if (t->left)
            {
                m[t->left] = t;
                q.push(t->left);
            }
            if (t->right)
            {
                m[t->right] = t;
                q.push(t->right);
            }
            if (t == target)
            {
                clear(q);
                q.push(t);
                break;
            }
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        if (!root)
            return {};
        unordered_map<TreeNode *, TreeNode *> m;
        queue<TreeNode *> q{{root}};
        findTarget(q, target, m);
        int level = 0;
        vector<int> ans;
        unordered_set<TreeNode *> visited;
        while (!q.empty())
        {
            int size = q.size();
            // traverse level by level
            for (int i = size; i > 0; --i)
            {
                TreeNode *t = q.front();
                visited.insert(t);
                q.pop();
                // once we are in the level we are looking for, push the node's value to the answer
                if (level == K)
                {
                    ans.push_back(t->val);
                    continue;
                }
                if (t->left && !visited.count(t->left))
                    q.push(t->left);
                if (t->right && !visited.count(t->right))
                    q.push(t->right);
                // we can find the node's parent in the map, which count as next level.
                if (m.count(t) && !visited.count(m[t]))
                    q.push(m[t]);
            }
            level++;
        }

        return ans;
    }
};

int main()
{

    return EXIT_SUCCESS;
}