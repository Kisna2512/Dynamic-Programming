
string solveTab(int n, int m, string s1, string s2)
{

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {

            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int len = dp[n][m];
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        ans += "$";
    }

    int idx = len - 1;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans[idx] = s1[i - 1];
            idx--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return ans;
}

string findLCS(int n, int m, string &s1, string &s2)
{
    return solveTab(n, m, s1, s2);
}