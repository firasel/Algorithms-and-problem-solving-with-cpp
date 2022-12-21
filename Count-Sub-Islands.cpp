#include <bits/stdc++.h>
using namespace std;

class Solution
{
  vector<int> row = {-1, 0, 1, 0};
  vector<int> col = {0, 1, 0, -1};

public:
  void isSubIsland(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int r, int c, int &n, int &m, bool &flag)
  {
    grid2[r][c] = 0;
    for (int i = 0; i < 4; i++)
    {
      int nr = r + row[i];
      int nc = c + col[i];
      if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid2[nr][nc])
      {
        if (!grid1[nr][nc])
          flag = false;
        isSubIsland(grid1, grid2, nr, nc, n, m, flag);
      }
    }
  }

  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
  {
    int n = grid1.size(), m = grid1[0].size(), count = 0;
    bool flag;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid2[i][j] && grid1[i][j])
        {
          flag = true;
          isSubIsland(grid1, grid2, i, j, n, m, flag);
          if (flag)
            count++;
        }
      }
    }

    return count;
  }
};

int main()
{
  Solution st;

  vector<vector<int>> grid1 = {{1, 1, 1, 0, 0}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 1, 1}};

  vector<vector<int>> grid2 = {{1, 1, 1, 0, 0}, {0, 0, 1, 1, 1}, {0, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}};

  int ans = st.countSubIslands(grid1, grid2);
  cout << ans << endl;

  return 0;
}