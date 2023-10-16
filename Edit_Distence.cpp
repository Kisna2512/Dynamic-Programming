class Solution
{
public:
    int solve(int i, int j, string word1, string word2)
    {
        if (i < 0)
        {
            return j + 1;
        }

        if (j < 0)
        {
            return i + 1;
        }

        if (word1[i] == word2[j])
        {
            return 0 + solve(i - 1, j - 1, word1, word2);
        }

        int insertOps = 1 + solve(i, j - 1, word1, word2);
        int deleteOps = 1 + solve(i - 1, j, word1, word2);
        int replaceOps = 1 + solve(i - 1, j - 1, word1, word2);

        return min({insertOps, deleteOps, replaceOps});
    }

    int solve(int i, int j, string word1, string word2, vector<vector<int>> &dp)
    {
        if (i < 0)
        {
            return j + 1;
        }

        if (j < 0)
        {
            return i + 1;
        }
        if (dp[i][j] != -1)
        {
            dp[i][j];
        }
        if (word1[i] == word2[j])
        {
            return dp[i][j] = 0 + solve(i - 1, j - 1, word1, word2, dp);
        }

        return dp[i][j] = 1 + min({solve(i, j - 1, word1, word2, dp), solve(i - 1, j, word1, word2, dp), solve(i - 1, j - 1, word1, word2, dp)});
    }

    int solve(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }

        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]});
                }
            }
        }

        return dp[n][m];
    }

    int solveSpace(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for (int j = 0; j <= m; j++)
        {
            prev[j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            cur[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    cur[j] = prev[j - 1];
                }
                else
                {
                    cur[j] = 1 + min({cur[j - 1], prev[j - 1], prev[j]});
                }
            }
            prev = cur;
        }

        return prev[m];
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solveSpace(word1, word2);
    }
};