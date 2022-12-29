#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    int n, flag = 0;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
      cin >> strs[i];
    sort(strs.begin(), strs.end());
    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (strs[j].substr(0, strs[i].length()) == strs[i])
        {
          flag = 1;
          break;
        }
      }
      if (flag)
        break;
    }
    if (flag)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}