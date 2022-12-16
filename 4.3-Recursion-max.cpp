#include <bits/stdc++.h>
using namespace std;

int maxNum(vector<int> nums)
{
  if (nums.empty())
    return -1;
  int temp = nums.back();
  nums.pop_back();
  int subMax = maxNum(nums);
  return temp > subMax ? temp : subMax;
}

int main()
{
  vector<int> nums = {3, 2, 5, 2, 7, 1};
  cout << maxNum(nums) << endl;
  return 0;
}