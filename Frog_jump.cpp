#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int> &v)
{
    if (ind == 0)
    {
        return 0;
    }

    int left = solve(ind - 1, v) + abs(v[ind] - v[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
    {
        right = solve(ind - 2, v) + abs(v[ind] - v[ind - 2]);
    }
    return min(left, right);
}

int solve(int ind, vector<int> &v, vector<int> &dp)
{
    if (ind == 0)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int left = solve(ind - 1, v, dp) + abs(v[ind] - v[ind - 1]);

    int right = INT_MAX;
    if (ind > 1)
    {
        right = solve(ind - 2, v, dp) + abs(v[ind] - v[ind - 2]);
    }
    return dp[ind] = min(left, right);
}

int solveT(int n, vector<int> &v)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int left = dp[i - 1] + abs(v[i] - v[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = dp[i - 2] + abs(v[i] - v[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n];
}

int solveS(int n, vector<int> &v)
{
    int prev = 0, prev1 = 0;

    for (int i = 1; i <= n; i++)
    {
        int left = prev + abs(v[i] - v[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = prev1 + abs(v[i] - v[i - 2]);
        }
        int curr = min(left, right);

        prev1 = prev;
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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {

        cin >> v[i];
    }
    vector<int> dp(n + 1, -1);
    cout << solveS(n - 1, v) << endl;

    return 0;
}