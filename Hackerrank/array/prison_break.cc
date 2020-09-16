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
prison:
    Arrguments:
        n: number of horizontal bars
        m: number of vertical bars
        h: array of int. The horizontal bar being removed.
        v: array of int. The vertical bar being removed.
    Return: the max area the prisoner got. int

for example:
    Given n = 3, m = 3, h = {2}, v = {2};

    we have the prison
      1 2 3
     _ _ _ _
    | | | | |
   1 _ _ _ _
    | | | | |
   2 _ _ _ _
    | | | | |
   3 _ _ _ _
    | | | | |
     _ _ _ _

     becomes
     
      1 2 3
     _ _ _ _
    | |   | |
   1 _ _ _ _
    | |///| |
   2   ///
    | |///| |
   3 _ _ _ _
    | |   | |
     _ _ _ _

     the max area is 4

The approach is not that efficient with one test case TLE.
*/
long countMax(vector<int> &vec)
{
    long maxValue = 0;
    long start = 0, end = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        // start from the i. This could be an issue for the efficiency
        // since this will always search again. But we can start from the last end.
        end = i;
        start = end;
        // if it's continuous, keep moving the end pointer
        while (end < vec.size() && vec[end] == vec[end + 1] - 1)
        {
            end++;
        }
        maxValue = max(maxValue, (end - start + 2));
    }
    return maxValue;
}

long prison(int n, int m, vector<int> h, vector<int> v)
{
    sort(h.begin(), h.end());
    sort(v.begin(), v.end());
    // getting the maximum height and width to calculate the largest area
    long maxH = countMax(h);
    long maxV = countMax(v);
    return maxH * maxV;
}

int main()
{

    return EXIT_SUCCESS;
}