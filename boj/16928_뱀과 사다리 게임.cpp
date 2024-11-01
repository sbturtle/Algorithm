#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int map[101];
int isvis[101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(isvis, isvis + 101, -1);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		map[n1] = n2;
	}

	queue<int> q;
	q.push(1);
	isvis[1] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 1; i <= 6; i++) {
			int nxt = cur + i;
			if (isvis[nxt] != -1 || nxt > 100)
				continue;

			isvis[nxt] = isvis[cur] + 1;
			int b = map[nxt];
			if (b != 0) {
				if (isvis[b] == -1) {
					isvis[b] = isvis[nxt];
					q.push(b);
				}
			}
			else
				q.push(nxt);

			if (nxt == 100)
				break;

		}
	}
	cout << isvis[100];

	return 0;
}