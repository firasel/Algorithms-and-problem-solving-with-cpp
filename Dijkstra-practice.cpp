#include <bits/stdc++.h>
using namespace std;

void Dijkstra(unordered_map<int, vector<pair<int, int>>> &graph, vector<int> &distance, int &n, int s)
{
  vector<bool> visited(n + 1, false);
  distance[s] = 0;
  for (int i = 0; i < n; i++)
  {
    int selected_node = -1;
    for (int j = 1; j <= n; j++)
    {
      if (visited[j])
        continue;
      if (selected_node == -1 || distance[selected_node] > distance[j])
        selected_node = j;
    }
    visited[selected_node] = 1;
    for (auto adj_entry : graph[selected_node])
    {
      int adj_node = adj_entry.first, edge_cost = adj_entry.second;
      if (distance[selected_node] + edge_cost < distance[adj_node])
        distance[adj_node] = distance[selected_node] + edge_cost;
    }
  }
}

int main()
{
  int n, m, u, v, w;
  cin >> n >> m;
  unordered_map<int, vector<pair<int, int>>> graph;
  vector<int> distance(n + 1, INT32_MAX);
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  int src = 1;
  Dijkstra(graph, distance, n, src);

  for (int i = 1; i <= n; i++)
  {
    cout << distance[i] << " ";
  }
  cout << endl;

  return 0;
}

/*
          5
      12 /
       /
     1 --- 6
12  /  30   \ 40
  /          \
 2           7
  \         /
12 \      /  20
    3 --- 4
      12

7 7
1 2 12
1 5 12
1 6 30
2 3 12
3 4 12
4 7 20
6 7 40
*/