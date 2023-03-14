#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  TreeNode *left;
  TreeNode *right;
  int val;

  TreeNode(int val)
  {
    this->val = val;
    left = NULL;
    right = NULL;
  }
};

class Solution
{
public:
  long long kthLargestLevelSum(TreeNode *root, int k)
  {
    vector<long long> sums;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    long long sum = 0;
    while (!q.empty())
    {
      TreeNode *temp = q.front();
      q.pop();
      if (temp != NULL)
      {
        sum += temp->val;
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
      }
      else
      {
        if (!q.empty())
          q.push(NULL);
        sums.push_back(sum);
        sum = 0;
      }
    }

    if (sums.size() < k)
      return -1;
    sort(sums.rbegin(), sums.rend());
    return sums[k - 1];
  }
};

int main()
{
  Solution st;

  TreeNode *root = new TreeNode(5);
  TreeNode *n1 = new TreeNode(8);
  TreeNode *n2 = new TreeNode(9);
  TreeNode *n3 = new TreeNode(2);
  TreeNode *n4 = new TreeNode(1);
  TreeNode *n5 = new TreeNode(3);
  TreeNode *n6 = new TreeNode(7);
  TreeNode *n7 = new TreeNode(4);
  TreeNode *n8 = new TreeNode(6);

  root->left = n1;
  root->right = n2;

  n1->left = n3;
  n1->right = n4;

  n2->left = n5;
  n2->right = n6;

  n3->left = n7;
  n3->right = n8;

  cout << st.kthLargestLevelSum(root, 2) << endl;

  return 0;
}