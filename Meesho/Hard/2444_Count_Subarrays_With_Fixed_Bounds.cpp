#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long countSubarrays(vector<int> &nums, int minK, int maxK)
  {
    int n = nums.size();

    int result = 0;

    for (int i = 0; i < n; i++)
    {
      int mini = nums[i], maxi = nums[i];

      for (int j = i; j < n; j++)
      {
        mini = min(mini, nums[j]);
        maxi = max(maxi, nums[j]);

        if (mini == minK && maxi == maxK)
          result++;
        else if (mini < minK || maxi > maxK)
          break;
      }
    }

    return result;
  }

  long long countSubarraysOptimal(vector<int> &nums, int minK, int maxK)
  {
    int minKIdx = -1, maxKIdx = -1, culpritIdx = -1;

    long long result = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == minK)
        minKIdx = i;
      if (nums[i] == maxK)
        maxKIdx = i;
      if (nums[i] < minK || nums[i] > maxK)
        culpritIdx = i;

      int smallerIdx = min(minKIdx, maxKIdx);

      if (smallerIdx - culpritIdx > 0)
        result += smallerIdx - culpritIdx;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 3, 5, 2, 7, 5};
  int minK = 1, maxK = 5;

  cout << sol.countSubarrays(nums, minK, maxK) << endl;
  cout << sol.countSubarraysOptimal(nums, minK, maxK) << endl;

  return 0;
}