#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
  {
    vector<int> color(n, 0);
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < paths.size(); i++)
    {
      graph[paths[i][0] - 1].push_back(paths[i][1] - 1);
      graph[paths[i][1] - 1].push_back(paths[i][0] - 1);
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
      if (!color[i])
      {
        q.push(i);
        color[i] = 1;
        while (!q.empty())
        {
          int s = q.front();
          q.pop();
          for (auto v : graph[s])
          {
            if (!color[v] || color[v] == color[s])
            {
              color[v] = color[s] + 1;
              q.push(v);
            }
            if (color[v] > 4)
              color[v] = 1;
          }
        }
      }
    }

    return color;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> paths = {{1, 2}, {2, 3}, {3, 1}};
  vector<int> ans = st.gardenNoAdj(3, paths);
  for (auto num : ans)
    cout << num << " ";
  cout << endl;

  return 0;
}