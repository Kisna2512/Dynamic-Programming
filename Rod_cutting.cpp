class Solution
{
public:
    int solve(int idx, int price[], int n)
    {

        if (idx == 0)
        {
            return n * price[0];
        }
        int ntake = solve(idx - 1, price, n);
        int take = INT_MIN;
        int rodlength = idx + 1;
        if (rodlength <= n)
        {
            take = price[idx] + solve(idx, price, n - rodlength);
        }

        return max(ntake, take);
    }

    int solve(int idx, int price[], int n, vector<vector<int>> &dp)
    {

        if (idx == 0)
        {
            return n * price[0];
        }
        if (dp[idx][n] != -1)
        {
            return dp[idx][n];
        }
        int ntake = solve(idx - 1, price, n, dp);
        int take = INT_MIN;
        int rodlength = idx + 1;
        if (rodlength <= n)
        {
            take = price[idx] + solve(idx, price, n - rodlength, dp);
        }

        return dp[idx][n] = max(ntake, take);
    }

    int solveTab(int price[], int n)
    {

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = i * price[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int ntake = dp[i - 1][j];
                int take = INT_MIN;
                int rodlength = i + 1;
                if (rodlength <= j)
                {
                    take = price[i] + dp[i][j - rodlength];
                }
                dp[i][j] = max(take, ntake);
            }
        }

        return dp[n - 1][n];
    }

    int solveSpace(int price[], int n)
    {

        vector<int> prev(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            prev[i] = i * price[0];
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> cur(n + 1, 0);
            for (int j = 0; j <= n; j++)
            {
                int ntake = prev[j];
                int take = INT_MIN;
                int rodlength = i + 1;
                if (rodlength <= j)
                {
                    take = price[i] + cur[j - rodlength];
                }
                cur[j] = max(take, ntake);
            }
            prev = cur;
        }

        return prev[n];
    }

    int cutRod(int price[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solveSpace(price, n);
    }
};