class Solution
{
public:
    int solveSpace(int n, int m, string s1, string s2)
    {
        vector<int> prev(m + 1, 0);
        for (int i = 1; i < n + 1; i++)
        {
            vector<int> cur(m + 1, 0);
            for (int j = 1; j < m + 1; j++)
            {

                if (s1[i - 1] == s2[j - 1])
                    cur[j] = 1 + prev[j - 1];
                else
                    cur[j] = max(prev[j], cur[j - 1]);
            }
            prev = cur;
        }
        return prev[m];
    }
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        return solveSpace(n, n, s, t);
    }
};