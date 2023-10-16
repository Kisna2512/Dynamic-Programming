class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            mini = min(mini, prices[i]);
            ans = max(ans, (prices[i] - mini));
        }
        return ans;
    }
};