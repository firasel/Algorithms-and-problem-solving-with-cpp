#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<vector<int>> &adj_list, vector<int> &visited, int s, queue<int> &q)
{
  visited[s] = 1;
  q.push(s);
  for (int v : adj_list[s])
  {
    if (!visited[v] && DFS(adj_list, visited, v, q))
      return true;
    else if (visited[v] == 1)
    {
      q.push(v);
      return true;
    }
  }
  visited[s] = 2;
  q.pop();
  return false;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj_list(n + 1);
  vector<int> visited(n + 1, 0);
  queue<int> q;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
  }

  bool is_cycle = false;
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i] && DFS(adj_list, visited, i, q))
    {
      is_cycle = true;
      break;
    }
  }

  if (is_cycle)
  {
    while (q.front() != q.back())
      q.pop();

    cout << q.size() << endl;
    while (!q.empty())
    {
      cout << q.front() << " ";
      q.pop();
    }
    cout << endl;
  }
  else
    cout << "IMPOSSIBLE" << endl;

  return 0;
}

/*

4 4
1 2
2 3
3 4
4 2

4 3
2 1
2 3
3 4

4 5
1 3
2 1
2 4
3 2
3 4

*/