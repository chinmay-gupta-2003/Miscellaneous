#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestCycle(vector<int> &edges)
  {
    int n = edges.size();

    vector<int> visited(n, 0);

    int result = -1;

    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        int currNode = i;
        int currDist = 0;

        unordered_map<int, int> distMap;

        while (!visited[currNode])
        {
          visited[currNode]++;
          distMap[currNode] = currDist;
          currDist++;

          int nextNode = edges[currNode];

          if (nextNode == -1)
            break;

          if (distMap.count(nextNode))
          {
            int cycleLength = currDist - distMap[nextNode];

            result = max(result, cycleLength);

            break;
          }

          currNode = nextNode;
        }
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> edges = {2, -1, 3, 1};

  cout << sol.longestCycle(edges);

  return 0;
}