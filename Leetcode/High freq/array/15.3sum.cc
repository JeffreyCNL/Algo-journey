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

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        // sorting can be efficient for dealing with duplicated number
        // and also can divide the array to <negative, 0 , positive>
        sort(nums.begin(), nums.end());
        // if the beginning is greater than zero or the end is smaller, no way we can have an answer
        if (nums.empty() || nums.front() > 0 || nums.back() < 0 || nums.size() < 3)
            return {};
        for (int k = 0; k < nums.size(); ++k)
        {
            if (nums[k] > 0)
                break;
            // should also deal with duplicated k index value
            if (k > 0 && nums[k] == nums[k - 1])
                continue;
            int target = 0 - nums[k], i = k + 1, j = nums.size() - 1;
            // the other two pointers should meet the target for the answer
            while (i < j)
            {
                if (nums[i] + nums[j] == target)
                {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    while (i < j && nums[i] == nums[i + 1])
                        i++;
                    while (i < j && nums[j] == nums[j - 1])
                        j--;
                    i++;
                    j--;
                }
                else if (nums[i] + nums[j] < target)
                    ++i;
                else
                    --j;
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> nums = {0, 0, 0, 0};

    return EXIT_SUCCESS;
}