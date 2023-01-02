#include <bits/stdc++.h>
using namespace std;

void DFS(map<int, vector<int>> &graph, vector<bool> &visited, int s)
{
  visited[s] = true;
  for (auto v : graph[s])
  {
    if (!visited[v])
      DFS(graph, visited, v);
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> graph;

  vector<bool> visited(n + 1, false);
  vector<int> ans;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      ans.push_back(i);
      DFS(graph, visited, i);
    }
  }
  cout << ans.size() - 1 << endl;
  for (int i = 0; i < ans.size() - 1; i++)
    cout << ans[i] << " " << ans[i + 1] << endl;

  return 0;
}

/*
4 2
1 2
3 4
*/