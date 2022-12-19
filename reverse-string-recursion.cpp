#include <bits/stdc++.h>
using namespace std;

string reverseStr(string str)
{
  if (str.length() < 2) // Base case
    return str;
  char temp = str.back();
  str.pop_back();
  return temp + reverseStr(str); // Recursive case
}

int main()
{
  cout << reverseStr("phitron") << endl;
  return 0;
}