#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int reverse(int x)
  {
    long long res = 0;
    while (x != 0)
    {
      res = (res * 10) + (x % 10);
      x /= 10;
    }
    if (res > INT_MAX)
      return 0;
    else if (res < INT_MIN)
      return 0;
    return res;
  }
};

int main()
{
  Solution st;
  cout << st.reverse(-231) << endl;

  return 0;
}