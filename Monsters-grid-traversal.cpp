#include <bits/stdc++.h>
using namespace std;

int row[4] = {0, 0, 1, -1};
int col[4] = {1, -1, 0, 0};

int DFS(vector<vector<char>> &grid, pair<int, int> s, int &n, int &m, int p)
{
  grid[s.first][s.second] = '#';
  if (s.first == 0 || s.first == n - 1 || s.second == 0 || s.second == m - 1)
    return p;
  for (int i = 0; i < 4; i++)
  {
    int nr = s.first + row[i], nc = s.second + col[i];
    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.')
    {
      int path = DFS(grid, {nr, nc}, n, m, p + 1);
      if (path > -1)
        return path;
    }
  }
  return -1;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  pair<int, int> source;
  for (int i = 0; i < n; i++)
  {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++)
    {
      grid[i][j] = str[j];
      if (str[j] == 'A')
        source = {i, j};
    }
  }
  int pathLen = DFS(grid, source, n, m, 0);
  if (pathLen != -1)
    cout << "YES" << endl
         << pathLen << endl;
  else
    cout << "NO" << endl;

  return 0;
}

/*

5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

5 8
########
....A..#
#.#.M#.#
#M#..#.#
#.######

5 8
########
#M..A..#
#.#.M#.#
#M#..#.#
#.######

*/