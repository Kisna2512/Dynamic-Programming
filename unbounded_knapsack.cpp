class Solution
{
public:
    int solve(int idx, int w, int val[], int wt[])
    {
        if (idx == 0)
        {
            return (w / wt[idx]) * val[idx];
        }

        int npick = solve(idx - 1, w, val, wt);
        int pick = INT_MIN;
        if (w >= wt[idx])
        {
            pick = val[idx] + solve(idx, w - wt[idx], val, wt);
        }

        return max(pick, npick);
    }

    int solve(int idx, int w, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            return (w / wt[idx]) * val[idx];
        }

        if (dp[idx][w] != -1)
        {
            return dp[idx][w];
        }

        int npick = solve(idx - 1, w, val, wt, dp);
        int pick = INT_MIN;
        if (w >= wt[idx])
        {
            pick = val[idx] + solve(idx, w - wt[idx], val, wt, dp);
        }

        return dp[idx][w] = max(pick, npick);
    }

    int solveTab(int n, int w, int val[], int wt[])
    {
        vector<vector<int>> dp(n, vector<int>(w + 1, 0));
        for (int W = 0; W <= w; W++)
        {
            dp[0][W] = ((int)(W / wt[0])) * val[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int W = 0; W <= w; W++)
            {
                int npick = dp[i - 1][W];
                int pick = 0;
                if (wt[i] <= W)
                {
                    pick = val[i] + dp[i][W - wt[i]];
                }

                dp[i][W] = max(pick, npick);
            }
        }

        return dp[n - 1][w];
    }

    int solveSpace(int n, int w, int val[], int wt[])
    {
        vector<int> prev(w + 1, 0);
        for (int W = 0; W <= w; W++)
        {
            prev[W] = ((int)(W / wt[0])) * val[0];
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> cur(w + 1, 0);
            for (int W = 0; W <= w; W++)
            {
                int npick = prev[W];
                int pick = 0;
                if (wt[i] <= W)
                {
                    pick = val[i] + cur[W - wt[i]];
                }

                cur[W] = max(pick, npick);
            }

            prev = cur;
        }

        return prev[w];
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W + 1, -1));
        return solveSpace(N, W, val, wt);
    }
};
