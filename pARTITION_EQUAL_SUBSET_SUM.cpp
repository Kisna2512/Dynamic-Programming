
bool solve(int i, vector<int> &arr, int n, int target, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return true;
    }
    if (i == 0)
    {
        return (arr[i] == target);
    }
    if (dp[i][target] != -1)
    {
        return dp[i][target];
    }
    bool take = false;
    if (target >= arr[i])
    {
        take = solve(i - 1, arr, n, target - arr[i], dp);
    }
    bool ntake = solve(i - 1, arr, n, target, dp);
    return dp[i][target] = (take | ntake);
}
