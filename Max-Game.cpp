// #include <bits/stdc++.h>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
  int q;
  cin >> q;
  priority_queue<int> pq;
  while (q--)
  {
    int op;
    cin >> op;
    if (op == 1)
    {
      int num;
      cin >> num;
      pq.push(num);
    }
    else
    {
      cout << pq.top() << endl;
      pq.pop();
    }
  }

  return 0;
}