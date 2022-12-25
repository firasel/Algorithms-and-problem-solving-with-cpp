#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
  {
    int n = nums.size(), m = queries.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < m; i++)
    {
      int ans = 0, cnt = 0;
      for (auto num : nums)
      {
        if (ans + num > queries[i])
          break;
        ans += num;
        cnt++;
      }
      queries[i] = cnt;
    }

    return queries;
  }
};

int main()
{
  Solution st;

  vector<int> nums = {4, 5, 2, 1};
  vector<int> queries = {3, 10, 21};
  vector<int> res = st.answerQueries(nums, queries);

  for (auto num : res)
    cout << num << " ";
  cout << endl;

  return 0;
}