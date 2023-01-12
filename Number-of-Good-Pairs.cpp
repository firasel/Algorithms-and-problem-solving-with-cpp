#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numIdenticalPairs(vector<int> &nums)
  {
    int ans = 0;
    unordered_map<int, int> mp;
    for (int num : nums)
      mp[num]++;
    for (auto el : mp)
      ans += ((el.second - 1) * (el.second)) / 2;
    return ans;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {1, 2, 3, 1, 1, 3};
  cout << st.numIdenticalPairs(nums) << endl;
  return 0;
}