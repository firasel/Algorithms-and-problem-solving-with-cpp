#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    int n = grid.size(), m = grid[0].size(), fresh = 0, cnt = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 2)
          q.push({i, j});
        else if (grid[i][j] == 1)
          fresh++;
      }
    }

    if (fresh == 0)
      return 0;

    q.push({-1, -1});
    int row[4] = {1, -1, 0, 0}, col[4] = {0, 0, 1, -1};

    while (!q.empty())
    {
      auto p = q.front();
      q.pop();
      if (p.first == -1 && p.second == -1)
      {
        cnt++;
        if (!q.empty())
          q.push({-1, -1});
      }
      else
      {
        for (int i = 0; i < 4; i++)
        {
          int nr = p.first + row[i], nc = p.second + col[i];
          if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1)
          {
            grid[nr][nc] = 2;
            q.push({nr, nc});
            fresh--;
          }
        }
      }
    }
    if (fresh == 0)
      return cnt - 1;
    return -1;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  cout << st.orangesRotting(grid) << endl;
  return 0;
}