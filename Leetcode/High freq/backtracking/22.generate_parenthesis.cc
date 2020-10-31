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
    Given an integer, we need generate all the possible parenthesis
    and put them into vector
    The key idea is to count the number of left and right parenthesis.
    And we would never expect left parentheis more than right since it will not be valid.
    
*/
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ret;
        dfs(n, n, "", ret);
        return ret;
    }
    void dfs(int left, int right, string out, vector<string> &ret)
    {
        if (left > right)
            return;
        if (left == 0 && right == 0)
        {
            ret.push_back(out);
        }
        if (left > 0)
            dfs(left - 1, right, out + "(", ret);
        if (right > 0)
            dfs(left, right - 1, out + ")", ret);
    }
};

int main()
{
    Solution obj;
    obj.generateParenthesis(5);

    return EXIT_SUCCESS;
}