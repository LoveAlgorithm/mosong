/*
info
- 25204 문자열 정렬

start
1. 정렬 + 추가 조건 -> 시간초과
2. Trie...?
접근
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool comp1(string a, string b) {
  return a.length() < b.length();
}
bool comp2(string a, string b) {
  short str_len = a.length();
  for (int i = 0; i < str_len; i++){
    if (a[i] != b[i]) {
      if (a[i] == '-') return false;
      else if (b[i] == '-') return true;
      else {
        if (toupper(a[i]) == toupper(b[i])) {
          return a[i] < b[i];
        } else {
          return toupper(a[i]) < toupper(b[i]);
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);

  int test_case, test_total;
  string dump;
  cin >> test_total;
  vector<vector<string>> strs;
  strs.resize(test_total);
  
  for (int i = 0; i < test_total; i++) {
    cin >> test_case;
    for (int j = 0; j < test_case; j++) {
      cin >> dump;
      strs[i].push_back(dump);
    }
    sort(strs[i].begin(), strs[i].end(), comp2);
  }

  for (auto str : strs)
    for (auto s : str)
      cout << s << endl;
  return 0;
}