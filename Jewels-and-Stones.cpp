#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numJewelsInStones(string jewels, string stones)
  {
    int ans = 0;
    map<char, int> stone;
    for (char ch : stones)
      stone[ch]++;

    for (auto ch : jewels)
      if (stone.find(ch) != stone.end())
      {
        ans += stone[ch];
        stone[ch] = 0;
      }

    return ans;
  }
};

int main()
{
  Solution st;
  cout << st.numJewelsInStones("aA", "aAAbbbb") << endl;

  return 0;
}