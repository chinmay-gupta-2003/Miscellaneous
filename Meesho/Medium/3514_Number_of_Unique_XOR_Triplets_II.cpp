#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int uniqueXorTripletsBrute(vector<int> &nums)
  {
    int n = nums.size();

    unordered_set<int> uniqueXOR;

    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        for (int k = j; k < n; k++)
        {
          uniqueXOR.insert(nums[i] ^ nums[j] ^ nums[k]);
        }
      }
    }

    return uniqueXOR.size();
  }

  int uniqueXorTripletsOptimal(vector<int> &nums)
  {
    int n = nums.size();

    unordered_set<int> twoXOR;

    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        twoXOR.insert(nums[i] ^ nums[j]);
      }
    }

    unordered_set<int> result;

    for (int i = 0; i < n; i++)
    {
      for (int XOR : twoXOR)
      {
        result.insert(XOR ^ nums[i]);
      }
    }

    return result.size();
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3};

  cout << sol.uniqueXorTripletsBrute(nums) << endl;
  cout << sol.uniqueXorTripletsOptimal(nums) << endl;

  return 0;
}