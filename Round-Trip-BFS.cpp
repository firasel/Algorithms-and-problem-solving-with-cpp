#include <bits/stdc++.h>
using namespace std;

bool BFS(unordered_map<int, vector<int>> &graph, vector<bool> &visited, vector<int> &parent, int s, int p, int &startNode, int &endNode)
{
  visited[s] = true;
  parent[s] = p;
  queue<int> q;
  q.push(s);
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (auto v : graph[u])
    {
      if (!visited[v])
      {
        visited[v] = true;
        parent[v] = u;
        q.push(v);
      }
      else if (parent[u] != v)
      {
        startNode = v;
        endNode = u;
        cout << "Cycle: ";
        cout << v << " ";
        int curr = u;
        while (curr != v && curr != 0)
        {
          cout << curr << " ";
          curr = parent[curr];
        }
        cout << v << endl;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  int n, m;
  cin >> n >> m;
  unordered_map<int, vector<int>> graph;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<bool> visited(n + 1, false);
  vector<int> parent(n + 1, 0);

  bool isCycle = false;
  int startNode, endNode;

  for (int i = 1; i <= n; i++)
  {
    if (!visited[i] && BFS(graph, visited, parent, i, -1, startNode, endNode))
    {
      isCycle = true;
      break;
    }
  }
  cout << "F: " << isCycle << " " << startNode << " " << endNode << endl;
  if (isCycle)
  {
    int currNode = endNode;
    vector<int> ans;
    for (auto num : parent)
      cout << num << " ";
    cout << endl;
    ans.push_back(endNode);
    while (currNode != startNode && currNode > 0)
    {
      cout << currNode << " ";
      ans.push_back(parent[currNode]);
      currNode = parent[currNode];
      cout << currNode << endl;
    }
    ans.push_back(endNode);
    cout << ans.size() << endl;
    for (auto c : ans)
      cout << c << " ";
    cout << endl;
  }
  else
    cout << "IMPOSSIBLE" << endl;

  return 0;
}

/*
1 --- 2 --- 5 --- 6
      |     |
      |     |
      3--- 4

6 6
1 2
2 3
2 5
3 4
4 5
5 6

1 --- 2 --- 5 --- 6
      |     |
      |     |
      3     4

6 5
1 2
2 3
2 5
4 5
5 6


*/