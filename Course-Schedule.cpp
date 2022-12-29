#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool DFS(int s, vector<bool> &visited, vector<bool> &dfsVisited, unordered_map<int, vector<int>> &graph)
  {
    visited[s] = true;
    dfsVisited[s] = true;
    for (auto v : graph[s])
    {
      if (!visited[v])
      {
        if (DFS(v, visited, dfsVisited, graph))
          return true;
      }
      else if (visited[v] && dfsVisited[v])
        return true;
    }
    dfsVisited[s] = false;
    return false;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<bool> visited(numCourses, false), dfsVisisted(numCourses, false);
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < prerequisites.size(); i++)
    {
      graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }

    for (int i = 0; i < numCourses; i++)
    {
      if (!visited[i])
      {
        if (DFS(i, visited, dfsVisisted, graph))
          return false;
      }
    }

    return true;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};

  cout << st.canFinish(2, prerequisites) << endl;
  return 0;
}