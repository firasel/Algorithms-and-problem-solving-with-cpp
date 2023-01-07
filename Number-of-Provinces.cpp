#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void DFS(vector<vector<int>> &isConnected, vector<bool> &visited, int &n, int s)
  {
    visited[s] = true;
    for (int i = 0; i < n; i++)
      if (isConnected[s][i] == 1 && !visited[i])
        DFS(isConnected, visited, n, i);
  }

  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int n = isConnected.size(), cnt = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
      if (!visited[i])
        cnt++, DFS(isConnected, visited, n, i);

    return cnt;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

  cout << st.findCircleNum(isConnected) << endl;

  return 0;
}