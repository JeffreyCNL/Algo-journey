

/*
    We need to keep track of how many rain water we can collect between the buildings
    
         _
        | |
     _  | |
    | | | |
    |3| |5| 
    | |_| |  we can clearly tell it can only store 3 at most


     _  
    | | 
    | |  _ 
    | | | | we can clearly tell it can only store 3 at most
    |5| |3|
    | |_| |

    So the key point is to track the left maximum value and right maximum value
    and get the minimum from it - the height of the building. That's the
    water we can store.
*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> rightMax(n, 0);
        vector<int> leftMax(n, 0);
        int tmp = 0;
        for (int i = 0; i < n; ++i)
        {
            if (height[i] > tmp)
            {
                tmp = height[i];
            }
            leftMax[i] = tmp;
        }
        tmp = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (height[i] > tmp)
            {
                tmp = height[i];
            }
            rightMax[i] = tmp;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans += (min(leftMax[i], rightMax[i]) - height[i]);
        }
        return ans;
    }
};

// we can also use two pointers to track the left and right
// We move whatever is smaller and minus it by height and we can get the volumne
// this will only take one iteration, still O(n) tho

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0, l = 0, r = height.size() - 1;
        while (l < r)
        {
            int mn = min(height[l], height[r]);
            if (mn == height[l])
            {
                ++l;
                while (l < r && height[l] < mn)
                {
                    res += mn - height[l++];
                }
            }
            else
            {
                --r;
                while (l < r && height[r] < mn)
                {
                    res += mn - height[r--];
                }
            }
        }
        return res;
    }
};