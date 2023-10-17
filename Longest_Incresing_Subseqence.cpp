class Solution
{
public:
    // Recursion
    int solve(int idx, int prev_idx, vector<int> &nums)
    {
        if (idx == nums.size())
        {
            return 0;
        }

        int nontake = 0 + solve(idx + 1, prev_idx, nums);
        int take = INT_MIN;
        if (prev_idx == -1 || nums[idx] > nums[prev_idx])
        {
            take = 1 + solve(idx + 1, idx, nums);
        }

        return max(take, nontake);
    }

    // Memoization
    int solve(int idx, int prev_idx, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (idx == nums.size())
        {
            return 0;
        }
        if (dp[idx][prev_idx + 1] != -1)
        {
            return dp[idx][prev_idx + 1];
        }
        int nontake = 0 + solve(idx + 1, prev_idx, nums, dp);
        int take = INT_MIN;
        if (prev_idx == -1 || nums[idx] > nums[prev_idx])
        {
            take = 1 + solve(idx + 1, idx, nums, dp);
        }
        return dp[idx][prev_idx + 1] = max(take, nontake);
    }

    // Tabulation
    int solve(int n, vector<int> &nums)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= -1; j--)
            {
                int nontake = dp[i + 1][j + 1];
                int take = INT_MIN;
                if (j == -1 || nums[i] > nums[j])
                {
                    take = 1 + dp[i + 1][i + 1];
                }
                dp[i][j + 1] = max(take, nontake);
            }
        }

        return dp[0][0];
    }

    // Space Optimization
    int solveSpace(int n, vector<int> &nums)
    {
        vector<int> ahead(n + 1, 0);
        vector<int> cur(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= -1; j--)
            {
                int nontake = ahead[j + 1];
                int take = INT_MIN;
                if (j == -1 || nums[i] > nums[j])
                {
                    take = 1 + ahead[i + 1];
                }
                cur[j + 1] = max(take, nontake);
            }
            ahead = cur;
        }

        return ahead[0];
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solveSpace(n, nums);
    }
};