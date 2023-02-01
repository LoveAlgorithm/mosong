#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  int cnt_man = 0, cnt_woman = 0;
  int diff;
  bool is_swap = false;
  string lane;
  cin >> diff >> lane;

  for (int i = 0; i < lane.length(); i++) {
    if (lane[i] == 'M') {
      if (abs((cnt_man+1) - cnt_woman) <= diff)
        cnt_man++;
      else if ( i + 1 < lane.length() && lane[i+1] == 'W') {
        swap(lane[i], lane[i + 1]);
        cnt_woman++;
      } else { // M이면서 차이가 넘을거 같은데 다음것도 M인경우
        break;
      }
    } else {
      if (abs((cnt_man) - (cnt_woman + 1)) <= diff)
        cnt_woman++;
      else if (i + 1 < lane.length() && lane[i + 1] == 'M') {
        swap(lane[i], lane[i + 1]);
        cnt_man++;
      } else {
        break;
      }
    }
  }
  cout << cnt_man + cnt_woman << '\n';
  return 0;
}