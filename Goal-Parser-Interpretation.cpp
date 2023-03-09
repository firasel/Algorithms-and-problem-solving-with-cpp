#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string interpret(string command)
  {
    int len = command.length();
    string ans = "";
    for (int i = 0; i < len; i++)
    {
      if (command[i] != '(' && command[i] != ')')
        ans += command[i];
      else if (command[i] == '(' && command[i + 1] == ')')
        ans += 'o';
    }
    return ans;
  }
};

int main()
{
  Solution st;
  cout << st.interpret("G()(al)") << endl;
  return 0;
}