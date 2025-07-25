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

    if (n < 3)
      return n;

    int bits = 0;

    while (n)
    {
      bits++;
      n = n >> 1;
    }

    return pow(2, bits);
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2};

  cout << sol.uniqueXorTripletsBrute(nums) << endl;
  cout << sol.uniqueXorTripletsOptimal(nums) << endl;

  return 0;
}