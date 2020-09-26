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
    https://leetcode.com/problems/find-leaves-of-binary-tree/
    Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
    Input: [1,2,3,4,5]
  
          1
         / \
        2   3
       / \     
      4   5    

    Output: [[4,5,3],[2],[1]]

    The key idea for this question is to find the layer from the leaves. and the leaves is from the 0 layer.
    We can use the layer as index to find each node's layer, use the idex to put into the answer.

*/
class Solution
{
public:
    vector<vector<int>> findLeaves(TreeNode *root)
    {
        vector<vector<int>> ans;
        helper(root, ans);
        return ans;
    }

    int helper(TreeNode *node, vector<vector<int>> &ans)
    {
        if (!node)
            return -1;
        int l = helper(node->left, ans);
        int r = helper(node->right, ans);
        // the idex should be determined by whichever has higher layer value.
        int idx = max(l, r) + 1;
        if (idx >= ans.size())
        {
            ans.push_back({node->val});
        }
        else
        {
            ans[idx].push_back(node->val);
        }
        return idx;
    }
};
int main()
{

    return EXIT_SUCCESS;
}