#include <bits/stdc++.h>
using namespace std;

// Recursive TC:O(2^N) SC:O(N)
int fibrec(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fibrec(n - 1) + fibrec(n - 2);
}

// Memoization TC:O(N) SC:O(N)+O(N)
int fibMemo(int n, vector<int> dp)
{
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
}

// Tabulation TC:O(N) SC:O(N)
int fibTab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Space Optimization TC:O(N) SC:O(1)
int fibSpace(int n)
{
    int prev2 = 0;
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
    cout << fibrec(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << fibMemo(n, dp) << endl;

    cout << fibTab(n) << endl;
    cout << fibSpace(n) << endl;

    return 0;
}
