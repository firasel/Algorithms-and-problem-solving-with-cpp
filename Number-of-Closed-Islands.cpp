#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void BFS(vector<vector<int>> &grid, int r, int c, int n, int m)
  {
    grid[r][c] = 1;
    if (r - 1 >= 0 && grid[r - 1][c] == 0)
      BFS(grid, r - 1, c, n, m);
    if (r + 1 < n && grid[r + 1][c] == 0)
      BFS(grid, r + 1, c, n, m);
    if (c - 1 >= 0 && grid[r][c - 1] == 0)
      BFS(grid, r, c - 1, n, m);
    if (c + 1 < m && grid[r][c + 1] == 0)
      BFS(grid, r, c + 1, n, m);
  }

  int closedIsland(vector<vector<int>> &grid)
  {
    int n = grid.size(), m = grid[0].size(), count = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if ((i * j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 0)
          BFS(grid, i, j, n, m);
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 0)
        {
          count++;
          BFS(grid, i, j, n, m);
        }
      }
    }

    return count;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0}};
  int ans = st.closedIsland(grid);
  cout << ans << endl;

  return 0;
}