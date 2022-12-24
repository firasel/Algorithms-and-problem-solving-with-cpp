#include <bits/stdc++.h>
using namespace std;

int remove_edge(map<int, vector<int>> &graph)
{
  int count = 0;
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
      {
        auto nodeAdd = find(graph[el.first].begin(), graph[el.first].end(), chNode);
        if (nodeAdd != graph[el.first].end())
          graph[el.first].erase(nodeAdd);
        count++;
      }
    }
  }
  return count;
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

  cout << "Total edge removed is: " << remove_edge(graph) << endl;

  return 0;
}

/*

5 10
1 2
2 1
1 3
3 1
2 4
4 2
3 4
4 3
4 5
5 4

5 7
1 2
1 3
2 4
4 2
4 3
4 5
5 4

*/