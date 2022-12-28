#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minStoneSum(vector<int> &piles, int k)
  {
    priority_queue<int> pq;
    int n = piles.size(), temp, newNum, ans = 0;
    for (int i = 0; i < n; i++)
    {
      pq.push(piles[i]);
      ans += piles[i];
    }
    while (k--)
    {
      temp = pq.top();
      newNum = ceil((double)temp / 2);
      pq.pop();
      pq.push(newNum);
      ans -= (temp - newNum);
    }

    return ans;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {4, 3, 6, 7};
  cout << st.minStoneSum(nums, 3) << endl;

  return 0;
}