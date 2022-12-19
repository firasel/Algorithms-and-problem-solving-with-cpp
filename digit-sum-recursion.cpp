#include <bits/stdc++.h>
using namespace std;

int digitSum(int n)
{
  if (n <= 0) // Base case
    return 0;
  return n % 10 + digitSum(n / 10); // Recursive case
}

int main()
{
  cout << digitSum(7464) << endl;
  return 0;
}