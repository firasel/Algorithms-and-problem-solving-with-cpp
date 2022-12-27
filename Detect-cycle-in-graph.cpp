#include <bits/stdc++.h>
using namespace std;

bool DFS(unordered_map<int, vector<int>> &graph, vector<bool> &visited, vector<int> &parent, int s, int p)
{
  visited[s] = true;
  parent[s] = p;
  for (int adj_node : graph[s])
  {
    if (!visited[adj_node])
    {
      if (DFS(graph, visited, parent, adj_node, s))
        return true;
    }
    else if (parent[s] != adj_node)
      return true;
  }
  return false;
}

bool detect_cycle(unordered_map<int, vector<int>> &graph, int n, int s)
{
  vector<bool> visited(n + 1, false);
  vector<int> parent(n + 1, 0);
  return DFS(graph, visited, parent, s, -1);
}

int main()
{
  int n, m;
  cin >> n >> m;
  unordered_map<int, vector<int>> graph;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  if (detect_cycle(graph, n, 0))
    cout << "Cycle detected" << endl;
  else
    cout << "Not found any cycle" << endl;

  return 0;
}

/*
0 --- 1 --- 2 --- 4 --- 5
      \    /
       \ /
        3

5 6
0 1
1 2
1 3
2 3
2 4
4 5


0 --- 1 --- 2 --- 4 --- 5
      \
       \
        3

5 5
0 1
1 2
1 3
2 4
4 5

*/