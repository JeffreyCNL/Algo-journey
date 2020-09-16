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

class solution
{
public:
    // w width, h height, n num buildings
    int findMinDist(int w, int h, int n)
    {
        vector<vector<int>> grid(w, vector<int>(h, -1));
        return solve(n, w, h, 0, 0, grid);
    }

    int bfs(int w, int h, vector<vector<int>> &grid)
    {
        vector<vector<int>> dist(w, vector<int>(h));
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        dist = grid;
        int max_dist = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; ++j)
            {
                if (dist[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            max_dist = max(max_dist, dist[x][y]);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int new_x = x + dirs[i][0];
                int new_y = y + dirs[i][1];
                if (new_x >= w || new_y >= h || new_x < 0 || new_y < 0)
                    continue;
                if (dist[new_x][new_y] == -1)
                {
                    dist[new_x][new_y] = dist[x][y] + 1;
                    q.push({new_x, new_y});
                }
            }
        }

        return max_dist;
    }

    int solve(int left, int w, int h, int row, int col, vector<vector<int>> &grid)
    {
        if (left == 0)
        {
            return bfs(w, h, grid);
        }
        int r = row, c = col;
        if (col >= h)
        {
            r += col / h;
            c = col % h;
        }
        int min_dist = INT_MAX;
        for (int i = r; i < w; ++i)
        {
            for (int j = c; j < h; j++)
            {
                grid[i][j] = 0;
                int val = solve(left - 1, w, h, i, j + 1, grid);
                min_dist = min(min_dist, val);
                grid[i][j] = -1;
            }
        }
        return min_dist;
    }
};

int main()
{
    int w = 2, h = 3, n = 2;

    solution obj;
    cout << obj.findMinDist(w, h, n) << endl;

    w = 4;
    h = 4;
    n = 3;
    cout << obj.findMinDist(w, h, n) << endl;

    return EXIT_SUCCESS;
}