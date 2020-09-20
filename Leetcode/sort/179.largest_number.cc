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
    Given a list of non negative integers, 
    arrange them such that they form the largest number.

    Input: [3,30,34,5,9]
    Output: "9534330"

    Thought process:
        a large first digit will give us a large result. Therefore, we need to sort it 
        for the largest first and make it to the return string. However, we knwo that
        we can directly compare with the string. Therefore, make the pair add up together
        will give us the solution
    Edge cases:
        there might be leading zero. But there
*/

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        if (nums.empty())
            return "";
        vector<string> tmp(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            tmp[i] = to_string(nums[i]);
        }
        sort(tmp.begin(), tmp.end(), [&](string a, string b) {
            return (a + b) > (b + a);
        });
        string ans = "";
        for (auto s : tmp)
        {
            // get rid of leading zeros
            if (ans.empty() && s == "0")
                continue;
            ans += s;
        }
        // if all zeros in the nums
        return ans.empty() ? "0" : ans;
    }
};
int main()
{

    return EXIT_SUCCESS;
}