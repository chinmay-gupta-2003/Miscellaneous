#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestEqualSubarrayBrute(vector<int> &nums, int k)
  {
    int n = nums.size();
    int result = 1;

    for (int i = 0; i < n; i++)
    {
      int equalNums = 0, numsDeleted = 0;

      for (int j = i; j < n && numsDeleted <= k; j++)
      {
        if (nums[i] == nums[j])
          equalNums++;
        else
          numsDeleted++;
      }

      result = max(result, equalNums);
    }

    return result;
  }

  int longestEqualSubarrayOptimal(vector<int> &nums, int k)
  {
    int n = nums.size();
    unordered_map<int, int> freqMap;

    int i = 0, j = 0, result = 1;

    while (j < n)
    {
      freqMap[nums[j]]++;

      result = max(result, freqMap[nums[j]]);

      if (j - i + 1 - result > k)
      {
        freqMap[nums[i]]--;
        i++;
      }

      j++;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 3, 2, 3, 1, 3};
  int k = 3;

  cout << sol.longestEqualSubarrayBrute(nums, k) << endl;
  cout << sol.longestEqualSubarrayOptimal(nums, k) << endl;

  return 0;
}