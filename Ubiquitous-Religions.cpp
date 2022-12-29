#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void DFS(unordered_map<int, vector<int>> &graph, vector<bool> &visited, int s)
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, c = 1;
  while (cin >> n >> m && n != m != 0)
  {
    int cnt = 0;
    unordered_map<int, vector<int>> graph;
    vector<bool> visited(n + 1, false);
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
        cnt++;
        DFS(graph, visited, i);
      }
    }
    cout << "Case " << c++ << ": " << cnt << "\n";
  }

  return 0;
}