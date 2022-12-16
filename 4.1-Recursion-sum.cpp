#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> nums)
{
  if (nums.empty())
    return 0;
  int temp = nums.front();
  nums.erase(nums.begin());
  return temp + sum(nums);
}

int main()
{
  vector<int> nums = {3, 2, 5, 2, 7, 1};
  cout << sum(nums) << endl;
  return 0;
}