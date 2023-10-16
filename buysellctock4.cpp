class Solution
{
public:
    int solve(int idx, int buy, vector<int> &prices, int trasc)
    {
        if (idx == prices.size() || trasc == 0)
        {
            return 0;
        }
        if (buy)
        {
            return max(-prices[idx] + solve(idx + 1, 0, prices, trasc), solve(idx + 1, 1, prices, trasc));
        }
        return max(prices[idx] + solve(idx + 1, 1, prices, trasc - 1), solve(idx + 1, 0, prices, trasc));
    }

    int solve(int idx, int buy, vector<int> &prices, int trasc, vector<vector<vector<int>>> &dp)
    {
        if (idx == prices.size() || trasc == 0)
        {
            return 0;
        }
        if (dp[idx][buy][trasc] != -1)
        {
            return dp[idx][buy][trasc];
        }
        if (buy)
        {
            return dp[idx][buy][trasc] = max(-prices[idx] + solve(idx + 1, 0, prices, trasc, dp), solve(idx + 1, 1, prices, trasc, dp));
        }
        return dp[idx][buy][trasc] = max(prices[idx] + solve(idx + 1, 1, prices, trasc - 1, dp), solve(idx + 1, 0, prices, trasc, dp));
    }

    int solve(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int tr = 1; tr <= k; tr++)
                {
                    if (buy == 1)
                    {
                        dp[i][buy][tr] = max(-prices[i] + dp[i + 1][0][tr], dp[i + 1][1][tr]);
                    }
                    else
                    {
                        dp[i][buy][tr] = max(prices[i] + dp[i + 1][1][tr - 1], dp[i + 1][0][tr]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }

    int solveSpace(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(k + 1, 0));
        vector<vector<int>> cur(2, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int tr = 1; tr <= k; tr++)
                {
                    if (buy == 1)
                    {
                        cur[buy][tr] = max(-prices[i] + after[0][tr], after[1][tr]);
                    }
                    else
                    {
                        cur[buy][tr] = max(prices[i] + after[1][tr - 1], after[0][tr]);
                    }
                }
                after = cur;
            }
        }
        return after[1][k];
    }

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solveSpace(prices, k);
    }
};