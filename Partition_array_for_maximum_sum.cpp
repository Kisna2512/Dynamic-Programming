class Solution
{
public:
    int solve(int idx, int k, int n, vector<int> &arr)
    {
        if (idx == arr.size())
        {
            return 0;
        }

        int len = 0, maxi = INT_MIN;
        int maxAns = 0;
        for (int j = idx; j < min(n, idx + k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + solve(j + 1, k, n, arr);
            maxAns = max(maxAns, sum);
        }

        return maxAns;
    }

    int solve(int idx, int k, int n, vector<int> &arr, vector<int> &dp)
    {
        if (idx == arr.size())
        {
            return 0;
        }
        if (dp[idx] != -1)
        {
            return dp[idx];
        }
        int len = 0, maxi = INT_MIN;
        int maxAns = 0;
        for (int j = idx; j < min(n, idx + k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + solve(j + 1, k, n, arr, dp);
            maxAns = max(maxAns, sum);
        }

        return dp[idx] = maxAns;
    }

    int solve(int k, int n, vector<int> &arr)
    {

        vector<int> dp(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--)
        {
            int len = 0, maxi = INT_MIN;
            int maxAns = 0;
            for (int j = idx; j < min(n, idx + k); j++)
            {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len * maxi + dp[j + 1];
                maxAns = max(maxAns, sum);
            }

            dp[idx] = maxAns;
        }
        return dp[0];
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return solve(k, n, arr);
    }
};