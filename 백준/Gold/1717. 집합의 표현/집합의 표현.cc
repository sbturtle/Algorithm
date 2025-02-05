#include <iostream>
#include <algorithm>
using namespace std;

int parent[1000004];

int find(int x) {
	if (parent[x] <  0) return x;
	return parent[x] = find(parent[x]);
}

bool isInclude(int& u, int& v) {
	u = find(u);
	v = find(v);

	if (u == v)
		return true;
	return false;
}

bool uni(int u, int v) {
	if (isInclude(u, v))
		return false;
	if (parent[u] > parent[v])
		swap(u, v);
	parent[u]--;
	parent[v] = u;

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	fill(parent, parent + n + 1, -1);

	while (m--) {
		int act, a, b;
		cin >> act >> a >> b;

		if (act == 0) {
			uni(a, b);
		}
		else {
			if (a == b) {
				cout << "YES" << '\n';
				continue;
			}

			cout << (isInclude(a, b) ? "YES" : "NO") << '\n';
		}
	}


	return 0;
}