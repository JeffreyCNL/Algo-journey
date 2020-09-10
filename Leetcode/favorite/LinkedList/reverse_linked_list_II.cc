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

// https://leetcode.com/problems/reverse-linked-list-ii/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
The goal of this problem is to reverse the linked list in a specific range.
*/
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        // some edge cases
        if (!head)
            return nullptr;
        if (m == n)
            return head;
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        ListNode *dummy = pre;
        // move to the one node before reverse list
        for (int i = 0; i < m - 1; ++i)
            pre = pre->next;
        ListNode *cur = pre->next;
        for (int i = m; i < n; ++i)
        {
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
        return dummy->next;
    }
};
int main()
{

    return EXIT_SUCCESS;
}
