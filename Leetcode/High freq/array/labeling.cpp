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

string getLargestString(string &originalLabel, int charLimit)
{
    if (originalLabel.empty())
    {
        return "";
    }
    sort(originalLabel.begin(), originalLabel.end(), [](char &a, char &b) {
        return a > b;
    });
    int i = 0, j = 1, n = originalLabel.size();
    while (j < n)
    {
        cout << originalLabel << endl;
        while (j < n && originalLabel[i] == originalLabel[j])
        {
            j++;
            if (j - i + 1 > charLimit)
            {

                i = j;
                char c = originalLabel[i];
                while (j < n && originalLabel[j] == c)
                {
                    j++;
                }
                swap(originalLabel[i], originalLabel[j]);
                if (j == n - 1)
                {
                    originalLabel.erase(originalLabel.begin() + j);
                    return originalLabel;
                }
                i++;
            }
        }
        i = j;
        j++;
    }
    return originalLabel;
}

int main()
{
    string original = "azzxxx";
    int charLimits = 2;
    cout << getLargestString(original, charLimits) << endl;

    original = "azzzzz";
    cout << getLargestString(original, charLimits) << endl;
    return EXIT_SUCCESS;
}