#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void DFS(vector<vector<int>> &grid, int r, int c, int n, int m, int &count)
  {
    grid[r][c] = 0;
    count++;
    if (r - 1 >= 0 && grid[r - 1][c] == 1)
      DFS(grid, r - 1, c, n, m, count);
    if (r + 1 < n && grid[r + 1][c] == 1)
      DFS(grid, r + 1, c, n, m, count);
    if (c - 1 >= 0 && grid[r][c - 1] == 1)
      DFS(grid, r, c - 1, n, m, count);
    if (c + 1 < m && grid[r][c + 1] == 1)
      DFS(grid, r, c + 1, n, m, count);
  }

  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    int n = grid.size(), m = grid[0].size(), count, ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1)
        {
          count = 0;
          DFS(grid, i, j, n, m, count);
          if (count > ans)
            ans = count;
        }
      }
    }
    return ans;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  int ans = st.maxAreaOfIsland(grid);
  cout << ans << endl;

  return 0;
}