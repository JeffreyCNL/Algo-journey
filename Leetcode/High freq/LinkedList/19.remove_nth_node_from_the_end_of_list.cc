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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
/*
This question ask us to remove the nth node from the end of the list
say 1->2->3->4->5 and n = 2, we need to remove 4 from the list.
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/
class Solution
{
public:
    // one pass solution. We don't have to iterate to the end to find the length of the list
    // instead, using two pointers fast and slow to modify the list.
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head->next)
            return nullptr;
        ListNode *cur = head, *pre = head;
        // move n step further and pre is n step behind,
        // this way we can find the desired remove node
        for (int i = 0; i < n; ++i)
            cur = cur->next;
        // the length is equal to the size of list
        if (!cur)
            return head->next;
        while (cur->next)
        {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }

    // another way to do the function. However, instead of jump over the node, we actually remove it.
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *dummy = head;

        for (int i = 1; i <= n; ++i)
        {
            fast = fast->next;
        }
        if (!fast)
            return head->next;
        while (true)
        {
            if (fast->next == nullptr)
            {
                ListNode *nxt = slow->next->next;
                delete (slow->next);
                slow->next = nxt;
                break;
            }
            slow = slow->next;
            fast = fast->next;
        }

        return dummy;
    }
};

int main()
{

    return EXIT_SUCCESS;
}