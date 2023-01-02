#include <bits/stdc++.h>
using namespace std;

bool BFS(unordered_map<int, vector<int>> &graph, vector<int> &indegree, int &n)
{
  int visitedNode = 0;
  queue<int> q;
  for (int i = 0; i < n; i++)
  {
    if (indegree[i] == 0)
      q.push(i);
  }

  while (!q.empty())
  {
    visitedNode++;
    int u = q.front();
    q.pop();
    for (int v : graph[u])
    {
      indegree[v]--;
      if (indegree[v] == 0)
      {
        q.push(v);
      }
    }
  }

  return visitedNode != n;
}

int main()
{
  int n, m, u, v;
  // Graph input
  cin >> n >> m;
  unordered_map<int, vector<int>> graph;
  vector<int> indegree(n, 0);
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    graph[u].push_back(v);
    indegree[v]++;
  }

  bool isCycle = BFS(graph, indegree, n);

  if (isCycle)
    cout << "The graph contains a cycle" << endl;
  else
    cout << "The graph has no cycles" << endl;

  return 0;
}

/*
Test Case:

7 7
0 1
0 6
1 2
1 5
2 0
2 3
3 4

5 5
0 1
0 3
1 2
1 4
3 2

*/