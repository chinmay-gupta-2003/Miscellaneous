#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximumProductBrute(vector<int> &nums)
  {
    int n = nums.size();
    int result = INT_MIN;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        for (int k = j + 1; k < n; k++)
        {
          result = max(result, nums[i] * nums[j] * nums[k]);
        }
      }
    }

    return result;
  }

  int maximumProductBetter(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int result = INT_MIN;

    for (int i = 0; i < 6; i++)
    {
      result = max(result, nums[(n - 3 + i) % n] * nums[(n - 2 + i) % n] * nums[(n - 1 + i) % n]);
    }

    return result;
  }

  int maximumProductOptimal(vector<int> &nums)
  {
    int n = nums.size();

    int minOne = INT_MAX, minTwo = INT_MAX;
    int maxOne = INT_MIN, maxTwo = INT_MIN, maxThree = INT_MIN;

    for (int num : nums)
    {
      if (num >= maxOne)
      {
        maxThree = maxTwo;
        maxTwo = maxOne;
        maxOne = num;
      }
      else if (num >= maxTwo)
      {
        maxThree = maxTwo;
        maxTwo = num;
      }
      else if (num > maxThree)
        maxThree = num;

      if (num <= minOne)
      {
        minTwo = minOne;
        minOne = num;
      }
      else if (num < minTwo)
        minTwo = num;
    }

    return max(maxOne * maxTwo * maxThree, maxOne * minOne * minTwo);
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {-1, -2, -3};

  cout << sol.maximumProductBrute(nums) << endl;
  cout << sol.maximumProductBetter(nums) << endl;
  cout << sol.maximumProductOptimal(nums) << endl;

  return 0;
}