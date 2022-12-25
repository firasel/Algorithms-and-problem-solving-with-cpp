#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int firstMissingPositive(vector<int> &nums)
  {
    int ans = 1, n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
      if (nums[i] < ans)
        continue;
      if (nums[i] > ans)
        break;
      ans++;
    }
    return ans;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {1, 2, 0};
  cout << st.firstMissingPositive(nums) << endl;
  return 0;
}