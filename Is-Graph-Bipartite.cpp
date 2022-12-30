#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool DFS(vector<vector<int>> &graph, vector<int> &colored, int s)
  {
    for (auto v : graph[s])
    {
      if (!colored[v])
      {
        if (colored[s] == 1)
          colored[v] = 2;
        else
          colored[v] = 1;
        if (!DFS(graph, colored, v))
          return false;
      }
      else if (colored[s] == colored[v])
        return false;
    }
    return true;
  }
  bool isBipartite(vector<vector<int>> &graph)
  {
    int size = graph.size();
    vector<int> colored(size, 0);

    for (int i = 0; i < size; i++)
    {
      if (!colored[i])
      {
        colored[i] = 1;
        if (!DFS(graph, colored, i))
          return false;
      }
    }

    return true;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
  cout << st.isBipartite(graph) << endl;
  return 0;
}