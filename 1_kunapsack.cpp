#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int idx, int w, int wt[], int val[])
    {
       
        if (idx == 0)
        {
            if (wt[0] <= w)
            {
                return val[idx];
            }
            return 0;
        }

        int nonpick = solve(idx - 1, w, wt, val);
        int pick = INT_MIN;
        if (w >= wt[idx])
        {
            pick = val[idx] + solve(idx - 1, w - wt[idx], wt, val);
        }

        return max(nonpick, pick);
    }

    int solve(int idx, int w, int wt[], int val[], vector<vector<int>> &dp)
    {
        if (w < 0)
        {
            return INT_MIN;
        }
        if (idx == 0)
        {
            if (wt[0] <= w)
            {
                return val[idx];
            }
            return 0;
        }

        if (dp[idx][w] != -1)
        {
            return dp[idx][w];
        }

        int nonpick = solve(idx - 1, w, wt, val, dp);
        int pick = INT_MIN;
        if (w >= wt[idx])
        {
            pick = val[idx] + solve(idx - 1, w - wt[idx], wt, val, dp);
        }

        return dp[idx][w] = max(nonpick, pick);
    }

    int solveTab(int W, int wt[], int val[], int n)
    {

        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for (int i = wt[0]; i <= W; i++)
        {
            dp[0][i] = val[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                int non = dp[i - 1][w];
                int p = INT_MIN;
                if (wt[i] <= w)
                {
                    p = val[i] + dp[i - 1][w - wt[i]];
                }

                dp[i][w] = max(non, p);
            }
        }

        return dp[n - 1][W];
    }

    int solveSpace(int W, int wt[], int val[], int n)
    {

        vector<int> prev(W + 1, 0);
        for (int i = wt[0]; i <= W; i++)
        {
            prev[i] = val[0];
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> cur(W + 1, 0);
            for (int w = 0; w <= W; w++)
            {
                int non = prev[w];
                int p = INT_MIN;
                if (wt[i] <= w)
                {
                    p = val[i] + prev[w - wt[i]];
                }

                cur[w] = max(non, p);
            }
            prev = cur;
        }

        return prev[W];
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        //   return solve(n-1,W,wt,val,dp);
        return solveSpace(W, wt, val, n);
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
