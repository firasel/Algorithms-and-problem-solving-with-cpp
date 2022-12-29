#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool DFS(int s, vector<bool> &visited, vector<bool> &dfsVisited, vector<vector<int>> &graph, vector<bool> &present_cycle)
  {
    visited[s] = true;
    dfsVisited[s] = true;
    for (auto v : graph[s])
    {
      if (!visited[v])
      {
        if (DFS(v, visited, dfsVisited, graph, present_cycle))
          return present_cycle[s] = true;
      }
      else if (visited[v] && dfsVisited[v])
        return present_cycle[s] = true;
    }
    dfsVisited[s] = false;
    return false;
  }

  vector<int> eventualSafeNodes(vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<int> ans;
    vector<bool> visited(n, false), dfsVisited(n, false), present_cycle(n, false);

    for (int i = 0; i < n; i++)
      if (!visited[i])
        DFS(i, visited, dfsVisited, graph, present_cycle);

    for (int i = 0; i < n; i++)
      if (!present_cycle[i])
        ans.push_back(i);

    return ans;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

  vector<int> ans = st.eventualSafeNodes(graph);

  for (auto num : ans)
    cout << num << " ";
  cout << endl;

  return 0;
}