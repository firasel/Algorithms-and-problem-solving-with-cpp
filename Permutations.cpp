#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void DFS(vector<int> &nums, int pos, vector<int> &temp, vector<vector<int>> &res)
  {
    if (pos == nums.size())
    {
      res.push_back(temp);
      return;
    }
    for (int i = 0; i <= temp.size(); i++)
    {
      temp.insert(temp.begin() + i, nums[pos]);
      DFS(nums, pos + 1, temp, res);
      temp.erase(temp.begin() + i);
    }
  }

  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> res;
    vector<int> temp;
    DFS(nums, 0, temp, res);
    return res;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans = st.permute(nums);
  for (auto allNums : ans)
  {
    for (auto num : allNums)
      cout << num << " ";
    cout << endl;
  }

  return 0;
}