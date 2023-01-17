#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<int> adj[N];
int visited[N];
int d[N];
queue<int> q;

void bfs()
{
  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    for (int u : adj[node])
    {
      if (visited[u] == 0)
      {
        visited[u] = 1;
        d[u] = d[node] + 1;
        q.push(u);
      }
    }
  }
}

int main()
{
  int n, m, t = 0, k, lastNode = INT_MAX;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cin >> k;
  for (int i = 0; i < k; i++)
  {
    int a;
    cin >> a;
    q.push(a);
    d[a] = 0;
    visited[a] = 1;
  }
  bfs();

  for (int i = 1; i <= n; i++)
  {
    if (t < d[i])
    {
      t = d[i];
      lastNode = i;
    }
    if (t == d[i])
      lastNode = min(lastNode, i);
  }
  cout << t << endl
       << lastNode << endl;

  return 0;
}