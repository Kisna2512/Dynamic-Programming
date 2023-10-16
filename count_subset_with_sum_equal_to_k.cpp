int mod = 1e9 + 7;
int solve(int i, vector<int> &arr, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
    {
        return 1;
    }
    if (i == 0)
    {
        return (arr[i] == sum);
    }

    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }

    int pick = 0;

    if (arr[i] <= sum)
    {
        pick = solve(i - 1, arr, sum - arr[i], dp);
    }

    int notpick = solve(i - 1, arr, sum, dp);

    return dp[i][sum] = pick + notpick;
}

int solveTab(int n, vector<int> &arr, int sum)
{
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (arr[0] <= sum)
    {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int s = 0; s <= sum; s++)
        {
            int pick = 0;

            if (arr[i] <= s)
            {
                pick = dp[i - 1][s - arr[i]] % mod;
            }

            int notpick = dp[i - 1][s] % mod;
            dp[i][s] = pick + notpick;
        }
    }

    return dp[n - 1][sum] % mod;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return solveTab(n, num, tar);
}