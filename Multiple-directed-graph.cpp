#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<int, vector<int>> mp;

  for (int i = 2; i <= 101; i++)
  {
    mp[i];
    for (int j = i; j <= 101; j++)
      if (j % i == 0)
        mp[i].push_back(j);
  }

  for (auto el : mp)
  {
    cout << el.first << " -> ";
    for (auto edge : el.second)
      cout << edge << " ";
    cout << endl;
  }

  return 0;
}
