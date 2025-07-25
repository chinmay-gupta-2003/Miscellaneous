#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int firstSmall(vector<int> &nums)
  {
    for (int i = nums.size() - 1; i >= 1; i--)
    {
      if (nums[i] > nums[i - 1])
        return i - 1;
    }

    return -1;
  }

  int justGreater(vector<int> &nums, int index)
  {
    for (int i = nums.size() - 1; i > index; i--)
    {
      if (nums[i] > nums[index])
        return i;
    }

    return -1;
  }

  void nextPermutation(vector<int> &nums)
  {
    int firstSmallIndex = firstSmall(nums);

    if (firstSmallIndex == -1)
    {
      reverse(nums.begin(), nums.end());
      return;
    }

    int justGreaterIndex = justGreater(nums, firstSmallIndex);

    swap(nums[justGreaterIndex], nums[firstSmallIndex]);
    reverse(nums.begin() + firstSmallIndex + 1, nums.end());
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 4, 7, 6, 3, 2};

  for (int num : nums)
    cout << num << " ";

  return 0;
}