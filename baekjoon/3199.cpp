#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  double p,q,r;
  cin >> p >> q >> r;
  cout.setf(ios::showpoint);
  cout.precision(4);
  cout << fixed;
  if (p != r) {
    cout << '0' << endl;
  } else {
    // 미분 결과물
    cout << 2 * p * (p + q) << endl;
  }
  return 0;
}