class Solution
{
public:
    int solve(int idx, int buy, vector<int> &prices, int fee)
    {
        if (idx == prices.size())
        {
            return 0;
        }
        int profit = 0;
        if (buy)
        {
            profit = max(-prices[idx] + solve(idx + 1, 0, prices, fee), solve(idx + 1, 1, prices, fee));
        }
        else
        {
            profit = max(prices[idx] - fee + solve(idx + 1, 1, prices, fee), solve(idx + 1, 0, prices, fee));
        }
        return profit;
    }

    int solve(int idx, int buy, vector<int> &prices, int fee, vector<vector<int>> &dp)
    {
        if (idx == prices.size())
        {
            return 0;
        }
        int profit = 0;
        if (dp[idx][buy] != -1)
        {
            return dp[idx][buy];
        }
        if (buy)
        {
            profit = max(-prices[idx] + solve(idx + 1, 0, prices, fee, dp), solve(idx + 1, 1, prices, fee, dp));
        }
        else
        {
            profit = max(prices[idx] - fee + solve(idx + 1, 1, prices, fee, dp), solve(idx + 1, 0, prices, fee, dp));
        }
        return dp[idx][buy] = profit;
    }

    int solve(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                long long profit = 0;
                if (buy)
                {
                    profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                }
                else
                {
                    profit = max(prices[i] - fee + dp[i + 1][1], dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int solveSpace(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> prev(2, 0), cur(2, 0);
        prev[0] = prev[1] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                long long profit = 0;
                if (buy)
                {
                    profit = max(-prices[i] + prev[0], prev[1]);
                }
                else
                {
                    profit = max(prices[i] - fee + prev[1], prev[0]);
                }
                cur[buy] = profit;
            }
            prev = cur;
        }
        return prev[1];
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solveSpace(prices, fee);
    }
};