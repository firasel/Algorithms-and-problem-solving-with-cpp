#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int passThePillow(int n, int time)
  {
    int i = 1, d = 1;
    while (time--)
    {
      if (i == n)
        d = -1;
      else if (i == 1)
        d = 1;
      i += d;
    }
    return i;
  }
};

int main()
{
  Solution st;

  cout << st.passThePillow(4, 5) << endl;

  return 0;
}