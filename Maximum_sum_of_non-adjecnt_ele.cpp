#include <bits/stdc++.h>
using namespace std;
int solve(int idx, int *arr)
{
    if (idx == 0)
    {
        return arr[idx];
    }

    if (idx < 0)
    {
        return 0;
    }

    int pick = arr[idx] + solve(idx - 2, arr);
    int nonpick = 0 + solve(idx - 1, arr);

    return max(pick, nonpick);
}

int solve(int idx, int *arr, vector<int> &dp)
{
    if (idx == 0)
    {
        return arr[idx];
    }

    if (idx < 0)
    {
        return 0;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int pick = arr[idx] + solve(idx - 2, arr, dp);
    int nonpick = 0 + solve(idx - 1, arr, dp);

    return dp[idx] = max(pick, nonpick);
}

int solveT(int n, int *arr)
{
    vector<int> dp(n + 1, 0);
    dp[0] = arr[0];

    for (int i = 1; i <= n; i++)
    {

        int pick = arr[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int non = 0 + dp[i - 1];
        dp[i] = max(pick, non);
    }
    return dp[n];
}

int solveS(int n, int *arr)
{
    int prev1 = arr[0];
    int prev2 = 0;
    for (int i = 1; i <= n; i++)
    {

        int pick = arr[i];
        if (i > 1)
        {
            pick += prev2;
        }
        int non = 0 + prev1;
        int curr = max(pick, non);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int findMaxSum(int *arr, int n)
{
    vector<int> dp(n + 1, -1);
    // return solve(n-1,arr);
    return solveS(n - 1, arr);
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}