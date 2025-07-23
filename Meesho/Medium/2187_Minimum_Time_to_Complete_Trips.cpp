#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isValid(long long givenTime, vector<int> &time, int totalTrips)
  {
    long long trips = 0;

    for (long long it : time)
    {
      trips += givenTime / it;

      if (trips >= totalTrips)
        return true;
    }

    return false;
  }

  long long minimumTime(vector<int> &time, int totalTrips)
  {
    long long start = INT_MAX, end;

    for (long long it : time)
    {
      start = min(start, it);
    }

    end = start * totalTrips;

    long long result;

    while (start <= end)
    {
      long long mid = start + (end - start) / 2;

      if (isValid(mid, time, totalTrips))
      {
        result = mid;
        end = mid - 1;
      }
      else
        start = mid + 1;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> time = {1, 2, 3};
  int totalTrips = 5;

  cout << sol.minimumTime(time, totalTrips);

  return 0;
}