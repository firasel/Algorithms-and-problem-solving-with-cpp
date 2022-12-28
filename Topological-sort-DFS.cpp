#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void DFS(int s, stack<int> &st, vector<bool> &visited, unordered_map<int, vector<int>> &graph)
  {
    visited[s] = true;
    for (auto v : graph[s])
    {
      if (!visited[v])
        DFS(v, st, visited, graph);
    }
    st.push(s);
  }

  vector<int> topoSort(int V, vector<vector<int>> &edges)
  {
    // Create the graph
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < edges.size(); i++)
    {
      graph[edges[i][0]].push_back(edges
                                       [i][1]);
    }

    vector<int> ans;
    stack<int> st;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
        DFS(i, st, visited, graph);
    }

    while (!st.empty())
    {
      ans.push_back(st.top());
      st.pop();
    }

    return ans;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> edges = {{0, 1}, {1, 3}, {3, 4}, {2, 3}, {2, 4}};

  vector<int> res = st.topoSort(5, edges);
  for (int node : res)
    cout << node << " ";
  cout << endl;

  return 0;
}