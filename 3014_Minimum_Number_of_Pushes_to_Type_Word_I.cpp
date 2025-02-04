#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumPushes(string word)
  {
    unordered_map<int, int> freqMap;

    int key = 2, result = 0;

    for (int i = 0; i < word.size(); i++)
    {
      if (key > 9)
        key = 2;

      freqMap[key]++;

      result += freqMap[key];

      key++;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string word = "abcde";

  cout << sol.minimumPushes(word);

  return 0;
}