#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
vector<int> list[N];

int main()
{
  int n, k, o, u, v;
  cin >> n >> k;
  while (k--)
  {
    cin >> o >> u;
    if (o == 1)
    {
      cin >> v;
      list[u].push_back(v);
      list[v].push_back(u);
    }
    else
    {
      for (auto v : list[u])
        cout << v << " ";
      cout << endl;
    }
  }
  return 0;
}