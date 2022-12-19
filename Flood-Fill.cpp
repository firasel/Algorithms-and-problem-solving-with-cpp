#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
  {
    if (image[sr][sc] == color)
      return image;
    int prevColor = image[sr][sc], n = image.size(), m = image[0].size();
    queue<pair<int, int>> q;
    q.push({sr, sc});
    while (!q.empty())
    {
      int nr = q.front().first, nc = q.front().second;
      q.pop();
      image[nr][nc] = color;
      if (nr - 1 >= 0 && image[nr - 1][nc] == prevColor)
        q.push({nr - 1, nc});
      if (nr + 1 < n && image[nr + 1][nc] == prevColor)
        q.push({nr + 1, nc});
      if (nc - 1 >= 0 && image[nr][nc - 1] == prevColor)
        q.push({nr, nc - 1});
      if (nc + 1 < m && image[nr][nc + 1] == prevColor)
        q.push({nr, nc + 1});
    }
    return image;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> image = {{0, 0, 0}, {0, 0, 0}};
  vector<vector<int>> ans = st.floodFill(image, 1, 0, 2);
  for (auto chVect : ans)
  {
    for (auto el : chVect)
      cout << el << " ";
    cout << endl;
  }

  return 0;
}