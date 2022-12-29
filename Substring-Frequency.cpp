#include <iostream>
#include <string.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, c = 1;
  cin >> t;
  while (t--)
  {
    int cnt = 0;
    string a, b;
    cin >> a >> b;

    size_t found = a.find(b);
    while (found != string::npos)
    {
      cnt++;
      found = a.find(b, found + 1);
    }
    cout << "Case " << c++ << ": " << cnt << "\n";
  }
  return 0;
}