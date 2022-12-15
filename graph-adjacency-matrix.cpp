#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(n, 0));
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    arr[u][v] = 1;
    arr[v][u] = 1;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}