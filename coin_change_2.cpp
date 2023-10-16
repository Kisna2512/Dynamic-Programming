class Solution
{
public:
    long long mod = 1e9 + 7;
    int solve(int idx, vector<int> &coins, int amount)
    {
        if (idx == 0)
        {
            return (amount % coins[idx] == 0);
        }

        int nonpick = solve(idx - 1, coins, amount);
        int pick = 0;
        if (coins[idx] <= amount)
        {
            pick = solve(idx, coins, amount - coins[idx]);
        }

        return (pick + nonpick);
    }

    int solve(int idx, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            return (amount % coins[idx] == 0);
        }
        if (dp[idx][amount] != -1)
        {
            return dp[idx][amount];
        }
        int nonpick = solve(idx - 1, coins, amount, dp);
        int pick = 0;
        if (coins[idx] <= amount)
        {
            pick = solve(idx, coins, amount - coins[idx], dp);
        }

        return dp[idx][amount] = (pick + nonpick);
    }

    int solveTab(int n, vector<int> &arr, int target)
    {
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int T = 0; T <= target; T++)
        {
            if (T % arr[0] == 0)
            {
                dp[0][T] = 1;
            }
            else
            {
                dp[0][T] = 0;
            }
        }

        for (int idx = 1; idx < n; idx++)
        {
            for (int T = 0; T <= target; T++)
            {
                int nottake = (dp[idx - 1][T]);
                int take = 0;
                if (arr[idx] <= T)
                {
                    take = (dp[idx][T - arr[idx]]);
                }

                dp[idx][T] = (take + nottake);
            }
        }

        return dp[n - 1][target];
    }

    int solveSpace(int n, vector<int> &arr, int target)
    {
        vector<int> prev(target + 1, 0);
        for (int T = 0; T <= target; T++)
        {
            if (T % arr[0] == 0)
            {
                prev[T] = 1;
            }
            else
            {
                prev[T] = 0;
            }
        }

        for (int idx = 1; idx < n; idx++)
        {
            vector<int> cur(target + 1, 0);
            for (int T = 0; T <= target; T++)
            {
                int nottake = (prev[T]);
                int take = 0;
                if (arr[idx] <= T)
                {
                    take = (cur[T - arr[idx]]);
                }

                cur[T] = (take + nottake);
            }
            prev = cur;
        }

        return prev[target];
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        //  vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        //  return solve(n-1,coins,amount,dp);

        return solveSpace(n, coins, amount);
    }
};