#include <bits/stdc++.h>
using namespace std;

void DFS(unordered_map<int, vector<int>> &graph, unordered_map<int, bool> &visited, int node)
{
  visited[node] = true;
  for (auto chNode : graph[node])
  {
    if (!visited[chNode])
      DFS(graph, visited, chNode);
  }
}

int connected_components(unordered_map<int, vector<int>> &graph, int n)
{
  int count = 0;
  unordered_map<int, bool> visited;
  for (auto el : graph)
  {
    visited[el.first] = false;
  }

  for (auto el : graph)
  {
    if (!visited[el.first])
    {
      count++;
      DFS(graph, visited, el.first);
    }
  }
  count += fabs(n - graph.size());
  return count;
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

  cout << "Total connected components: " << connected_components(graph, n) << endl;

  return 0;
}

/*

5 4
1 2
1 3
2 3
4 5

6 4
1 2
1 3
2 3
4 5

7 4
1 2
1 3
2 3
4 5

*/