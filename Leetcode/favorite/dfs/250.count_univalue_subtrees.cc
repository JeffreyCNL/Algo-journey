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
    Given the root of a binary tree, return the number of uni-value subtrees.
    A uni-value subtree means all nodes of the subtree have the same value.

    Input: root = [5,1,5,5,5,null,5]
    Output: 4

    Based on the problem we can know that leaves must be the answer.

*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int countUnivalSubtrees(TreeNode *root)
    {
        int ans = 0;
        helper(root, ans);
        return ans;
    }

    bool helper(TreeNode *node, int &ans)
    {
        if (!node)
            return true;
        // going down to the left and right to check it's subtrees
        bool sameLeft = helper(node->left, ans);
        bool sameRight = helper(node->right, ans);
        // cout << sameLeft << " " << sameRight << endl;
        // if the subtree return True for both left and right
        // and value on the parent is the same as left and right, we should increment the answer.
        if ((sameLeft && sameRight) && (!node->left || node->left->val == node->val) && (!node->right || node->right->val == node->val))
        {
            ans++;
            return true;
        }
        return false;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(5);
    Solution *obj = new Solution();
    cout << obj->countUnivalSubtrees(root) << endl;
    return EXIT_SUCCESS;
}