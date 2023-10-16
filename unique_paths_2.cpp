class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &grid)
    {
        if (i >= 0 && j >= 0 && grid[i][j] == 1)
        {
            return 0;
        }
        if (i == 0 && j == 0)
        {
            return 1;
        }
        if (i < 0 || j < 0)
        {
            return 0;
        }
        return solve(i - 1, j, grid) + solve(i, j - 1, grid);
    }

    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i >= 0 && j >= 0 && grid[i][j] == 1)
        {
            return 0;
        }
        if (i == 0 && j == 0)
        {
            return 1;
        }
        if (i < 0 || j < 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        return dp[i][j] = solve(i - 1, j, grid, dp) + solve(i, j - 1, grid, dp);
    }

    int solveTab(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else if (i == 0 && j == 0)
                {

                    dp[i][j] = 1;
                }
                else
                {
                    int left = 0, right = 0;
                    if (i > 0)
                    {
                        left = dp[i - 1][j];
                    }
                    if (j > 0)
                    {
                        right = dp[i][j - 1];
                    }
                    dp[i][j] = left + right;
                }
            }
        }

        return dp[m - 1][n - 1];
    }

    int solveSpace(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    cur[j] = 0;
                }
                else if (i == 0 && j == 0)
                {

                    cur[j] = 1;
                }
                else
                {
                    int left = 0, right = 0;
                    if (i > 0)
                    {
                        left = prev[j];
                    }
                    if (j > 0)
                    {
                        right = cur[j - 1];
                    }
                    cur[j] = left + right;
                }
            }
            prev = cur;
        }

        return prev[n - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {

        //  int m=grid.size();
        //  int n=grid[0].size();
        //  vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        //  return solve(m-1,n-1,grid,dp);

        return solveSpace(grid);
    }
};