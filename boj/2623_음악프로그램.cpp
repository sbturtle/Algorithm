#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1);
	vector<int> deg(n + 1);

	vector<int> answer;
	for (int i = 0; i < m; i++) {
		int cnt;
		cin >> cnt;
		int a;
		cin >> a;
		for (int j = 0; j < cnt - 1; j++) {
			int b;
			cin >> b;
			adj[a].push_back(b);
			deg[b]++;
			a = b;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		answer.push_back(cur);
		for (auto i : adj[cur]) {
			deg[i]--;
			if (deg[i] == 0) q.push(i);
		}
	}

	if (answer.size() != n)
		cout << 0;
	else {
		for (int s : answer)
			cout << s << '\n';
	}

	return 0;
}
