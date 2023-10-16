#include <iostream>
#include <vector>

using namespace std;

int solve(int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        return 0;
    }

    return solve(n - 1) + solve(n - 2);
}

int solve(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int solvetab(int n)
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

int solveS(int n)
{
    int prev = 1, prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev1;
        prev1 = prev;
        prev = curr;
    }

    return prev;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << solveS(n) << endl;
    return 0;
}
