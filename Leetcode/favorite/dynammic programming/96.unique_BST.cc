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
    Given an integer, we need to find how to combine a BST.
    The key idea is to make every number as a root and try to 
    get the result based on the previous value.
   
 n = 1
     1
    
 n = 2  
      1             2
        \          /
          2       1   
 n = 3

       1             1              3           3        2
        \             \            /           /        /  \
        2              3          1           2        1    3
        \             /            \         /
        3            2               2      1

 n = 4
     1
      \
       2
        \
         3
          \
            4 .....
*/
class Solution
{
public:
    int numTrees(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        // building the dp vector
        for (int i = 1; i <= n; ++i)
        {
            int tmp = 0;
            // make every one as a root
            for (int root = 1; root <= i; ++root)
            {
                // the one on the left's combination *  the one on the right's combination
                // all the combination is based on the previous result
                tmp += dp[i - root] * dp[root - 1];
                // cout <<"root : " << root << " " <<  tmp << endl;
            }
            dp[i] = tmp;
        }
        return dp.back();
    }
};

int main()
{

    return EXIT_SUCCESS;
}