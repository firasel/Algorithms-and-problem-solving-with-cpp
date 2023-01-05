#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

unordered_map<int, vector<pair<int, int>>> graph;
int d[N], visited[N];
int n, m;

void dijkstra(int s)
{
  for (int i = 1; i <= n; i++)
  {
    d[i] = INF;
  }
  d[s] = 0;
  for (int i = 0; i < n; i++)
  {
    int selected_node = -1;
    for (int j = 1; j <= n; j++)
    {
      if (visited[j] == 1)
        continue;
      if (selected_node == -1 || d[selected_node] > d[j])
        selected_node = j;
    }
    visited[selected_node] = 1;
    for (auto adj_entry : graph[selected_node])
    {
      int adj_node = adj_entry.first, edge_cost = adj_entry.second;
      if (d[selected_node] + edge_cost < d[adj_node])
        d[adj_node] = d[selected_node] + edge_cost;
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
  for (int i = 1; i <= n; i++)
  {
    cout << d[i] << " ";
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