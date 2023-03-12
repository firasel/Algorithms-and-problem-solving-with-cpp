#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool checkVowel(char &ch)
  {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
      return true;
    return false;
  }

  int vowelStrings(vector<string> &words, int left, int right)
  {
    int ans = 0;
    for (int i = left; i <= right; i++)
      if (checkVowel(words[i].front()) && checkVowel(words[i].back()))
        ans++;

    return ans;
  }
};

int main()
{
  Solution st;

  vector<string> words = {"are", "amy", "u"};

  cout << st.vowelStrings(words, 0, 2) << endl;

  return 0;
}