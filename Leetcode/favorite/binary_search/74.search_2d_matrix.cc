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
    https://leetcode.com/problems/search-a-2d-matrix/
    Write an efficient algorithm that searches for a value in an m x n matrix. 
    This matrix has the following properties:
        Integers in each row are sorted from left to right.
        The first integer of each row is greater than the last integer of the previous row.

    do the binary search to find the specif row we are looking for
    do the binary search for the row
*/
class Solution
{
public:
    int lookForRow(vector<vector<int>> &matrix, const int &target)
    {
        int l = 0, r = matrix.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] > target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (matrix[l][0] > target)
            l--;
        return l;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty() || matrix.back().back() < target || matrix.front().front() > target)
            return false;
        int row = lookForRow(matrix, target);
        int l = 0, r = matrix[row].size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] == target)
                return true;
            if (matrix[row][mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return false;
    }
};

int main()
{

    return EXIT_SUCCESS;
}