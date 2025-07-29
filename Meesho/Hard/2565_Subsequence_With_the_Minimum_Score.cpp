#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumScore(string s, string t)
  {
    int n1 = s.length(), n2 = t.length();
    vector<int> suffix(n1, 0), prefix(n1, 0);

    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
      if (s[i] == t[j])
      {
        prefix[i]++;
        j++;
      }

      if (i > 0)
        prefix[i] += prefix[i - 1];

      i++;
    }

    i = n1 - 1, j = n2 - 1;

    while (i >= 0 && j >= 0)
    {
      if (s[i] == t[j])
      {
        suffix[i]++;
        j--;
      }

      if (i < n1 - 1)
        suffix[i] += suffix[i + 1];

      i--;
    }

    int result = n2;

    for (int i = 0; i < n1 - 1; i++)
    {
      result = min(result, n2 - (prefix[i] + suffix[i + 1]));
    }

    result = min({result, n2 - suffix[0], n2 - prefix[n1 - 1]});

    result = max(result, 0);

    return result;
  }
};

int main()
{
  Solution sol;
  string s = "abacaba", t = "dzaa";

  cout << sol.minimumScore(s, t);

  return 0;
}