#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
  {
    int n = grid.size(), m = grid[0].size(), M = m, N = n, step = 0, next, prev, block = min(m, n) / 2;
    n--;
    m--;

    while (n > 0 && m > 0)
    {
      int cnt = k % (2 * (M + N - 4 * step) - 4);
      while (cnt--)
      {
        prev = grid[step][step];
        for (int i = step; i < n; i++)
        {
          next = grid[i + 1][step];
          grid[i + 1][step] = prev;
          prev = next;
        }

        for (int i = step; i < m; i++)
        {
          next = grid[n][i + 1];
          grid[n][i + 1] = prev;
          prev = next;
        }

        for (int i = n; i > step; i--)
        {
          next = grid[i - 1][m];
          grid[i - 1][m] = prev;
          prev = next;
        }

        for (int i = m; i > step; i--)
        {
          next = grid[step][i - 1];
          grid[step][i - 1] = prev;
          prev = next;
        }
      }
      m--;
      n--;
      step++;
      if (step >= m || step >= n)
        break;
    }

    return grid;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> grid = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  vector<vector<int>> ans = st.rotateGrid(grid, 2);

  for (auto nums : ans)
  {
    for (auto num : nums)
      cout << num << " ";
    cout << endl;
  }

  return 0;
}
