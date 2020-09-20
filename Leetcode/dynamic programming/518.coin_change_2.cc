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
    https://leetcode.com/problems/coin-change-2/
    You are given coins of different denominations and a total amount of money. 
    Write a function to compute the number of combinations that make up that amount. 
    You may assume that you have infinite number of each kind of coin.

    amount = 5, coins = [1, 2, 5]
    output:4
    Explanation: there are four ways to make up the amount:
    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1
*/

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 1;
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins)
        {
            for (int i = coin; i < dp.size(); ++i)
            {
                // every amount is based on the previous amount
                // we from "coin" step forward, we can find the previous step
                // to that amount. Sum it up, we will get the answer.
                dp[i] += dp[i - coin];
            }
        }
        return dp.back();
    }
};

int main()
{

    return EXIT_SUCCESS;
}