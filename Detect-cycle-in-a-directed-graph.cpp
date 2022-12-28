#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool cycleDetect(int s, vector<bool> &visited, vector<bool> &currVisited, unordered_map<int, vector<int>> &graph)
  {
    visited[s] = true;
    currVisited[s] = true;
    for (auto v : graph[s])
    {
      if (!visited[v])
      {
        if (cycleDetect(v, visited, currVisited, graph))
          return true;
      }
      else if (visited[v] && currVisited[v])
        return true;
    }
    currVisited[s] = false;
    return false;
  }

  bool isCyclic(int V, vector<vector<int>> &edges)
  {
    // Create the graph
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < edges.size(); i++)
    {
      graph[edges[i][0]].push_back(edges
                                       [i][1]);
    }

    vector<bool> visited(V, false), currVisited(V, false);
    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        if (cycleDetect(i, visited, currVisited, graph))
          return true;
      }
    }
    return false;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 4}, {4, 3}, {5, 0}, {5, 6}, {6, 7}, {7, 5}};
  cout << st.isCyclic(8, edges) << endl;
  return 0;
}