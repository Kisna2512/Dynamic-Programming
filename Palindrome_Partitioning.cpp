class Solution
{
public:
    bool isPalindrome(string &s)
    {
        int i = 0, j = s.size() - 1;
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, string &s, vector<int> &dp)
    {
        if (i == s.size())
        {
            return 0;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int mini = INT_MAX;
        string temp = "";

        for (int j = i; j < s.size(); j++)
        {
            temp += s[j];

            if (isPalindrome(temp))
            {
                mini = min(mini, 1 + solve(j + 1, s, dp));
            }
        }

        return dp[i] = mini;
    }

    int solve(int n, string &s)
    {
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int mini = INT_MAX;
            string temp = "";
            for (int j = i; j < s.size(); j++)
            {
                temp += s[j];
                if (isPalindrome(temp))
                {
                    mini = min(mini, 1 + dp[j + 1]);
                    dp[i] = mini;
                }
            }
        }

        return dp[0];
    }

    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(n, s) - 1;
    }
};