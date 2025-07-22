#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minPartitionsBrute(string n)
  {
    int result = 0;

    while (stoi(n) > 0)
    {
      string num = "";

      for (char &ch : n)
      {
        if (ch == '0')
          num.push_back('0');
        else
          num.push_back('1');
      }

      result += stoi(n) / stoi(num);

      n = to_string(stoi(n) % stoi(num));
    }

    return result;
  }

  int minPartitions(string n)
  {
    int result = 0;

    for (char &ch : n)
    {
      result = max(result, ch - '0');
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string n = "1098";

  cout << sol.minPartitionsBrute(n) << endl;
  cout << sol.minPartitions(n) << endl;

  return 0;
}