#include <bits/stdc++.h>
using namespace std;

bool BFS(unordered_map<int, vector<int>> &graph, vector<int> &indegree, int &n)
{
  queue<int> q;
  queue<int> ans;
  for (int i = 1; i <= n; i++)
  {
    if (indegree[i] == 0)
      q.push(i);
  }

  while (!q.empty())
  {
    int u = q.front();
    ans.push(u);
    q.pop();
    for (int v : graph[u])
    {
      indegree[v]--;
      if (indegree[v] == 0)
      {
        q.push(v);
      }
    }
  }
  if (ans.size() == n)
  {
    while (!ans.empty())
    {
      cout << ans.front() << " ";
      ans.pop();
    }
    cout << endl;
    return false;
  }
  return true;
}

int main()
{
  int n, m, u, v;
  cin >> n >> m;
  unordered_map<int, vector<int>> graph;
  vector<int> indegree(n + 1, 0);
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    graph[u].push_back(v);
    indegree[v]++;
  }
  if (BFS(graph, indegree, n))
    cout << "IMPOSSIBLE" << endl;
  return 0;
}

/*
5 3
1 2
3 1
4 5
*/