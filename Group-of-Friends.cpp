#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void DFS(unordered_map<int, vector<int>> &graph, vector<bool> &visited, int s, int &cnt)
{
  cnt++;
  visited[s] = true;
  for (auto v : graph[s])
  {
    if (!visited[v])
      DFS(graph, visited, v, cnt);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    int ans = 0, cnt, n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> graph;
    vector<bool> visited(n + 2, false);
    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
      cnt = 0;
      if (!visited[i])
        DFS(graph, visited, i, cnt);
      ans = max(ans, cnt);
    }
    cout << ans << "\n";
  }

  return 0;
}