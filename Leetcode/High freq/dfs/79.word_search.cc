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
    bool dfs(vector<vector<char>> &board, string &word, int idx, const int &m, const int &n, int row, int col)
    {
        if (word.size() == idx)
            return true;
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[idx] || board[row][col] == '*')
            return false;
        board[row][col] = '*';
        bool ret = dfs(board, word, idx + 1, m, n, row + 1, col) ||
                   dfs(board, word, idx + 1, m, n, row - 1, col) ||
                   dfs(board, word, idx + 1, m, n, row, col + 1) ||
                   dfs(board, word, idx + 1, m, n, row, col - 1);
        board[row][col] = word[idx];
        return ret;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        const int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(board, word, 0, m, n, i, j))
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    return EXIT_SUCCESS;
}