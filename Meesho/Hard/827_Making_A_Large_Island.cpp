#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
  vector<int> parent, size;

  DisjointSet(int n)
  {
    parent.resize(n);
    size.resize(n);

    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int FindParent(int u)
  {
    if (parent[u] == u)
      return u;

    return parent[u] = FindParent(parent[u]);
  }

  void UnionBySize(int u, int v)
  {
    int parent_U = FindParent(u), parent_V = FindParent(v);

    if (parent_U == parent_V)
      return;

    if (size[parent_U] >= size[parent_V])
    {
      size[parent_U] += size[parent_V];
      parent[parent_V] = parent_U;
    }
    else
    {
      size[parent_V] += size[parent_U];
      parent[parent_U] = parent_V;
    }
  }
};

class Solution
{
public:
  int largestIsland(vector<vector<int>> &grid)
  {
    int n = grid.size();
    DisjointSet DS(n * n);

    vector<vector<int>> coords = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j])
        {
          for (auto coord : coords)
          {
            int ni = i + coord[0];
            int nj = j + coord[1];

            if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj])
              DS.UnionBySize(ni * n + nj, i * n + j);
          }
        }
      }
    }

    int result = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 0)
        {
          int size = 1;
          unordered_set<int> adjNodes;

          for (auto coord : coords)
          {
            int ni = i + coord[0];
            int nj = j + coord[1];

            if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj])
              adjNodes.insert(DS.FindParent(ni * n + nj));
          }

          for (int s : adjNodes)
            size += DS.size[s];

          result = max(result, size);
        }
      }
    }

    return result ? result : n * n;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {{1, 1}, {1, 0}};

  cout << sol.largestIsland(grid);

  return 0;
}