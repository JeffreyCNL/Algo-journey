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
    https://leetcode.com/problems/decode-ways/
    A message containing letters from A-Z is being 
    encoded to numbers using the following mapping:

    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26
    Given a non-empty string containing only digits, 
    determine the total number of ways to decode it.

    Input: "226"
    Output: 3
    Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
class Solution
{
public:
    // O(n), O(n)
    int numDecodings(string s)
    {
        if (s[0] == '0' || s.empty())
            return 0;
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;

        for (int i = 1; i < dp.size(); ++i)
        {
            // if the char before is zero, there's no way we
            // can come up with another mapping
            if (s[i - 1] == '0')
            {
                dp[i] = 0;
            }
            else
            {
                // all the one is based on the previous value
                dp[i] = dp[i - 1];
            }
            // however, we can have 10s and 20s except the one over 26
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
int main()
{

    return EXIT_SUCCESS;
}