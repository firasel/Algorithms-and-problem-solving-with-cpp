#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getCommon(vector<int> &nums1, vector<int> &nums2)
  {
    int s1 = nums1.size(), s2 = nums2.size(), i = 0, j = 0;
    while (i < s1 && j < s2)
    {
      if (nums1[i] == nums2[j])
        return nums1[i];
      else if (nums1[i] < nums2[j])
        i++;
      else
        j++;
    }
    return -1;
  }
};

int main()
{
  Solution st;
  vector<int> nums1 = {1, 2, 3}, nums2 = {2, 4};
  cout << st.getCommon(nums1, nums2) << endl;

  return 0;
}