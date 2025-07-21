#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> indexMap;

    for (int i = 0; i < nums.size(); i++)
    {
      int remainingTarget = target - nums[i];

      if (indexMap.find(remainingTarget) != indexMap.end())
        return {indexMap[remainingTarget], i};

      indexMap[nums[i]] = i;
    }

    return {-1, -1};
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  auto ans = sol.twoSum(nums, target);

  cout << ans[0] << " " << ans[1];

  return 0;
}