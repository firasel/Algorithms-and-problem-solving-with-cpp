#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxIceCream(vector<int> &costs, int coins)
  {
    sort(costs.begin(), costs.end());
    if (costs[0] > coins)
      return 0;
    int cnt = 0, n = costs.size();
    for (int i = 0; i < n; i++)
    {
      if (coins - costs[i] >= 0)
        coins -= costs[i], cnt++;
      else
        break;
    }
    return cnt;
  }
};

int main()
{
  Solution st;
  vector<int> costs = {1, 3, 2, 4, 1};
  cout << st.maxIceCream(costs, 7) << endl;

  return 0;
}