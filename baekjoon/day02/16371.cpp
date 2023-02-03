/*
info
- 16371 작은수 내기

start
1. 확률계산이라 조합을 생각함 -> 그 이상이 생각안남
2. 알고리즘 분류 확인 -> 정렬 후 동일 위치에 있는 것끼리 비교 후 결과 도출 시도
X(문제 의도 파악 실수)
3. 이기는 경우가 생기는지만 체크 -> 정렬하고 접근 가능한 젤 작은 인자가 이길 수 없으면 젤 큰 녀석을 대신 제출

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  int N, answer = 0;
  cin >> N;
  deque<short> a(N, 0), b(N, 0);

  for (auto &card : a)
    cin >> card;
  for (auto &card : b)
    cin >> card;
  sort(a.begin(), a.end()); // 주언
  sort(b.begin(), b.end()); // 사장

  for (int i = 0; i < N; i++) {
    if (b.front() <= a.front()) {
      b.pop_front();
      a.pop_back();
    } else {
      b.pop_front();
      a.pop_front();
      answer++;
    }
  }
  ((N + 1) / 2 <= answer) ? cout << "YES\n" : cout << "NO\n";
  return 0;
}