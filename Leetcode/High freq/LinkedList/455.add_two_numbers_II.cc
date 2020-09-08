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

/* the main idea of this solution is to reverse the linkedlist first
and add those numbers together, just like question number 2.
after we get the result, we reverse back to the return value.
Time: O(n) -> reverse + add + reverse
Space: O(n) -> creating nodes
*/
// class Solution {
// public:

//     ListNode* reverseList(ListNode* node){
//       ListNode* cur = node;
//       ListNode* nxt;
//       ListNode* prev = nullptr;
//       // 1 -> 2 -> 3 -> 4
//       while(cur){
//         nxt = cur->next;
//         cur->next = prev;
//         prev = cur;
//         cur = nxt;
//       }
//       return prev;
//     }

//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         // nothing in either one
//         if (!l1) return l2;
//         if (!l2) return l1;
//         // reverse
//         l1 = reverseList(l1);
//         l2 = reverseList(l2);
//         return reverseList(addTwoList(l1, l2));
//     }

//     ListNode* addTwoList(ListNode* l1, ListNode* l2) {
//         ListNode* cur = new ListNode(-1);
//         ListNode* dummy = cur;
//         int carry = 0;
//         while(l1 || l2|| carry){
//           if (l1){
//             carry += l1->val;
//             l1 = l1->next;
//           }
//           if (l2){
//             carry += l2->val;
//             l2 = l2->next;
//           }
//           cur->next = new ListNode(carry % 10);
//           carry /= 10;
//           cur = cur->next;
//         }
//         return dummy->next;
//     }
// };

/* using stack
still O(n) to iterrate all the list nodes, and O(n + m) to store in the stacks
but don't have to reverse again 
*/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;
        // iterate two of the list and put into two stacks
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode *res = new ListNode(0);
        while (!s1.empty() || !s2.empty())
        {
            if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }
            res->val = sum % 10;
            ListNode *head = new ListNode(sum / 10);
            head->next = res;
            res = head;
            sum /= 10;
        }
        return res->val == 0 ? res->next : res;
    }
};

int main()
{

    return EXIT_SUCCESS;
}