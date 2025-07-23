#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int idx, int n, unordered_set<int> &usedNums)
  {
    if (idx > n)
      return 1;

    int result = 0;

    for (int i = 1; i <= n; i++)
    {
      if (usedNums.find(i) != usedNums.end())
        continue;

      if (i % idx == 0 || idx % i == 0)
      {
        usedNums.insert(i);

        result += solve(idx + 1, n, usedNums);

        usedNums.erase(i);
      }
    }

    return result;
  }

  int countArrangement(int n)
  {
    unordered_set<int> usedNums;

    return solve(1, n, usedNums);
  }
};

int main()
{
  Solution sol;
  int n = 4;

  cout << sol.countArrangement(n) << endl;

  return 0;
}