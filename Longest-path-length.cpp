#include <bits/stdc++.h>
using namespace std;

int findLongestPath(map<int, vector<int>> &graph)
{
  int ans = 0;
  queue<int> q;
  vector<bool> visited(102, false);
  vector<int> longest(102, 0);

  for (int s = 2; s <= 101; s++)
  {
    queue<int> q;
    q.push(s);
    longest[s] = 1;
    visited[s] = true;

    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      for (int i = 0; i < graph[u].size(); i++)
      {
        int v = graph[u][i];
        if (longest[v] < longest[u] + 1 && !visited[v])
        {
          longest[v] = longest[u] + 1;
          q.push(v);
          visited[v] = true;
        }
      }
    }
  }

  for (int i = 2; i <= 101; i++)
    ans = max(ans, longest[i]);

  return ans;
}

int main()
{
  map<int, vector<int>> mp;

  for (int i = 2; i <= 101; i++)
  {
    mp[i];
    for (int j = i; j <= 101; j++)
      if (j % i == 0)
        mp[i].push_back(j);
  }

  int longest = findLongestPath(mp);
  cout << "The length of the longest path is -> " << longest << endl;

  return 0;
}
