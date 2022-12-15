#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    arr[u].push_back(v);
    arr[v].push_back(u);
  }

  for (int i = 0; i < n; i++)
  {
    cout << i << " -> ";
    for (auto num : arr[i])
    {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}