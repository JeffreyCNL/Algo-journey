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
https://leetcode.com/problems/max-area-of-island/

*/

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int area = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    int tmpArea = 0;
                    // keep update of the max area
                    int tmp = dfs(grid, i, j, tmpArea);
                    area = max(area, tmp);
                }
            }
        }
        return area;
    }

    int dfs(vector<vector<int>> &grid, int row, int col, int &area)
    {
        int n = grid.size(), m = grid[0].size();
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0)
            return 0;
        grid[row][col] = 0;
        area++;
        // go to every direction to find the maximum area
        dfs(grid, row + 1, col, area);
        dfs(grid, row - 1, col, area);
        dfs(grid, row, col + 1, area);
        dfs(grid, row, col - 1, area);
        return area;
    }
};

// another solution that does not need to return the value of area
// just modify the area in the memory and compare them while running over the dfs function.
// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int curMax = 0;
//         for (int i = 0; i < grid.size(); ++i){
//             for (int j = 0; j < grid[0].size(); ++j){
//                 int area = 0;
//                 if (grid[i][j] == 1) {
//                     dfs(grid, area, i , j);
//                     curMax = max(curMax, area);
//                 }
//             }
//         }
//         return curMax;
//     }

//     void dfs(vector<vector<int>>& grid, int& area, int row, int col){
//         int n = grid.size(), m = grid[0].size();
//         if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == -1 || grid[row][col] == 0) return;
//         grid[row][col] = -1;
//         area++;
//         dfs(grid, area, row + 1, col);
//         dfs(grid, area, row - 1, col);
//         dfs(grid, area, row, col + 1);
//         dfs(grid, area, row, col - 1);
//     }
// };
int main()
{

    return EXIT_SUCCESS;
}