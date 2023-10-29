class Solution
{
public:
    int mod = 1003;
    long long solve(int i, int j, int isTrue, string s)
    {
        if (i > j)
        {
            return 0;
        }

        if (i == j)
        {
            if (isTrue)
            {
                return s[i] == 'T';
            }
            else
            {
                return s[i] == 'F';
            }
        }
        long long ways = 0;
        for (int ind = i + 1; ind <= j - 1; ind = ind + 2)
        {
            long long lt = solve(i, ind - 1, 1, s);
            long long lf = solve(i, ind - 1, 0, s);
            long long rt = solve(ind + 1, j, 1, s);
            long long rf = solve(ind + 1, j, 0, s);

            if (s[ind] == '&')
            {
                if (isTrue)
                {
                    ways = (ways + (rt * lt) % mod) % mod;
                }
                else
                {
                    ways = (ways + (rt * lf) % mod + (rf * lt) % mod + (rf * lf) % mod) % mod;
                }
            }
            else if (s[ind] == '|')
            {
                if (isTrue)
                {
                    ways = (ways + (lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
                }
                else
                {
                    ways = (ways + (lf * rf) % mod) % mod;
                }
            }
            else
            {
                if (isTrue)
                {
                    ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
                }
                else
                {
                    ways = (ways + (lt * rt) % mod + (lf * rf) % mod) % mod;
                }
            }
        }

        return ways;
    }

    long long solve(int i, int j, int isTrue, string s, vector<vector<vector<long long>>> &dp)
    {
        if (i > j)
        {
            return 0;
        }

        if (i == j)
        {
            if (isTrue)
            {
                return s[i] == 'T';
            }
            else
            {
                return s[i] == 'F';
            }
        }
        if (dp[i][j][isTrue] != -1)
        {
            return dp[i][j][isTrue];
        }
        long long ways = 0;
        for (int ind = i + 1; ind <= j - 1; ind = ind + 2)
        {
            long long lt = solve(i, ind - 1, 1, s, dp);
            long long lf = solve(i, ind - 1, 0, s, dp);
            long long rt = solve(ind + 1, j, 1, s, dp);
            long long rf = solve(ind + 1, j, 0, s, dp);

            if (s[ind] == '&')
            {
                if (isTrue)
                {
                    ways = (ways + (rt * lt) % mod) % mod;
                }
                else
                {
                    ways = (ways + (rt * lf) % mod + (rf * lt) % mod + (rf * lf) % mod) % mod;
                }
            }
            else if (s[ind] == '|')
            {
                if (isTrue)
                {
                    ways = (ways + (lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
                }
                else
                {
                    ways = (ways + (lf * rf) % mod) % mod;
                }
            }
            else
            {
                if (isTrue)
                {
                    ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
                }
                else
                {
                    ways = (ways + (lt * rt) % mod + (lf * rf) % mod) % mod;
                }
            }
        }

        return dp[i][j][isTrue] = ways;
    }

    int countWays(int N, string S)
    {
        vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(N, vector<long long>(2, -1)));
        return solve(0, N - 1, 1, S, dp);
    }
};