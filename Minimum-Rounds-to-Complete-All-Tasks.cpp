#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumRounds(vector<int> &tasks)
  {
    int n = tasks.size(), temp, cnt = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
      mp[tasks[i]]++;
    for (auto el : mp)
    {
      if (el.second < 2)
        return -1;
      else if (el.second % 3 == 0)
        cnt += (el.second / 3);
      else
        cnt += (el.second / 3) + 1;
    }
    return cnt;
  }
};

int main()
{
  Solution st;
  vector<int> tasks = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4};
  cout << st.minimumRounds(tasks) << endl;

  return 0;
}