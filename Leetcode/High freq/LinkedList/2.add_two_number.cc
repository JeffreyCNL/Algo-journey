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

// class Solution{
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
//         if (!l1) return l2;
//         if (!l2) return l1;
//         ListNode* ret = new ListNode(-1);
//         ListNode* cur = ret;
//         int carry = 0;
//         while(l1 || l2){
//             int v1 = l1 ? l1->val : 0;
//             int v2 = l2 ? l2->val : 0;
//             int sum = v1 + v2 + carry;
//             carry = sum / 10;
//             cur->next = new ListNode(sum % 10);
//             cur = cur->next;
//             l1 = l1 ? l1->next : l1;
//             l2 = l2 ? l2->next : l2;
//         }
//         if (carry) cur->next = new ListNode(carry);
//         return ret->next;
//     }
// };

int main()
{

    return EXIT_SUCCESS;
}