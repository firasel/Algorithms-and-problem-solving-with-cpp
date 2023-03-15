#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int splitNum(int num)
  {
    bool flag = true;
    string numStr = to_string(num), num1 = "", num2 = "";
    sort(numStr.begin(), numStr.end());
    for (auto chNum : numStr)
    {
      if (flag)
      {
        num1 += chNum;
        flag = false;
      }
      else
      {
        num2 += chNum;
        flag = true;
      }
    }

    return stoi(num1) + stoi(num2);
  }
};

int main()
{
  Solution st;
  cout << st.splitNum(4325) << endl;
  cout << st.splitNum(231) << endl;
  cout << st.splitNum(687) << endl;
  return 0;
}