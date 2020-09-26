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
    Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
    Input: 

        1 0 1 0 0
        1 0 1 1 1
        1 1 1 1 1
        1 0 0 1 0

    Output: 4


*/
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        // the first row and column when we encounter 1. the max it can get will be 1.
        for (int j = 0; j < m; ++j)
        {
            if (matrix[0][j] == '1')
            {
                dp[0][j] = 1;
                ans = max(ans, dp[0][j]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (matrix[i][0] == '1')
            {
                dp[i][0] = 1;
                ans = max(ans, dp[i][0]);
            }
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    // the up, and the left, and the diagonal will determine the current position.
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans * ans;
    }
};

int main()
{

    return EXIT_SUCCESS;
}