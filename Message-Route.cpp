#include <bits/stdc++.h>
using namespace std;

void BFS(unordered_map<int, vector<int>> &graph, int &n, int s, int d)
{
  vector<int> visited(n + 1, -1), parent(n + 1, 0);
  queue<int> q;
  visited[s] = 1;
  parent[s] = -1;
  q.push(s);

  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    for (int v : graph[u])
    {
      if (visited[v] == -1)
      {
        parent[v] = u;
        visited[v] = visited[u] + 1;
        q.push(v);
      }
    }
  }

  if (visited[d] == -1)
    cout << "IMPOSSIBLE\n";
  else
  {
    cout << visited[d] << endl;
    vector<int> path;
    int curr_node = d;
    while (true)
    {
      path.push_back(curr_node);
      if (curr_node == s)
        break;
      curr_node = parent[curr_node];
    }
    reverse(path.begin(), path.end());
    for (int node : path)
      cout << node << " ";
    cout << endl;
  }
}

int main()
{
  int n, m, u, v, s = 1, d;
  cin >> n >> m;
  unordered_map<int, vector<int>> graph;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  BFS(graph, n, 1, n);

  return 0;
}