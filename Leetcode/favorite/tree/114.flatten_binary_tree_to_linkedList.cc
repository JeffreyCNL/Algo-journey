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
    https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        // keep goint to the left and right till it reach the leaf
        if (root->left)
            flatten(root->left);
        if (root->right)
            flatten(root->right);
        // we need to store where right node to connect it later
        TreeNode *tmp = root->right;
        // assign the right node from the left.
        root->right = root->left;
        // don't forget to reset the left node to nullptr
        root->left = nullptr;
        // after connecting the left node we need to connect the original right node
        // back to the tree. We need to iterate to the end of the node since we
        // don't know how many node in the original left sub tree.
        while (root->right)
        {
            root = root->right;
        }
        root->right = tmp;
    }
};

int main()
{

    return EXIT_SUCCESS;
}