#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

int INF = 1e9 + 10;
int city, cnt;
int st, ed;
int d[1'004];		// 최소거리
int pre[1'004];
vector<vector<pair<int, int>>> bus;		// 간선

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> city >> cnt;
	bus = vector<vector<pair<int, int>>>(city + 4);

	fill(d, d + city + 4, INF);

	while (cnt--) {
		int u, v, w;
		cin >> u >> v >> w;
		bus[u].push_back({ w,v });
	}

	cin >> st >> ed;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[st] = 0;
	pq.push({ d[st],st });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.Y] != cur.X)			continue;

		for (auto nxt : bus[cur.Y]) {
			if (d[nxt.Y] <= cur.X + nxt.X)				continue;

			pq.push({ cur.X + nxt.X, nxt.Y });
			d[nxt.Y] = cur.X + nxt.X;
			pre[nxt.Y] = cur.Y;
		}
	}

	stack<int> s;
	int p = ed;
	s.push(p);
	while (p != st) {
		p = pre[p];
		s.push(p);
	}
	cout << d[ed] << '\n';
	cout << s.size() << '\n';

	while (!s.empty()) {
		int cur = s.top(); s.pop();
		cout << cur << ' ';
	}

	return 0;
}
