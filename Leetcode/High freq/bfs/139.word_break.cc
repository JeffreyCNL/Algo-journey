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
    Given a non-empty string s and a dictionary wordDict
    containing a list of non-empty words, determine 
    if s can be segmented into a space-separated 
    sequence of one or more dictionary words.

    Input: s = "leetcode", wordDict = ["leet", "code"]
    Output: true
    Explanation: Return true 
    because "leetcode" can be segmented as "leet code".
*/
// BFS solution
class Solution
{
public:
    // BFS
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        queue<int> pos{{0}};
        vector<bool> visited(s.size(), false);
        while (!pos.empty())
        {
            int idx = pos.front();
            pos.pop();
            if (!visited[idx])
            {
                // the edge is for substr function
                for (int i = idx + 1; i <= s.size(); ++i)
                {
                    string tmp = s.substr(idx, i - idx);
                    // it shows that we can use this
                    // index for the next word
                    // push it into the queue
                    if (wordSet.count(tmp))
                    {
                        pos.push(i);
                        if (i == s.size())
                        {
                            return true;
                        }
                    }
                }
                visited[idx] = true;
            }
        }
        return false;
    }
};

int main()
{

    return EXIT_SUCCESS;
}