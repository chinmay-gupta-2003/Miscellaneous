#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int MOD = 1e9 + 7;

  int solve(int idx, int n, int c_l, int c_e, int c_t, long long dp[100001][2][3][2])
  {
    if (idx == n)
    {
      if (c_l >= 1 && c_e >= 2 && c_t >= 1)
        return 1;

      return 0;
    }

    if (dp[idx][c_l][c_e][c_t] != -1)
      return dp[idx][c_l][c_e][c_t];

    long long result = 0;

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
      if (ch == 'l' && c_l < 1)
        result = (result + solve(idx + 1, n, c_l + 1, c_e, c_t, dp)) % MOD;
      else if (ch == 'e' && c_e < 2)
        result = (result + solve(idx + 1, n, c_l, c_e + 1, c_t, dp)) % MOD;
      else if (ch == 't' && c_t < 1)
        result = (result + solve(idx + 1, n, c_l, c_e, c_t + 1, dp)) % MOD;
      else
        result = (result + solve(idx + 1, n, c_l, c_e, c_t, dp)) % MOD;
    }

    return dp[idx][c_l][c_e][c_t] = result % MOD;
  }

  int stringCount(int n)
  {
    long long dp[100001][2][3][2];
    memset(dp, -1, sizeof(dp));

    return solve(0, n, 0, 0, 0, dp);
  }
};

int main()
{
  Solution sol;
  int n = 10;

  cout << sol.stringCount(n) << endl;

  return 0;
}