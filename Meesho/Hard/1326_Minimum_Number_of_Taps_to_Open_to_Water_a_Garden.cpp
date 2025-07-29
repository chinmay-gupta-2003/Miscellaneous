#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int index, int maxRight, vector<pair<int, int>> &ranges, map<pair<int, int>, int> &dp)
  {
    if (index >= ranges.size())
    {
      if (maxRight >= ranges.size() - 1)
        return 0;

      return 1e9;
    }

    if (ranges[index].first > maxRight)
      return 1e9;

    if (dp.find({index, maxRight}) != dp.end())
      return dp[{index, maxRight}];

    int take = 1 + solve(index + 1, max(maxRight, ranges[index].second), ranges, dp);

    int notTake = solve(index + 1, maxRight, ranges, dp);

    return dp[{index, maxRight}] = min(take, notTake);
  }

  int minTaps(int n, vector<int> &ranges)
  {
    vector<pair<int, int>> rangesSorted;

    for (int i = 0; i <= n; i++)
    {
      int leftRange = max(0, i - ranges[i]);
      int rightRange = min(n, i + ranges[i]);

      rangesSorted.push_back({leftRange, rightRange});
    }

    sort(rangesSorted.begin(), rangesSorted.end());

    map<pair<int, int>, int> dp;

    int result = solve(0, 0, rangesSorted, dp);

    if (result >= 1e9)
      return -1;

    return result;
  }

  int minTapsOptimal(int n, vector<int> &ranges)
  {
    vector<int> startEnd(n + 1, 0);

    for (int i = 0; i <= n; i++)
    {
      int start = max(0, i - ranges[i]);
      int end = min(n, i + ranges[i]);

      startEnd[start] = max(startEnd[start], end);
    }

    int result = 0, currentEnd = 0, maxEnd = 0;

    for (int i = 0; i <= n; i++)
    {
      if (i > maxEnd)
        return -1;

      if (i > currentEnd)
      {
        result++;
        currentEnd = maxEnd;
      }

      maxEnd = max(maxEnd, startEnd[i]);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  int n = 5;
  vector<int> ranges = {3, 4, 1, 1, 0, 0};

  cout << sol.minTaps(n, ranges) << endl;
  cout << sol.minTapsOptimal(n, ranges) << endl;

  return 0;
}