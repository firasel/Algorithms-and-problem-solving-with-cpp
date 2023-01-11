#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--)
    {
      if (digits[i] == 9)
        digits[i] = 0;
      else
      {
        digits[i] += 1;
        return digits;
      }
    }
    digits.push_back(0);
    digits[0] = 1;
    return digits;
  }
};

int main()
{
  Solution st;
  vector<int> digits = {1, 2, 3};
  vector<int> ans = st.plusOne(digits);
  for (auto num : ans)
    cout << num << " ";
  cout << endl;
  return 0;
}