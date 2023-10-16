class Solution
{
public:
    int mod = 1e9 + 7;
    int solve(int i, int j, vector<vector<int>> &grid)
    {
        if (i == 0 && j == 0)
        {
            return grid[i][j];
        }

        if (i < 0 || j < 0)
        {
            return INT_MAX;
        }

        int up = grid[i][j] + solve(i - 1, j, grid) % mod;
        int left = grid[i][j] + solve(i, j - 1, grid) % mod;

        return min(up, left);
    }

    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            return grid[i][j];
        }

        if (i < 0 || j < 0)
        {
            return INT_MAX;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int up = grid[i][j] + solve(i - 1, j, grid, dp) % mod;
        int left = grid[i][j] + solve(i, j - 1, grid, dp) % mod;

        return dp[i][j] = min(up, left);
    }

    int solve(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row == 0 && col == 0)
                {
                    dp[0][0] = grid[0][0];
                }
                else
                {
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if (row > 0)
                    {
                        up = grid[row][col] + dp[row - 1][col] % mod;
                    }
                    if (col > 0)
                    {
                        left = grid[row][col] + dp[row][col - 1] % mod;
                    }

                    dp[row][col] = min(up, left);
                }
            }
        }

        return dp[m - 1][n - 1];
    }

    int solveSpaceOptimize(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, INT_MAX);

        for (int row = 0; row < m; row++)
        {
            vector<int> cur(n, INT_MAX);
            for (int col = 0; col < n; col++)
            {
                if (row == 0 && col == 0)
                {
                    cur[col] = grid[row][col];
                }
                else
                {
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if (row > 0)
                    {
                        up = grid[row][col] + prev[col] % mod;
                    }
                    if (col > 0)
                    {
                        left = grid[row][col] + cur[col - 1] % mod;
                    }

                    cur[col] = min(up, left);
                }
            }
            prev = cur;
        }

        return prev[n - 1];
    }

    int minPathSum(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solveSpaceOptimize(grid);
    }
};