#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findCenter(vector<vector<int>> &edges)
  {
    int n = edges.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      mp[edges[i][0]]++;
      mp[edges[i][1]]++;
    }

    return max_element(
               mp.begin(), mp.end(), [](const pair<int, int> &a, const pair<int, int> &b)
               { return a.second < b.second; })
        ->first;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
  cout << st.findCenter(edges) << endl;
  return 0;
}