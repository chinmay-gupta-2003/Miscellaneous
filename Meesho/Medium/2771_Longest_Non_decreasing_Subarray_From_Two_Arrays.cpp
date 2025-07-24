#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int idx, int prev, int count, vector<int> &nums1, vector<int> &nums2)
  {
    if (idx == nums1.size())
      return count;

    int result = count;

    if (nums1[idx] >= prev)
      result = max(result, solve(idx + 1, nums1[idx], count + 1, nums1, nums2));
    else
      result = max(result, solve(idx + 1, nums1[idx], 1, nums1, nums2));

    if (nums2[idx] >= prev)
      result = max(result, solve(idx + 1, nums2[idx], count + 1, nums1, nums2));
    else
      result = max(result, solve(idx + 1, nums2[idx], 1, nums1, nums2));

    return result;
  }

  int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2)
  {
    return solve(0, -1, 0, nums1, nums2);
  }

  int solveBottomUp(int idx, int arrNum, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
  {
    if (idx == nums1.size())
      return 0;

    if (dp[idx][arrNum] != -1)
      return dp[idx][arrNum];

    int result = 0;

    if (arrNum == 0)
    {
      result = max(result, solveBottomUp(idx + 1, 0, nums1, nums2, dp));
      result = max(result, 1 + solveBottomUp(idx + 1, 1, nums1, nums2, dp));
      result = max(result, 1 + solveBottomUp(idx + 1, 2, nums1, nums2, dp));
    }
    else if (arrNum == 1)
    {
      if (nums1[idx] >= nums1[idx - 1])
        result = max(result, 1 + solveBottomUp(idx + 1, 1, nums1, nums2, dp));

      if (nums2[idx] >= nums1[idx - 1])
        result = max(result, 1 + solveBottomUp(idx + 1, 2, nums1, nums2, dp));
    }
    else
    {
      if (nums1[idx] >= nums2[idx - 1])
        result = max(result, 1 + solveBottomUp(idx + 1, 1, nums1, nums2, dp));

      if (nums2[idx] >= nums2[idx - 1])
        result = max(result, 1 + solveBottomUp(idx + 1, 2, nums1, nums2, dp));
    }

    return dp[idx][arrNum] = result;
  }

  int maxNonDecreasingLengthMemoization(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size();

    vector<vector<int>> dp(n, vector<int>(3, -1));

    return solveBottomUp(0, 0, nums1, nums2, dp);
  }
};

int main()
{
  Solution sol;
  vector<int> nums1 = {2, 3, 1}, nums2 = {1, 2, 1};

  cout << sol.maxNonDecreasingLength(nums1, nums2) << endl;
  cout << sol.maxNonDecreasingLengthMemoization(nums1, nums2) << endl;

  return 0;
}