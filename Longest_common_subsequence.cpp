class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.
    int solve(int idx1, int idx2, string s1, string s2)
    {
        if (idx1 < 0 || idx2 < 0)
        {
            return 0;
        }

        if (s1[idx1] == s2[idx2])
        {
            return 1 + solve(idx1 - 1, idx2 - 1, s1, s2);
        }

        return max(solve(idx1 - 1, idx2, s1, s2), solve(idx1, idx2 - 1, s1, s2));
    }

    int solve(int idx1, int idx2, string s1, string s2, vector<vector<int>> &dp)
    {
        if (idx1 < 0 || idx2 < 0)
        {
            return 0;
        }

        if (dp[idx1][idx2] != -1)
        {
            return dp[idx1][idx2];
        }

        if (s1[idx1] == s2[idx2])
        {
            return dp[idx1][idx2] = 1 + solve(idx1 - 1, idx2 - 1, s1, s2, dp);
        }

        return dp[idx1][idx2] = max(solve(idx1 - 1, idx2, s1, s2, dp), solve(idx1, idx2 - 1, s1, s2, dp));
    }

    int solveTab(int n, int m, string s1, string s2)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {

                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    int solveSpace(int n, int m, string s1, string s2)
    {
        vector<int> prev(m + 1, 0);
        for (int i = 1; i < n + 1; i++)
        {
            vector<int> cur(m + 1, 0);
            for (int j = 1; j < m + 1; j++)
            {

                if (s1[i - 1] == s2[j - 1])
                    cur[j] = 1 + prev[j - 1];
                else
                    cur[j] = max(prev[j], cur[j - 1]);
            }
            prev = cur;
        }
        return prev[m];
    }

    int lcs(int n, int m, string s1, string s2)
    {
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return solve(n-1,m-1,s1,s2,dp);
        return solveSpace(n, m, s1, s2);
    }
};