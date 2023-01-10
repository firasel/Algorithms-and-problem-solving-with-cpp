#include <bits/stdc++.h>
using namespace std;

void printAns(vector<int> &ans)
{
  cout << "{ ";
  for (auto num : ans)
    cout << num << " ";
  cout << "}" << endl;
}

void combination(int s, int n, vector<int> &ans)
{
  if (n == 0)
  {
    printAns(ans);
    return;
  }
  for (int i = n; i >= s; i--)
  {
    ans.push_back(i);
    combination(i, n - i, ans);
    ans.pop_back();
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> ans;
  combination(1, n, ans);
  return 0;
}
