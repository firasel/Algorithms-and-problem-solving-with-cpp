#include <bits/stdc++.h>
using namespace std;

bool DFS(unordered_map<int, vector<int>> &graph, vector<int> &parent, int s, int &d, int p)
{
  parent[s] = p;
  if (s == d)
    return true;
  for (auto v : graph[s])
  {
    if (parent[v] == -1)
    {
      if (DFS(graph, parent, v, d, s))
        return true;
    }
  }
  return false;
}

int main()
{
  int n, m, u, v, s, d;
  cin >> n >> m;

  unordered_map<int, vector<int>> graph;
  vector<int> parent(n, -1);

  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  cout << "Source & Destination: ";
  cin >> s >> d;

  if (DFS(graph, parent, s, d, -2))
  {
    vector<int> path;
    int temp = d;
    while (temp != -2)
    {
      path.push_back(temp);
      temp = parent[temp];
    }
    reverse(path.begin(), path.end());
    temp = path.size();
    cout << "Path: ";
    for (int i = 0; i < temp; i++)
    {
      cout << path[i] << (i != temp - 1 ? " --> " : "");
    }
    cout << endl;
  }
  else
    cout << "Source/Destination not found!" << endl;

  return 0;
}

/*
0---1---2---5---6
    |   \
    |   \
    3---4---7

8 8
0 1
1 2
1 3
2 4
2 5
3 4
4 7
5 6

*/