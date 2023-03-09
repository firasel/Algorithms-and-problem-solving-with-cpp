#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string restoreString(string s, vector<int> &indices)
  {
    string ans = s;
    int size = indices.size();
    for (int i = 0; i < size; i++)
      ans[indices[i]] = s[i];
    return ans;
  }
};

int main()
{
  Solution st;
  vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
  cout << st.restoreString("codeleet", indices) << endl;

  return 0;
}