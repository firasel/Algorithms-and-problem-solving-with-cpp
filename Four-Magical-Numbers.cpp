#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    int max_product = numeric_limits<int>::min();
    int min_product = numeric_limits<int>::max();
    int max_sum = numeric_limits<int>::min();
    int min_sum = numeric_limits<int>::max();

    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      for (int j = 0; j < n; j++)
      {
        int b;
        cin >> b;
        int product = a * b;
        int sum = a + b;
        max_product = max(max_product, product);
        min_product = min(min_product, product);
        max_sum = max(max_sum, sum);
        min_sum = min(min_sum, sum);
      }
    }

    cout << max_product << " " << min_product << " " << max_sum << " " << min_sum << endl;
  }

  return 0;
}
