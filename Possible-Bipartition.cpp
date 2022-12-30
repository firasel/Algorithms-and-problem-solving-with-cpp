#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool DFS(unordered_map<int, vector<int>> &graph, vector<bool> &visited, vector<int> &color, int s)
  {
    visited[s] = true;
    for (auto v : graph[s])
    {
      if (!visited[v])
      {
        if (color[s] == 1)
          color[v] = 2;
        else
          color[v] = 1;
        if (!DFS(graph, visited, color, v))
          return false;
      }
      else if (color[s] == color[v])
        return false;
    }
    return true;
  }

  bool possibleBipartition(int n, vector<vector<int>> &dislikes)
  {
    int size = dislikes.size();
    unordered_map<int, vector<int>> graph;
    vector<bool> visited(n + 1, false);
    vector<int> color(n + 1, 0);

    for (int i = 0; i < size; i++)
    {
      graph[dislikes[i][0]].push_back(dislikes[i][1]);
      graph[dislikes[i][1]].push_back(dislikes[i][0]);
    }

    for (int i = 1; i <= n; i++)
    {
      if (!visited[i])
      {
        color[i] = 1;
        if (!DFS(graph, visited, color, i))
          return false;
      }
    }

    return true;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};
  cout << st.possibleBipartition(4, dislikes) << endl;
  return 0;
}