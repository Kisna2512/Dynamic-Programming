class Solution
{
public:
    int solve(int i, int j, string s, string t)
    {
        if (j < 0)
        {
            return 1;
        }

        if (i < 0)
        {
            return 0;
        }

        if (s[i] == t[j])
        {
            return solve(i - 1, j - 1, s, t) + solve(i - 1, j, s, t);
        }

        return solve(i - 1, j, s, t);
    }

    int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if (j < 0)
        {
            return 1;
        }

        if (i < 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == t[j])
        {
            return dp[i][j] = solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp);
        }

        return dp[i][j] = solve(i - 1, j, s, t, dp);
    }

    int solve(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
    }

    int solveSpace(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<double> prev(m + 1, 0), cur(m + 1, 0);
        prev[0] = cur[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    cur[j] = prev[j - 1] + prev[j];
                }
                else
                {
                    cur[j] = prev[j];
                }
            }
            prev = cur;
        }

        return prev[m];
    }

    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s, t);
    }
};