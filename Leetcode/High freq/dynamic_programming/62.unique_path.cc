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
    Given a grid. A robot started from the top-left corner,
    We have to find a way to go to the finish point which is
    the bottom-right corner.
    return how many unique way to get there.

    https://leetcode.com/problems/unique-paths/
*/
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // since the path is always based on the left and top,
        // we can find the dynamic transform function
        vector<vector<int>> dp(n, vector<int>(m, 1));
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n - 1][m - 1];
    }
};

//     int uniquePaths(int m, int n) {
//         // better space complexity O(n)
//         vector<int> dp(n,1);
//         for (int i = 1; i < m; i++){
//             for (int j = 1; j < n; j++){
//                 dp[j] += dp[j - 1];
//             }
//         }
//         return dp[n - 1];
int main()
{

    return EXIT_SUCCESS;
}