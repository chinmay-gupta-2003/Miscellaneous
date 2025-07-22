#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
  {
    int n = customers.size(), total = 0;

    for (int i = 0; i < n; i++)
    {
      if (grumpy[i] == 0)
        total += customers[i];
    }

    int i = 0, j = 0;

    while (j < minutes)
    {
      if (grumpy[j] == 1)
        total += customers[j];

      j++;
    }

    int result = total;

    while (j < n)
    {
      if (grumpy[j] == 1)
        total += customers[j];

      if (grumpy[i] == 1)
        total -= customers[i];

      result = max(result, total);

      i++;
      j++;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> customers = {4, 10, 10}, grumpy = {1, 1, 0};
  int minutes = 2;

  cout << sol.maxSatisfied(customers, grumpy, minutes) << endl;

  return 0;
}