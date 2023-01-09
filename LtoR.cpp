#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1000000;

int n;
int nums[N];
int tree[N * 7];

void build(int node, int start, int end)
{
  if (start == end)
  {
    tree[node] = nums[start];
    return;
  }
  int mid = (start + end) / 2;
  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);
  tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right)
{
  if (right < start || end < left)
  {
    return 1;
  }
  if (left <= start && end <= right)
  {
    return tree[node];
  }
  int mid = (start + end) / 2;
  int nLeft = query(node * 2, start, mid, left, right);
  int nRight = query(node * 2 + 1, mid + 1, end, left, right);
  return nLeft * nRight;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  build(1, 0, n - 1);

  int q;
  cin >> q;

  while (q--)
  {
    int left, right;
    cin >> left >> right;
    cout << query(1, 0, n - 1, left - 1, right - 1) << "\n";
  }

  return 0;
}
