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

/* https://leetcode.com/problems/valid-palindrome-ii/
we can skip at most one character and check if the string is still a palindrome.
The interesting part for this question is to search from two ends and skip right or left to keep 
searching, as long as we got one true result, then we should return true.
*/
class Solution
{
public:
    bool validPalindrome(string s)
    {
        if (s.size() <= 1)
            return true;
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            // if the same char, keep looping
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                // move left to check , move right to check.
                return helper(s, l + 1, r) || helper(s, l, r - 1);
            }
        }
        return true;
    }

    bool helper(string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
};
int main()
{

    return EXIT_SUCCESS;
}