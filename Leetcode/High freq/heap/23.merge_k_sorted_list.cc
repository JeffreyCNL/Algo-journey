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

/**
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

https://leetcode.com/problems/merge-k-sorted-lists/

The idea for this question is putting the node into pq and this way we can return by the top element as a sorted list.
The point of this question is to figure out how to get the sorting from small to large for ListNode* in priority_queue
 * 
 * 
 * 
*/
class Solution
{
public:
    // print funciton for printing priority queue
    template <typename T>
    void print_queue(T &q)
    {
        while (!q.empty())
        {
            // std::cout << q.top()->val << " ";
            std::cout << q.top() << " ";
            q.pop();
        }
        std::cout << '\n';
    }

    // my test to see the sorting direciotn of self lambda function
    void test(vector<int> &v)
    {
        auto cmp = [](int &a, int &b) {
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for (auto i : v)
        {
            pq.push(i);
        }
        print_queue(pq);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = [](ListNode *a, ListNode *b) {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp);
        for (auto node : lists)
        {
            if (node)
            {
                q.push(node);
            }
        }
        // print_queue(q);
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (!q.empty())
        {
            ListNode *n = q.top();
            q.pop();
            cur->next = n;
            cur = cur->next;
            if (cur->next)
                q.push(cur->next);
        }
        return dummy->next;
    }
};

// divide and conquer solution
/*
    the key idea is to merge two list together and keep merging until theres only one.
    Merging two lists should be easy.
    we use a for loop to merge them together
*/
// divide and conquer solution
/*
    the key idea is to merge two list together and keep merging until theres only one.
    Merging two lists should be easy.
    we use a for loop to merge them together
*/
class Solution
{
public:
    ListNode *mergeTwoList(ListNode *l1, ListNode *l2)
    {
        ListNode *cur = new ListNode(-1);
        ListNode *dummy = cur;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        int len = lists.size();
        // if there's more than one list exists, keep merging
        while (len > 1)
        {
            for (int i = 0; i < len / 2; ++i)
            {
                // merging from the start-> middle, middle<-end directions.
                lists[i] = mergeTwoList(lists[i], lists[len - 1 - i]);
            }
            // after we merge, there's only half of them left.
            // the reason why we plus one is to prevent odd numbers in the origin list
            // say 3 lists, after merging first and last, it should have 2 left instead of 1.
            len = (len + 1) / 2;
        }
        return lists.front();
    }
};

int main()
{

    return EXIT_SUCCESS;
}