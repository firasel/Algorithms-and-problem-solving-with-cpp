#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  vector<Node *> neighbors;
  Node()
  {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val)
  {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution
{
public:
  Node *DFS(Node *node, unordered_map<Node *, Node *> &mp)
  {
    vector<Node *> neighbors;
    Node *newNode = new Node(node->val);
    mp[node] = newNode;
    for (auto neighbor : node->neighbors)
    {
      if (mp.find(neighbor) != mp.end())
        neighbors.push_back(mp[neighbor]);
      else
        neighbors.push_back(DFS(neighbor, mp));
    }
    newNode->neighbors = neighbors;
    return newNode;
  }

  Node *cloneGraph(Node *node)
  {
    if (!node)
      return node;
    unordered_map<Node *, Node *> mp;
    DFS(node, mp);
    return mp[node];
  }
};

int main()
{
  Solution st;
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  Node *node4 = new Node(4);

  node1->neighbors = {node2, node4};
  node2->neighbors = {node1, node3};
  node3->neighbors = {node2, node4};
  node4->neighbors = {node3, node1};

  auto newEl = st.cloneGraph(node1);
  cout << newEl->val << endl;

  return 0;
}