#include <bits/stdc++.h>
using namespace std;

bool check_bi_directional(map<int, vector<int>> &graph)
{
  for (auto el : graph)
  {
    for (auto chNode : el.second)
    {
      bool flag = true;
      for (auto node : graph[chNode])
      {
        if (node == el.first)
        {
          flag = false;
          break;
        }
      }
      if (flag)
        return false;
    }
  }
  return true;
}

int main()
{
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> graph;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
  }

  if (check_bi_directional(graph))
    cout << "This is bi-directional graph" << endl;
  else
    cout << "This is not a bi-directional graph" << endl;

  return 0;
}