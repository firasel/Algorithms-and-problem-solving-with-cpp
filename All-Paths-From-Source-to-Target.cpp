#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void DFS(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> path, int &n, int s)
  {
    path.push_back(s);
    if (s == n)
      ans.push_back(path);
    for (auto v : graph[s])
      DFS(graph, ans, path, n, v);
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
  {
    int n = graph.size() - 1;
    vector<vector<int>> ans;
    DFS(graph, ans, {}, n, 0);
    return ans;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {}, {4}, {}};

  vector<vector<int>> ans = st.allPathsSourceTarget(graph);

  for (auto nums : ans)
  {
    for (auto num : nums)
      cout << num << " ";
    cout << endl;
  }

  return 0;
}