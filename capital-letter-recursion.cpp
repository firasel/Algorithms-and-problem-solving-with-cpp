#include <bits/stdc++.h>
using namespace std;

char getCapital(string str)
{
  if (str.empty() || (str.front() >= 'A' && str.front() <= 'Z')) // Base case
    return str.front();
  str.erase(str.begin());
  return getCapital(str); // Recursive case
}

int main()
{
  cout << getCapital("thisStRIng") << endl;
  return 0;
}