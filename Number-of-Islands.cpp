#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void DFS(vector<vector<char>> &grid, int r, int c, int n, int m)
  {
    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r - 1][c] == '1')
      DFS(grid, r - 1, c, n, m);
    if (r + 1 < n && grid[r + 1][c] == '1')
      DFS(grid, r + 1, c, n, m);
    if (c - 1 >= 0 && grid[r][c - 1] == '1')
      DFS(grid, r, c - 1, n, m);
    if (c + 1 < m && grid[r][c + 1] == '1')
      DFS(grid, r, c + 1, n, m);
  }

  int numIslands(vector<vector<char>> &grid)
  {
    int n = grid.size(), m = grid[0].size(), count = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == '1')
        {
          count++;
          DFS(grid, i, j, n, m);
        }
      }
    }
    return count;
  }
};

int main()
{
  Solution st;
  vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '1'}};
  int ans = st.numIslands(grid);
  cout << ans << endl;

  return 0;
}