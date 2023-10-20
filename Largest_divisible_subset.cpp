class Solution
{
public:
    vector<int> solveS(int n, vector<int> &nums)
    {
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);
        int maxi = 1;
        int lastidx = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastidx = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastidx]);
        while (hash[lastidx] != lastidx)
        {
            lastidx = hash[lastidx];
            temp.push_back(nums[lastidx]);
        }

        for (auto it : temp)
        {
            cout << it << " ";
        }
        return temp;
    }

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        return solveS(n, nums);
    }
};