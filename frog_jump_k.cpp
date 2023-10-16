#include <bits/stdc++.h>
using namespace std;
int solve(int ind, vector<int> &v, int k)
{
    if (ind == 0)
    {
        return 0;
    }
    int min_steps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
        {
            int jump = solve(ind - j, v, k) + abs(v[ind] - v[ind - j]);
            min_steps = min(min_steps, jump);
        }
    }
    return min_steps;
}
int solve(int ind, vector<int> &v, int k, vector<int> &dp)
{
    if (ind == 0)
    {
        return 0;
    }
    int min_steps = INT_MAX;
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
        {
            int jump = solve(ind - j, v, k, dp) + abs(v[ind] - v[ind - j]);
            min_steps = min(min_steps, jump);
        }
    }
    return dp[ind] = min_steps;
}

int solveT(int n, vector<int> &v, int k)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int min_steps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(v[i] - v[i - j]);
                dp[i] = min(min_steps, jump);
            }
        }
    }
    return dp[n];
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
    int k = 2;
    cout << solveT(n - 1, v, k) << endl;
    return 0;
}