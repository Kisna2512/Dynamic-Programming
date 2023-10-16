class Solution {
  public:
    // recursive
    bool solve(int i, int j, string s, string p) {
      if (i < 0 && j < 0) {
        return true;
      }

      if (i < 0 && j >= 0) {
        return false;
      }

      if (j < 0 && i >= 0) {
        for (int k = 0; k <= i; k++) {
          if (s[k] != '*') {
            return false;
          }
        }
        return true;
      }
      if (s[i] == p[j] || s[i] == '?') {
        return solve(i - 1, j - 1, s, p);
      }

      if (s[i] == '*') {
        return (solve(i - 1, j, s, p) || solve(i, j - 1, s, p));
      }

      return false;
    }

  //memoization
  bool solve(int i, int j, string s, string p, vector < vector < int >> & dp) {
    if (i < 0 && j < 0) {
      return true;
    }

    if (i < 0 && j >= 0) {
      return false;
    }

    if (j < 0 && i >= 0) {
      for (int k = 0; k <= i; k++) {
        if (s[k] != '*') {
          return false;
        }
      }
      return true;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    if (s[i] == p[j] || s[i] == '?') {
      return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
    }

    if (s[i] == '*') {
      return dp[i][j] = (solve(i - 1, j, s, p, dp) || solve(i, j - 1, s, p, dp));
    }

    return dp[i][j] = false;
  }

  // tabulation
  bool solveTab(int n, int m, string s, string p) {
    vector < vector < bool >> dp(n + 1, vector < bool > (m + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= m; j++) {
      dp[0][j] = false;
    }

    for (int i = 1; i <= n; i++) {
      bool flag = true;
      for (int k = 1; k <= i; k++) {
        if (s[k - 1] != '*') {
          flag = false;
          break;
        }
      }
      dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s[i - 1] == p[j - 1] || s[i - 1] == '?') {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (s[i - 1] == '*') {
          dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
        } else {
          dp[i][j] = false;
        }

      }
    }
    return dp[n][m];
  }

  // space optimization
  bool solveSpace(int n, int m, string s, string p) {
    vector < bool > prev(m + 1, false), cur(m + 1, false);
    prev[0] = true;
    for (int j = 1; j <= m; j++) {
      prev[j] = false;
    }

    for (int i = 1; i <= n; i++) {
      bool flag = true;
      for (int k = 1; k <= i; k++) {
        if (s[k - 1] != '*') {
          flag = false;
          break;
        }
      }
      cur[0] = flag;
      for (int j = 1; j <= m; j++) {
        if (s[i - 1] == p[j - 1] || s[i - 1] == '?') {
          cur[j] = prev[j - 1];
        } else if (s[i - 1] == '*') {
          cur[j] = prev[j] | cur[j - 1];
        } else {
          cur[j] = false;
        }

      }
      prev = cur;
    }
    return prev[m];
  }

  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector < vector < int >> dp(m, vector < int > (n, -1));
    return solveSpace(m, n, p, s);
  }
};