#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int row[4] = {0, 0, 1, -1}, col[4] = {1, -1, 0, 0};
  bool DFS(vector<vector<char>> &grid, int &n, int &m, pair<int, int> s, pair<int, int> p, char &currVal)
  {
    grid[s.first][s.second] = 1;
    for (int i = 0; i < 4; i++)
    {
      int nr = s.first + row[i], nc = s.second + col[i];
      if (nr >= 0 && nr < n && nc >= 0 && nc < m)
      {
        if (grid[nr][nc] == currVal)
        {
          if (DFS(grid, n, m, {nr, nc}, s, currVal))
          {
            return true;
          }
        }
        else if (grid[nr][nc] == 1 && !(p.first == nr && p.second == nc))
        {
          return true;
        }
      }
    }
    grid[s.first][s.second] = 2;
    return false;
  }

  bool containsCycle(vector<vector<char>> &grid)
  {
    char temp;
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] != 2)
        {
          temp = grid[i][j];
          if (DFS(grid, n, m, {i, j}, {-1, -1}, temp))
          {
            return true;
          }
        }
      }
    }
    return false;
  }
};

int main()
{
  Solution st;
  vector<vector<char>> grid = {{'a', 'b', 'b'}, {'b', 'z', 'b'}, {'b', 'b', 'a'}};
  cout << st.containsCycle(grid) << endl;
  return 0;
}