#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long INF = 1e18;

vector<pair<int, int>> adj_list[N];
long long d[N], parent[N];

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    d[i] = INF;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj_list[u].push_back({v, w});
  }
  bool isNegative = false;
  int last_updated_node = -1;
  for (int i = 1; i <= n; i++)
  {
    for (int node = 1; node <= n; node++)
    {
      for (auto adj_node : adj_list[node])
      {
        int u = node, v = adj_node.first, w = adj_node.second;
        if (d[u] + w < d[v])
        {
          d[v] = d[u] + w;
          parent[v] = u;
          if (i == n)
          {
            isNegative = true;
            last_updated_node = v;
          }
        }
      }
    }
  }

  if (isNegative == true)
  {
    cout << "YES" << endl;
    int selectedNode = last_updated_node;
    for (int i = 1; i <= n - 1; i++)
    {
      selectedNode = parent[selectedNode];
    }

    vector<int> cycle;
    cycle.push_back(selectedNode);
    while (true)
    {
      selectedNode = parent[selectedNode];
      cycle.push_back(selectedNode);
      if (selectedNode == cycle.front())
        break;
    }
    reverse(cycle.begin(), cycle.end());
    for (int node : cycle)
      cout << node << " ";
    cout << endl;
  }
  else
    cout << "NO" << endl;

  return 0;
}