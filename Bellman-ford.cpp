#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, u, v, w;
  cin >> n >> m;
  unordered_map<int, vector<pair<int, int>>> graph;
  vector<int> d(n + 1, INT32_MAX);
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  int src = 1, flag = 0;
  d[src] = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      for (auto v : graph[j])
      {
        if (d[j] + v.second < d[v.first])
        {
          d[v.first] = d[j] + v.second;
          if (i == n)
            flag = 1;
        }
      }
    }
  }
  if (flag)
    cout << "Graph has a cycle" << endl;
  else
  {
    for (int i = 1; i <= n; i++)
    {
      cout << d[i] << " ";
    }
  }
  cout << endl;

  return 0;
}

/*
  1   -2   3
1---2---3---4


4 3
1 2 1
2 3 -2
3 4 3
*/