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
  	Think about climbing stairs question.
	The difference is we can only step 1 or 2 in the climbing stair problem. 
	Here, we have multiple size of steps to reach to the target. 
	Therefore, we need to iterate the nums vector and check the smaller number
	as the corner stone to reach the final target.

    example nums = {1, 2, 3}, target = 4
    {(1, 1, 1, 1)
    (1, 1, 2)
    (1, 2, 1)
    (1, 3)
    (2, 1, 1)
    (2, 2)
    (3, 1)} => return 7
*/
int combinationSum4(vector<int> &nums, int target)
{
    /* sorting is used to minimize the run time for iterating through the nums.
        Once we reach number greater than the target we are looking for, there's no need to search for the rest.
    */
    sort(nums.begin(), nums.end());
    // use unsigned long to prevent integer overflow
    vector<unsigned long> dp(target + 1, 0);
    // standing on the ground also count as one way.
    dp[0] = 1;
    for (int i = 1; i <= target; ++i)
    {
        int ways = 0;
        for (int j = 0; j < nums.size(); ++j)
        {
            int remain = i - nums[j];
            if (remain < 0)
                break;
            // the way it can reach the point are always start from the smaller number
            ways += dp[remain];
        }
        dp[i] = ways;
    }
    return dp[target];
}

int main()
{

    return EXIT_SUCCESS;
}