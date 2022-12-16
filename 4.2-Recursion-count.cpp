#include <bits/stdc++.h>
using namespace std;

int count(vector<int> nums)
{
  if (nums.empty())
    return 0;
  nums.pop_back();
  return 1 + count(nums);
}

int main()
{
  vector<int> nums = {3, 2, 5, 2, 7, 1};
  cout << count(nums) << endl;
  return 0;
}