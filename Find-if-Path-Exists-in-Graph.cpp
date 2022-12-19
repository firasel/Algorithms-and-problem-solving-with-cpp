#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
  {
    unordered_map<int, vector<int>> list;
    int size = edges.size();
    for (int i = 0; i < size; i++)
    {
      list[edges[i][0]].push_back(edges[i][1]);
      list[edges[i][1]].push_back(edges[i][0]);
    }

    queue<int> q;
    q.push(source);
    vector<int> visited(n, 0);

    while (!q.empty())
    {
      int num = q.front();
      visited[num] = 1;
      if (num == destination)
        return true;
      q.pop();
      for (auto ch : list[num])
        if (!visited[ch])
          q.push(ch);
    }
    return false;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
  cout << st.validPath(3, edges, 0, 2) << endl;
  return 0;
}