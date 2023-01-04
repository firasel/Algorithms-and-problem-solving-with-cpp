#include <bits/stdc++.h>
using namespace std;

bool BFS(vector<vector<int>> &graph, vector<int> &parent, int s, int &d)
{
  int graphLen = graph.size();
  if (s < 0 || s >= graphLen || d < 0 || d >= graphLen)
    return false;
  queue<int> q;
  q.push(s);
  parent[s] = -2;

  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    if (u == d)
      return true;
    for (int i = 0; i < graphLen; i++)
    {
      if (graph[u][i] == 1)
      {
        if (parent[i] == -1)
        {
          parent[i] = u;
          q.push(i);
        }
      }
    }
  }

  return false;
}

int main()
{
  int n, m, u, v, s, d;
  cin >> n >> m;

  vector<vector<int>> graph(n, vector<int>(n, 0));
  vector<int> parent(n, -1);

  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    graph[u][v] = 1;
    graph[v][u] = 1;
  }
  cout << "Source & Destination: ";
  cin >> s >> d;

  if (BFS(graph, parent, s, d))
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