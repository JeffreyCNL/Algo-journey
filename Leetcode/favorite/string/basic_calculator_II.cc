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
https://leetcode.com/problems/basic-calculator-ii/
Input: "3+2*2"
Output: 7

Input: "3+2*2"
Output: 7

Input: " 3+5 / 2 "
Output: 5
*/
class Solution
{
public:
    int calculate(string s)
    {
        // this will prevent sign integer overflow for INT_MAX
        long ret = 0, num = 0, n = s.size();
        stack<int> st;
        char op = '+';
        // this is the same idea as my sol but i dunno how to implement it
        // insted of using many while to form the number, simply use another
        // if to prevent it
        // also the op is important
        // since when we meet an operation
        // we need to see the next number to calculate
        // therefore, we need to keep track of the previous operation sign
        for (int i = 0; i < n; ++i)
        {
            // if it's digit, keep adding up the number until we get the number itself
            if (s[i] >= '0')
            {
                num = num * 10 + s[i] - '0';
            }
            // do the operation when it reach to the end.
            // or when it's operation sign
            if ((s[i] < '0' && s[i] != ' ') || i == n - 1)
            {
                if (op == '+')
                    st.push(num);
                if (op == '-')
                    st.push(-num);
                if (op == '*' || op == '/')
                {
                    int tmp = st.top();
                    st.pop();
                    op == '*' ? st.push(tmp * num) : st.push(tmp / num);
                }
                // we need to keep update the operation sign
                // this way we know what to do when next number show up
                op = s[i];
                num = 0;
            }
        }
        // we need to make sure that multiplication and division first.
        // therefore we only push to the stack when we see +, -
        // and sum up all the numbers in the end.
        while (!st.empty())
        {
            ret += st.top();
            st.pop();
        }
        return ret;
    }
};

int main()
{

    return EXIT_SUCCESS;
}