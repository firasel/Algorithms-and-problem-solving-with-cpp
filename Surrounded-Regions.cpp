#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int row[4] = {0, 0, 1, -1};
  int col[4] = {1, -1, 0, 0};
  void DFS(vector<vector<char>> &board, int &n, int &m, pair<int, int> s)
  {
    board[s.first][s.second] = 'C';
    for (int i = 0; i < 4; i++)
    {
      int nr = s.first + row[i], nc = s.second + col[i];
      if (nr >= 0 && nr < n && nc >= 0 && nc < m)
      {
        if (board[nr][nc] == 'O')
          DFS(board, n, m, {nr, nc});
      }
    }
  }

  void solve(vector<vector<char>> &board)
  {
    int n = board.size(), m = board[0].size();
    // Boundary traversal
    for (int i = 0; i < n; i++)
    {
      if (board[i][0] == 'O')
        DFS(board, n, m, {i, 0});
      if (board[i][m - 1] == 'O')
        DFS(board, n, m, {i, m - 1});
    }
    for (int i = 0; i < m; i++)
    {
      if (board[0][i] == 'O')
        DFS(board, n, m, {0, i});
      if (board[n - 1][i] == 'O')
        DFS(board, n, m, {n - 1, i});
    }

    // Modify the board
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
        else if (board[i][j] == 'C')
          board[i][j] = 'O';
      }
    }
  }
};

int main()
{
  Solution st;
  vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};

  st.solve(board);

  for (auto row : board)
  {
    for (auto col : row)
      cout << col << " ";
    cout << endl;
  }

  return 0;
}