#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int maxIndexReached = 0;
    int n = nums.size();

    for (int i = 0; i <= min(maxIndexReached, n - 1); i++)
    {
      maxIndexReached = max(maxIndexReached, nums[i] + i);
    }

    return maxIndexReached >= n - 1;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 3, 1, 1, 4};

  cout << sol.canJump(nums);

  return 0;
}