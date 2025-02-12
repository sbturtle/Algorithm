#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

int v, e, k;		// 1 <= v <= 20'000, 1<= e <= 300'000

int d[20005];
int INF = 1e9 + 10;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e >> k;
	vector<vector<pair<int, int>>> adj = vector<vector<pair<int, int>>>(v + 1);

	fill(d, d + v + 1, INF);

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	d[k] = 0;
	pq.push({ d[k],k });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.Y] != cur.X) continue;

		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] <= cur.X + nxt.X)
				continue;

			pq.push({ cur.X + nxt.X, nxt.Y });
			d[nxt.Y] = cur.X + nxt.X;
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}

	return 0;
}
