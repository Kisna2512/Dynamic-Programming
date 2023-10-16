#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int i, int j, int m, int n)
    {
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }

        if (i >= m || j >= n)
        {
            return 0;
        }

        return solve(i + 1, j, m, n) + solve(i, j + 1, m, n);
    }

    int solve(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }

        if (i >= m || j >= n)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        return dp[i][j] = solve(i + 1, j, m, n, dp) + solve(i, j + 1, m, n, dp);
    }

    int solveTab(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[0][0] = 1;
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

    int solveS(int m, int n)
    {
        vector<int> prevRow(m, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    temp[0] = 1;
                }
                else
                {
                    int left = 0, right = 0;
                    if (i > 0)
                    {
                        left = prevRow[j];
                    }
                    if (j > 0)
                    {
                        right = temp[j - 1];
                    }
                    temp[j] = left + right;
                }
            }
            prevRow = temp;
        }

        return prevRow[n - 1];
    }

    int uniquePaths(int m, int n)
    {
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        //   return  solve(0,0,m,n,dp);

        return solveS(m, n);
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
