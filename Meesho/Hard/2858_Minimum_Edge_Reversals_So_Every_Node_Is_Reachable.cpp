#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dfs(int node, int parent, vector<vector<pair<int, int>>> &adjList,
          map<pair<int, int>, int> &dp)
  {
    if (dp.find({node, parent}) != dp.end())
      return dp[{node, parent}];

    int ans = 0;

    for (auto adjNode : adjList[node])
    {
      if (adjNode.first != parent)
        ans += adjNode.second + dfs(adjNode.first, node, adjList, dp);
    }

    return dp[{node, parent}] = ans;
  }

  vector<int> minEdgeReversals(int n, vector<vector<int>> &edges)
  {
    vector<vector<pair<int, int>>> adjList(n);

    for (auto edge : edges)
    {
      int u = edge[0], v = edge[1];

      adjList[u].push_back({v, 0});
      adjList[v].push_back({u, 1});
    }

    vector<int> result;
    map<pair<int, int>, int> dp;

    for (int i = 0; i < n; i++)
    {
      result.push_back(dfs(i, -1, adjList, dp));
    }

    return result;
  }
};

int main()
{
  Solution sol;
  int n = 4;
  vector<vector<int>> edges = {{2, 0}, {2, 1}, {1, 3}};

  auto ans = sol.minEdgeReversals(n, edges);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}