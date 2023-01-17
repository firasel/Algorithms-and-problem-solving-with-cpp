#include <bits/stdc++.h>
using namespace std;
vector<int> adj[102];
int visited[102];

void dfs(int node)
{
  visited[node] = 1;
  for (int v : adj[node])
  {
    if (visited[v] == 0)
    {
      cout << v << " " << node << endl;
      dfs(v);
    }
  }
}

int main()
{
  int n, m, u, v;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  return 0;
}