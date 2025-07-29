#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int n;
  int m;
  int MOD = 1e9 + 7;

  int solve(int idx, int dictIdx, string &target, vector<vector<long long>> &freq, vector<vector<long long>> &dp)
  {
    if (idx == m)
      return 1;

    if (dictIdx == n)
      return 0;

    if (dp[idx][dictIdx] != -1)
      return dp[idx][dictIdx];

    int take = (freq[target[idx] - 'a'][dictIdx] * solve(idx + 1, dictIdx + 1, target, freq, dp)) % MOD;
    int notTake = (solve(idx, dictIdx + 1, target, freq, dp)) % MOD;

    return dp[idx][dictIdx] = (take + notTake) % MOD;
  }

  int numWays(vector<string> &words, string target)
  {
    n = words[0].size();
    m = target.size();

    vector<vector<long long>> freq(26, vector<long long>(n, 0));
    vector<vector<long long>> dp(m, vector<long long>(n, -1));

    for (int i = 0; i < n; i++)
    {
      for (string &word : words)
      {
        char &ch = word[i];

        freq[ch - 'a'][i]++;
      }
    }

    return solve(0, 0, target, freq, dp);
  }
};

int main()
{
  Solution sol;
  vector<string> words = {"acca", "bbbb", "caca"};
  string target = "aba";

  return sol.numWays(words, target);

  return 0;
}