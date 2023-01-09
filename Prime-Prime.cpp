#include <bits/stdc++.h>
#include <queue>
using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val)
  {
    this->val = val;
    left = NULL;
    right = NULL;
  }
};

void leafNode(TreeNode *root, vector<int> &nodes)
{
  if (!root->left && !root->right)
  {
    nodes.push_back(root->val);
  }
  else
  {
    if (root->left)
      leafNode(root->left, nodes);
    if (root->right)
      leafNode(root->right, nodes);
  }
}

bool isPrime(int n)
{
  if (n <= 1)
    return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;
  return true;
};

int main()
{
  int val;
  cin >> val;
  if (val == -1)
  {
    cout << -1 << endl;
    return 0;
  }

  TreeNode *root = new TreeNode(val);
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    TreeNode *curr = q.front();
    q.pop();

    cin >> val;
    if (val != -1)
    {
      curr->left = new TreeNode(val);
      q.push(curr->left);
    }

    cin >> val;
    if (val != -1)
    {
      curr->right = new TreeNode(val);
      q.push(curr->right);
    }
  }

  vector<int> nodes;

  leafNode(root, nodes);
  sort(nodes.begin(), nodes.end());
  bool flag = true;
  for (auto node : nodes)
  {
    if (isPrime(node))
    {
      cout << node << " ";
      flag = false;
    }
  }
  if (flag)
    cout << -1;

  return 0;
}