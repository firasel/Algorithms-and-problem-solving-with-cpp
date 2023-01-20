#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<char>> keys = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
  vector<string> letterCombinations(string digits)
  {
    vector<string> ans;
    if (digits.size() == 0)
      return ans;
    ans.push_back("");
    for (auto ch : digits)
    {
      vector<string> temp;
      for (auto ch2 : keys[ch - '0'])
        for (auto prev : ans)
          temp.push_back(prev + ch2);
      ans.swap(temp);
    }
    return ans;
  }
};

int main()
{
  Solution st;
  vector<string> ans = st.letterCombinations("23");
  for (auto str : ans)
    cout << str << endl;

  return 0;
}