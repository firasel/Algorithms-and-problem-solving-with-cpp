#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 4;
  vector<int> adj_list[n];

  adj_list[0] = {1};
  adj_list[1] = {0, 2, 3};
  adj_list[2] = {1, 3};
  adj_list[3] = {1, 2};

  for (int i = 0; i < n; i++)
  {
    for (auto num : adj_list[i])
    {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}