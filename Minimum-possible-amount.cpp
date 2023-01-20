#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
const long long INF = 1e18;
long long adj[105][105];
long long cost[N];

int main()
{
  long long n, m;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> cost[i];
  cin >> m;

  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u][v] = cost[u];
    adj[v][u] = cost[v];
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (adj[i][j] == 0)
        adj[i][j] = INF;

  for (int k = 1; k <= n; k++)
    for (int u = 1; u <= n; u++)
      for (int v = 1; v <= n; v++)
        adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v]);

  if (adj[1][n] == INF)
    cout << -1 << endl;
  else
    cout << adj[1][n] << endl;
  return 0;
}