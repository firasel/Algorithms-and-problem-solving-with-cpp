#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool detectCapitalUse(string word)
  {
    int n = word.size(), cnt = 0;
    for (int i = 0; i < n; i++)
      if (word[i] >= 'A' && word[i] <= 'Z')
        cnt++;
    if (cnt > 1 && cnt == n)
      return true;
    else if (cnt == 1 && word[0] >= 'A' && word[0] <= 'Z')
      return true;
    else if (cnt == 0)
      return true;
    return false;
  }
};

int main()
{
  Solution st;
  cout << st.detectCapitalUse("Hello") << endl;
  cout << st.detectCapitalUse("hello") << endl;
  cout << st.detectCapitalUse("HeLlo") << endl;
  cout << st.detectCapitalUse("HELLO") << endl;
  return 0;
}