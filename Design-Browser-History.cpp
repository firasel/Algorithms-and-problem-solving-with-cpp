#include <bits/stdc++.h>
using namespace std;

class UrlLinkedList
{
public:
  string url;
  UrlLinkedList *next;
  UrlLinkedList *prev;
  UrlLinkedList(string url)
  {
    this->url = url;
    next = NULL;
    prev = NULL;
  }
};

class BrowserHistory
{
public:
  UrlLinkedList *curr = NULL, *temp = NULL;
  BrowserHistory(string homepage)
  {
    curr = new UrlLinkedList(homepage);
  }

  void visit(string url)
  {
    temp = new UrlLinkedList(url);
    curr->next = temp;
    temp->prev = curr;
    curr = temp;
  }

  string back(int steps)
  {
    while (steps-- && curr->prev)
      curr = curr->prev;
    return curr->url;
  }

  string forward(int steps)
  {
    while (steps-- && curr->next)
      curr = curr->next;
    return curr->url;
  }
};

int main()
{
  BrowserHistory *browserHistory = new BrowserHistory("leetcode.com");
  browserHistory->visit("google.com");
  browserHistory->visit("facebook.com");
  browserHistory->visit("youtube.com");

  cout << browserHistory->back(1) << endl;
  cout << browserHistory->back(1) << endl;
  cout << browserHistory->forward(1) << endl;

  browserHistory->visit("linkedin.com");

  cout << browserHistory->forward(2) << endl;
  cout << browserHistory->back(2) << endl;
  cout << browserHistory->back(7) << endl;

  return 0;
}