#include <bits/stdc++.h>
using namespace std;

// Recursive
int solverec(int ind, vector<int> &heights)
{

    if (ind == 0)
    {
        return 0;
    }

    int left = solverec(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);

    int right = INT_MAX;
    if (ind > 1)
    {
        right = solverec(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);
    }

    return min(left, right);
}

// Memoization
int solveMemo(int ind, vector<int> &heights, vector<int> &dp)
{
    if (ind == 0)
    {
        return 0;
    }

    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int left = solveMemo(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);

    int right = INT_MAX;
    if (ind > 1)
    {
        right = solveMemo(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    }

    return dp[ind] = min(left, right);
}

// Tabulation
int solveTab(int ind, vector<int> &heights)
{
    int n = ind;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;

    for (int i = 1; i < heights.size(); i++)
    {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }

        dp[i] = min(left, right);
    }
    return dp[n - 1];
}

// Space Optimisation
int solvespace(int ind, vector<int> &heights)
{
    int n = ind;

    int prev = 0;
    int prev2 = 0;

    for (int i = 1; i < heights.size(); i++)
    {
        int left = prev + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = prev2 + abs(heights[i] - heights[i - 2]);
        }

        int curri = min(left, right);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

int frogJump(int n, vector<int> &heights)
{
    // vector<int> dp(n + 1, -1);
    // return solveMemo(n - 1, heights, dp);
    // return solveTab(n, heights);
    return solvespace(n, heights);
    // return solverec(n, heights);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> heights(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    cout << frogJump(n - 1, heights);

    return 0;
}
