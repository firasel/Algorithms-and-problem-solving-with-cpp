#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;
  ListNode(int val)
  {
    this->val = val;
    next = NULL;
  }
};

class Solution
{
public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
  {
    vector<vector<int>> ans(m, vector<int>(n, -1));
    int top = 0, left = 0, right = n, bottom = m;

    while (head)
    {
      int i;
      for (i = left; i < right && head; i++)
      {
        ans[top][i] = head->val;
        head = head->next;
      }
      top++;

      for (i = top; i < bottom && head; i++)
      {
        ans[i][right - 1] = head->val;
        head = head->next;
      }
      right--;

      for (i = right - 1; i >= left && head; i--)
      {
        ans[bottom - 1][i] = head->val;
        head = head->next;
      }
      bottom--;

      for (i = bottom - 1; i >= top && head; i--)
      {
        ans[i][left] = head->val;
        head = head->next;
      }
      left++;
    }

    return ans;
  }
};

int main()
{
  Solution st;
  ListNode *head = new ListNode(3);
  ListNode *n1 = new ListNode(0);
  ListNode *n2 = new ListNode(2);
  ListNode *n3 = new ListNode(6);
  ListNode *n4 = new ListNode(8);
  ListNode *n5 = new ListNode(1);
  ListNode *n6 = new ListNode(7);
  ListNode *n7 = new ListNode(9);
  ListNode *n8 = new ListNode(4);
  ListNode *n9 = new ListNode(2);
  ListNode *n10 = new ListNode(5);
  ListNode *n11 = new ListNode(5);
  ListNode *n12 = new ListNode(0);

  head->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;
  n6->next = n7;
  n7->next = n8;
  n8->next = n9;
  n9->next = n10;
  n10->next = n11;
  n11->next = n12;

  vector<vector<int>> res = st.spiralMatrix(3, 5, head);

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 5; j++)
      cout << res[i][j] << " ";
    cout << endl;
  }

  return 0;
}