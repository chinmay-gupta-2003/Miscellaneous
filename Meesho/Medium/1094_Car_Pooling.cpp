#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool carPooling(vector<vector<int>> &trips, int capacity)
  {
    sort(trips.begin(), trips.end(), [](auto a, auto b)
         { return a[1] < b[1]; });

    int i = 0, n = trips.size(), currentCapcity = 0;
    int currentLocation = trips[0][1], endLocation;

    for (auto it : trips)
    {
      endLocation = max(endLocation, it[2]);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    while (currentLocation <= endLocation)
    {
      while (!pq.empty() && pq.top().first == currentLocation)
      {
        currentCapcity -= pq.top().second;

        pq.pop();
      }

      while (i < n && trips[i][1] == currentLocation)
      {
        currentCapcity += trips[i][0];

        if (currentCapcity > capacity)
          return false;

        pq.push({trips[i][2], trips[i][0]});

        i++;
      }

      currentLocation++;
    }

    return pq.size() == 0;
  }

  bool carPoolingShortMethod(vector<vector<int>> &trips, int capacity)
  {
    map<int, int> timeCapacity;

    for (auto it : trips)
    {
      timeCapacity[it[1]] += it[0];
      timeCapacity[it[2]] -= it[0];
    }

    for (auto it : timeCapacity)
    {
      capacity -= it.second;

      if (capacity < 0)
        return false;
    }

    return true;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
  int capacity = 5;

  cout << sol.carPooling(trips, capacity) << endl;
  cout << sol.carPoolingShortMethod(trips, capacity) << endl;

  return 0;
}