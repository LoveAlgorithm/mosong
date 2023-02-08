/*
info
- 1753 최단 경로

start
1. 최단거리 + 가중치 => 다익스트라
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
using pii = pair<int, int>; // cost, node index
#define INF 987654321
int v, e, start;
map<int, vector<pii>> graph;
vector<int> cost;
vector<bool> visit;

void dijkstra(int s) {
	priority_queue<pii, vector<pii>, greater<pii>> pq; // 코스트가 
	pq.push({ 0, s }); // cost, pos
	cost[s] = 0;
	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();

		if (graph[cur.second].empty() || visit[cur.second]) continue;
		visit[cur.second] = true;

		for (pii node : graph[cur.second]) { // 도착점, 점수
			if (node.second + cur.first < cost[node.first])
				cost[node.first] = node.second + cur.first;
			pq.push({ cost[node.first] , node.first });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
  cout.tie(0);
	cin >> v >> e >> start;

	cost.resize(v + 1, INF);
	visit.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int s, d, c;
		cin >> s >> d >> c;
		graph[s].push_back({ d, c });
	}

	dijkstra(start);

	for (int i = 1; i <= v; i++) {
		if (cost[i] == INF)
			cout << "INF\n";
		else
			cout << cost[i] << '\n';
	}
	return 0;
}