#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<int>> adj(n + 1, vector<int>());
	vector<int> deg(n + 1);

	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		adj[n1].push_back(n2);
		deg[n2]++;
	}
	queue<int>q;
	vector<int> result;

	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		result.push_back(cur);
		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	for (int r : result)
		cout << r << ' ';

	return 0;
}