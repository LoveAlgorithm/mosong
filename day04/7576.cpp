/*
info
- 7576 토마토

start
1. 그래프 탐색 -> BFS
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
struct node {
  int y;
  int x;
  int depth;
};
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);

  int y, x, cnt_visit = 0;
  cin >> x >> y;
  vector<vector<int>> tomato(y, vector<int>(x, 0));
  vector<vector<int>> visit(y, vector<int>(x, 0));
  queue<node> q;
  int min_date = 0;

  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      cin >> tomato[i][j];
      if (tomato[i][j] == 1) {
        visit[i][j] = 1;
        cnt_visit++;
        q.push({i, j, 1});
      } else if (tomato[i][j] == -1)
        cnt_visit++;
    }
  }

  while (!q.empty()) {
    node cur = q.front();
    q.pop();
    if (cur.depth > min_date)
      min_date = cur.depth;
    for (int i = 0; i < 4; i++) {
      int ny = cur.y + dy[i];
      int nx = cur.x + dx[i];

      if ((nx < 0 || nx >= x || ny < 0 || ny >= y) || visit[ny][nx] > 0)
        continue;
      if (tomato[ny][nx] != 0)
        continue;
      q.push({ny, nx, cur.depth + 1});
      visit[ny][nx] = cur.depth + 1;
      cnt_visit++;
    }
  }

  if (cnt_visit == y * x)
    cout << min_date - 1 << endl;
  else
    cout << -1 << endl;

  return 0;
}