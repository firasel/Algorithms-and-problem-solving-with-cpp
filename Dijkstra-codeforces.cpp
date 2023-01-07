#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

unordered_map<int, vector<pair<int, int>>> graph;
long long d[N];
int visited[N], parent[N];
int n, m;

void dijkstra(int s)
{
  for (int i = 1; i <= n; i++)
  {
    d[i] = INF;
  }
  d[s] = 0;
  priority_queue<pair<long long, int>> pq;
  pq.push({0, s});

  while (!pq.empty())
  {
    auto head = pq.top();
    pq.pop();
    int selected_node = head.second;
    if (visited[selected_node])
      continue;

    visited[selected_node] = 1;

    for (auto adj_entry : graph[selected_node])
    {
      int adj_node = adj_entry.first, edge_cost = adj_entry.second;
      if (d[selected_node] + edge_cost < d[adj_node])
      {
        d[adj_node] = d[selected_node] + edge_cost;
        parent[adj_node] = selected_node;
        pq.push({-d[adj_node], adj_node});
      }
    }
  }
}

int main()
{
  int u, v, w;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  int src = 1;
  dijkstra(src);
  if (visited[n] == 0)
  {
    cout << -1 << endl;
    return 0;
  }

  int curr = n;
  vector<int> path;
  while (true)
  {
    path.push_back(curr);
    if (curr == src)
      break;
    curr = parent[curr];
  }

  reverse(path.begin(), path.end());

  for (int node : path)
    cout << node << " ";
  cout << endl;

  return 0;
}