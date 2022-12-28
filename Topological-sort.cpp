#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> topoSort(int V, vector<vector<int>> &edges)
  {
    vector<int> ans;
    queue<int> q;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < edges.size(); i++)
    {
      graph[edges[i][0]].push_back(edges
                                       [i][1]);
    }

    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
      for (auto x : graph[i])
      {
        indegree[x]++;
      }
    }

    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
        q.push(i);
    }

    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      ans.push_back(u);
      for (auto v : graph[u])
      {
        indegree[v]--;
        if (indegree[v] == 0)
          q.push(v);
      }
    }
    return ans;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

  vector<int> res = st.topoSort(6, edges);
  for (int node : res)
    cout << node << " ";
  cout << endl;

  return 0;
}