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

// the key point is to find out where it rotate
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.empty())
            return -1;
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            // if middle point is greater the rightmost point.
            // meaning that there must be smaller element in the left side
            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        // cout << l << " " << r << endl;
        return nums[l];
    }
};

int main()
{

    return EXIT_SUCCESS;
}