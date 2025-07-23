#include <bits/stdc++.h>
using namespace std;

class Twitter
{
public:
  int timestamp;
  unordered_map<int, vector<pair<int, int>>> tweets;
  unordered_map<int, unordered_set<int>> following;

  Twitter() { timestamp = 0; }

  void postTweet(int userId, int tweetId)
  {
    tweets[userId].push_back({timestamp, tweetId});
    timestamp++;
  }

  vector<int> getNewsFeed(int userId)
  {
    priority_queue<pair<int, int>> maxHeap;

    for (auto it : tweets[userId])
    {
      maxHeap.push(it);
    }

    for (auto followee : following[userId])
    {
      for (auto it : tweets[followee])
      {
        maxHeap.push(it);
      }
    }

    vector<int> result;

    for (int i = 1; i <= 10 && !maxHeap.empty(); i++)
    {
      auto top = maxHeap.top();

      result.push_back(top.second);

      maxHeap.pop();
    }

    return result;
  }

  void follow(int followerId, int followeeId)
  {
    following[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId)
  {
    following[followerId].erase(followeeId);
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main()
{
  return 0;
}