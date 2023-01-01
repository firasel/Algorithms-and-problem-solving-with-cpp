#include <bits/stdc++.h>
using namespace std;

void DFS(unordered_map<int, vector<int>> &graph, vector<int> &distance, int s)
{
  for (auto v : graph[s])
  {
    if (distance[v] == -1)
      distance[v] = distance[s] + 1;
    else
      distance[v] = min(distance[v], distance[s] + 1);
    DFS(graph, distance, v);
  }
}

int main()
{
  int n, m, u, v, s;
  // Graph input
  cin >> n >> m;
  unordered_map<int, vector<int>> graph;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    graph[u].push_back(v);
  }
  // Source input
  cout << "Source Node: ";
  cin >> s;

  vector<int> distance(n, -1);
  // DFS call for distance calculation
  distance[s] = 0;
  DFS(graph, distance, s);
  // Print the distance for all nodes;
  for (int i = 0; i < n; i++)
  {
    cout << i << " - " << distance[i] << endl;
  }

  return 0;
}

/*

Test Case:

7 9
0 1
0 2
1 3
1 4
3 6
4 6
2 5
5 4
5 6

0

*/