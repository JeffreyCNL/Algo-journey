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
    Using dfs to construct every combination of letters
*/
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string out = "";
        dfs(digits, dict, 0, out, ans);
        return ans;
    }

    void dfs(const string &digits, const vector<string> &dict, int pos, string &out, vector<string> &ans)
    {
        if (pos == digits.size())
        {
            ans.push_back(out);
            return;
        }
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