#include <iostream>

using namespace std;

int main()
{
  int t, n;
  cin >> t;
  while (t--)
  {
    cin >> n;
    int maxFact = 0, f;
    for (int i = 2; i <= n / 2; i++)
    {
      f = 0;
      while (n % i == 0)
      {
        f++;
        n /= i;
      }
      maxFact += f;
    }

    if (n > 1)
      maxFact++;
    cout << maxFact << endl;
  }

  return 0;
}