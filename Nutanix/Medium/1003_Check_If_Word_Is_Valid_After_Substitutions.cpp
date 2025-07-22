#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isValidBrute(string s)
  {
    while (!s.empty())
    {
      if (s.find("abc") == string::npos)
        return false;

      s.erase(s.find("abc"), 3);
    }

    return true;
  }

  bool isValidBetter(string s)
  {
    vector<char> check;

    for (char &ch : s)
    {
      if (ch == 'c')
      {
        int n = check.size();

        if (n < 2 || check[n - 1] != 'b' || check[n - 2] != 'a')
          return false;

        check.pop_back();
        check.pop_back();
      }
      else
        check.push_back(ch);
    }

    return check.size() == 0;
  }
};

int main()
{
  Solution sol;
  string s = "bac";

  cout << sol.isValidBrute(s) << endl;
  cout << sol.isValidBetter(s) << endl;

  return 0;
}