#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

  ListNode(int nodeVal)
  {
    this->val = nodeVal;
    next = NULL;
  }
};

class Solution
{
public:
  ListNode *mergeNodes(ListNode *head)
  {
    ListNode *prev = head, *temp = head->next;
    while (temp)
    {
      if (temp->val != 0)
        prev->val += temp->val;
      else
      {
        if (temp->next)
        {
          prev->next = temp;
          prev = temp;
        }
        else
          prev->next = NULL;
      }
      temp = temp->next;
    }
    return head;
  }
};

void printList(ListNode *head)
{
  cout << head->val << " ";
  if (head->next)
    printList(head->next);
}

int main()
{
  Solution st;
  ListNode *head = new ListNode(0);
  ListNode *n1 = new ListNode(3);
  ListNode *n2 = new ListNode(1);
  ListNode *n3 = new ListNode(0);
  ListNode *n4 = new ListNode(4);
  ListNode *n5 = new ListNode(5);
  ListNode *n6 = new ListNode(2);
  ListNode *n7 = new ListNode(0);

  head->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;
  n6->next = n7;

  ListNode *res = st.mergeNodes(head);
  printList(res);
  cout << endl;

  return 0;
}