/*
info
- 23785 organ-free man

start
1. 재귀 + 팩토리얼
  -> 특정 case에서 fail
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
using pii = pair<int, int>;

vector<int> factorial(10, 1);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int y;
	vector<int> answer;
	string str = "";

	for (int i = 2; i < 10; i++) {
		factorial[i] = (i * factorial[i - 1]);
	}
	cin >> y;
	
	for (int i = 9; i > 0; i--) {
		while (y >= factorial[i]) {
			y -= factorial[i];
			answer.push_back(i);
		}
	}
	
	for (int i = answer.size() - 1; i >= 0; i--) {
		str += to_string(answer[i]);
	}
	cout << str << '\n';
	return 0;
}