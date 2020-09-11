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

// https://leetcode.com/problems/container-with-most-water/
/*
We are given a vector the height, we want to store the most water in the container
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int r = height.size() - 1, l = 0;
        int area = 0;
        while (l < r)
        {
            // update the area value everytime to keep it the maximum
            area = max(area, min(height[l], height[r]) * (r - l));
            // the key idea is that you don't move the higher wall if you want to store the max water
            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return area;
    }
};

int main()
{

    return EXIT_SUCCESS;
}