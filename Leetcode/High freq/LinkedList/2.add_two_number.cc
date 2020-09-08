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

class Solution
{
public:
    // time: O(n + m)
    // space: O(n + m) for creating nodes
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // nothing for either one. Just return it.
        if (!l2)
            return l1;
        if (!l1)
            return l2;

        ListNode *cur = new ListNode(-1);
        ListNode *dummy = cur;
        // use only one integer to store the value
        int carry = 0;
        while (l1 || l2 || carry)
        {
            if (l1)
            {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                carry += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(carry % 10);
            carry /= 10;
            cur = cur->next;
        }
        return dummy->next;
    }
};

int main()
{

    return EXIT_SUCCESS;
}