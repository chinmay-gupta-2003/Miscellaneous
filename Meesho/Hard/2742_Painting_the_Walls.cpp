#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int index, int wallsRemaining, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp)
  {
    if (wallsRemaining <= 0)
      return 0;

    if (index >= cost.size())
      return 1e8;

    if (dp[index][wallsRemaining] != -1)
      return dp[index][wallsRemaining];

    int paint = cost[index] + solve(index + 1, wallsRemaining - 1 - time[index], cost, time, dp);
    int notPaint = solve(index + 1, wallsRemaining, cost, time, dp);

    return dp[index][wallsRemaining] = min(paint, notPaint);
  }

  int paintWalls(vector<int> &cost, vector<int> &time)
  {
    int n = cost.size();

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return solve(0, n, cost, time, dp);
  }
};

int main()
{
  Solution sol;
  vector<int> cost = {1, 2, 3, 2}, time = {1, 2, 3, 2};

  cout << sol.paintWalls(cost, time);

  return 0;
}