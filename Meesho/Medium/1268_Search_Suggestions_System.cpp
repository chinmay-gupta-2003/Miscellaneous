#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<string>> suggestedProductsBrute(vector<string> &products, string searchWord)
  {
    sort(products.begin(), products.end());

    int n = searchWord.size();

    vector<vector<string>> result;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;

      for (string &s : products)
      {
        if (temp.size() == 3)
          break;

        if (s.find(searchWord.substr(0, i + 1)) == 0)
          temp.push_back(s);
      }

      result.push_back(temp);
    }

    return result;
  }

  vector<vector<string>> suggestedProductsBetter(vector<string> &products, string searchWord)
  {
    sort(products.begin(), products.end());

    int n = searchWord.size();

    string prefix = "";
    vector<vector<string>> result;

    for (int i = 0; i < n; i++)
    {
      prefix.push_back(searchWord[i]);

      int index = lower_bound(products.begin(), products.end(), prefix) - products.begin();

      result.push_back({});

      for (int j = index; j < min(index + 3, (int)products.size()) && products[j].compare(0, prefix.size(), prefix) == 0; j++)
      {
        result.back().push_back(products[j]);
      }
    }

    return result;
  }

  vector<vector<string>> suggestedProductsOptimal(vector<string> &products, string searchWord)
  {
    sort(products.begin(), products.end());

    int n = searchWord.size();

    string prefix = "";
    vector<vector<string>> result;

    for (int i = 0; i < n; i++)
    {
      prefix.push_back(searchWord[i]);

      int index = lower_bound(products.begin(), products.end(), prefix) - products.begin();

      result.push_back({});

      for (int j = index; j < min(index + 3, (int)products.size()) && products[j].compare(0, prefix.size(), prefix) == 0; j++)
      {
        result.back().push_back(products[j]);
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<string> products = {"havana"};
  string searchWord = "havana";

  auto ans = sol.suggestedProductsBrute(products, searchWord);

  for (auto it : ans)
  {
    for (auto it2 : it)
      cout << it2 << ", ";

    cout << endl;
  }

  cout << endl;

  ans = sol.suggestedProductsBetter(products, searchWord);

  for (auto it : ans)
  {
    for (auto it2 : it)
      cout << it2 << ", ";

    cout << endl;
  }

  return 0;
}