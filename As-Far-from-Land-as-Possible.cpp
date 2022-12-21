#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxDistance(vector<vector<int>> &grid)
  {
    int n = grid.size(), m = grid[0].size();
    int ans = 0, dis = 0, w = 0;
    queue<pair<int, int>> q;
    vector<int> row = {1, 0, -1, 0};
    vector<int> col = {0, 1, 0, -1};

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 0)
          w++;
        if (grid[i][j] == 1)
          q.push({i, j});
      }
    }

    if (w == 0 || q.empty())
    {
      return -1;
    }

    while (!q.empty())
    {
      int size = q.size();
      dis++;
      for (int i = 0; i < size; i++)
      {
        auto temp = q.front();
        q.pop();
        for (int j = 0; j < 4; j++)
        {
          int r = row[j] + temp.first, c = col[j] + temp.second;
          if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 0)
          {
            ans = dis;
            grid[r][c] = 1;
            q.push({r, c});
          }
        }
      }
    }

    return ans;
  }
};

int main()
{
  Solution st;

  vector<vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};

  int ans = st.maxDistance(grid);
  cout << ans << endl;

  return 0;
}