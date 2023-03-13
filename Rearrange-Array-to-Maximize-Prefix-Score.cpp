#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxScore(vector<int> &nums)
  {
    sort(nums.rbegin(), nums.rend());
    int len = nums.size(), ans = nums[0] > 0 ? 1 : 0;
    long long temp = nums[0];

    for (int i = 1; i < len; i++)
    {
      temp += nums[i];
      if (temp > 0)
        ans++;
    }
    return ans;
  }
};

int main()
{
  Solution st;

  vector<int> nums = {2, -1, 0, 1, -3, 3, -3};

  cout << st.maxScore(nums) << endl;

  return 0;
}