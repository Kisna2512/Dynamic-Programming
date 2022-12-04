#include <bits/stdc++.h>
using namespace std;

// Recursive TC:O(2^N) SC:O(N)
int solverec(int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n == 1)
    {
        return 1;
    }

    return solverec(n - 1) + solverec(n - 2);
}

// Memoization TC:O(N) SC:O(N)+O(N)
int solveMemo(int n, vector<int> dp)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = solveMemo(n - 1, dp) + solveMemo(n - 2, dp);
}

// Tabulation TC:O(N) SC:O(N)
int solveTab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Space Optimization TC:O(N) SC:O(1)
int solvespace(int n)
{
    int prev2 = 1;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << solverec(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << solveMemo(n, dp) << endl;

    cout << solveTab(n) << endl;
    cout << solvespace(n) << endl;

    return 0;
}