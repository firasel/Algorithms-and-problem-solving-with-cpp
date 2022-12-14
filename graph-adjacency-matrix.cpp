#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 4;
  vector<vector<int>> matrix(n, vector<int>(n, 0));

  matrix[0][1] = 1;
  matrix[1][0] = 1;

  matrix[1][2] = 1;
  matrix[2][1] = 1;

  matrix[2][3] = 1;
  matrix[3][2] = 1;

  matrix[3][1] = 1;
  matrix[1][3] = 1;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}