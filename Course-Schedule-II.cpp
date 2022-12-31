#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool DFS(unordered_map<int, vector<int>> &graph, vector<int> &visited, vector<int> &ans, int s)
  {
    visited[s] = 1;
    for (auto v : graph[s])
    {
      if (!visited[v] && DFS(graph, visited, ans, v))
        return true;
      else if (visited[v] == 1)
        return true;
    }
    visited[s] = 2;
    ans.push_back(s);
    return false;
  }

  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<int> ans, visited(numCourses, 0);
    unordered_map<int, vector<int>> graph;
    int n = prerequisites.size();
    for (int i = 0; i < n; i++)
      graph[prerequisites[i][0]].push_back(prerequisites[i][1]);

    for (int i = 0; i < numCourses; i++)
      if (!visited[i] && DFS(graph, visited, ans, i))
        return {};

    return ans;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  vector<int> ans = st.findOrder(4, prerequisites);
  for (auto num : ans)
    cout << num << " ";
  cout << endl;
  return 0;
}