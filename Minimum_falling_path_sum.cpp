class Solution
{
public:
    int mod = 1e9 + 7;

    int solve(int i, int j, vector<vector<int>> &matrix, int n)
    {
        if (j < 0 || j >= n)
        {
            return INT_MAX;
        }
        if (i == 0)
        {
            return matrix[i][j];
        }

        if (i < 0 || j < 0)
        {
            return INT_MAX;
        }

        int left = matrix[i][j] + solve(i - 1, j - 1, matrix, n) % mod;
        int down = matrix[i][j] + solve(i - 1, j, matrix, n) % mod;
        int right = matrix[i][j] + solve(i - 1, j + 1, matrix, n) % mod;

        return min(left, min(right, down));
    }

    int solve(int i, int j, vector<vector<int>> &matrix, int n, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= n)
        {
            return INT_MAX;
        }
        if (i == 0)
        {
            return matrix[i][j];
        }

        if (i < 0 || j < 0)
        {
            return INT_MAX;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int left = matrix[i][j] + solve(i - 1, j - 1, matrix, n, dp) % mod;
        int down = matrix[i][j] + solve(i - 1, j, matrix, n, dp) % mod;
        int right = matrix[i][j] + solve(i - 1, j + 1, matrix, n, dp) % mod;

        return dp[i][j] = min(left, min(right, down));
    }

    int solveTab(vector<vector<int>> &matrix, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int left = INT_MAX;
                if (j - 1 >= 0)
                {
                    left = matrix[i][j] + dp[i - 1][j - 1];
                }

                int down = matrix[i][j] + dp[i - 1][j];

                int right = INT_MAX;
                if (j + 1 < n)
                {
                    right = matrix[i][j] + dp[i - 1][j + 1];
                }

                dp[i][j] = min(left, min(right, down));
            }
        }

        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, dp[n - 1][i]);
        }
        return mini;
    }

    int solveSpace(vector<vector<int>> &matrix, int n)
    {
        vector<int> prev(n, 0);
        for (int i = 0; i < n; i++)
        {
            prev[i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {
                int left = INT_MAX;
                if (j - 1 >= 0)
                {
                    left = matrix[i][j] + prev[j - 1];
                }

                int down = matrix[i][j] + prev[j];

                int right = INT_MAX;
                if (j + 1 < n)
                {
                    right = matrix[i][j] + prev[j + 1];
                }

                cur[j] = min(left, min(right, down));
            }
            prev = cur;
        }

        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, prev[i]);
        }
        return mini;
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {

        int mini = INT_MAX;
        int n = matrix.size();
        //    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        //    for(int i=n-1;i >= 0;i--)
        //    {
        //        mini=min(mini,solve(n-1,i,matrix,n,dp));
        //    }

        mini = min(mini, solveSpace(matrix, n));
        return mini;
    }
};