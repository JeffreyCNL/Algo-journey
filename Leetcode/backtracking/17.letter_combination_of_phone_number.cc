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
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        // can also use map, but using vector can put string inside and use index as a reference.
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string out = "";
        dfs(digits, dict, 0, out, ans);
        return ans;
    }

    void dfs(const string &digits, const vector<string> &dict, int pos, string &out, vector<string> &ans)
    {
        // base case: when it reached the end of the digits, we can push the string inside
        if (pos == digits.size())
        {
            ans.push_back(out);
            return;
        }
        // use a pos to get to know where we are point to in the digits
        string s = dict[digits[pos] - '0'];
        for (int i = 0; i < s.size(); ++i)
        {
            out += s[i];
            dfs(digits, dict, pos + 1, out, ans);
            out.pop_back();
        }
    }
};

int main()
{

    return EXIT_SUCCESS;
}