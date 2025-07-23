#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int idx, vector<int> &nums, vector<int> &dp)
  {
    if (idx == nums.size())
      return 0;

    if (dp[idx] != -1)
      return dp[idx];

    int currIndex = idx, currElement = nums[idx];
    int take = 0;

    while (currIndex < nums.size() && nums[currIndex] == currElement)
    {
      take += currElement;
      currIndex++;
    }

    while (currIndex < nums.size() && nums[currIndex] == currElement + 1)
    {
      currIndex++;
    }

    take += solve(currIndex, nums, dp);

    int notTake = solve(idx + 1, nums, dp);

    return dp[idx] = max(take, notTake);
  }

  int deleteAndEarn(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    vector<int> dp(nums.size(), -1);

    return solve(0, nums, dp);
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 2, 3, 3, 3, 4};

  cout << sol.deleteAndEarn(nums) << endl;

  return 0;
}