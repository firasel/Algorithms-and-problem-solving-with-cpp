#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> leftRigthDifference(vector<int> &nums)
  {
    int size = nums.size();
    vector<int> left(size, 0), right(size, 0);
    for (int i = 1; i < size; i++)
      left[i] = left[i - 1] + nums[i - 1];
    for (int i = size - 2; i >= 0; i--)
      right[i] = right[i + 1] + nums[i + 1];
    for (int i = 0; i < size; i++)
      nums[i] = abs(left[i] - right[i]);
    return nums;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {10, 4, 8, 3};

  vector<int> ans = st.leftRigthDifference(nums);
  for (auto num : ans)
    cout << num << " ";
  cout << endl;

  return 0;
}