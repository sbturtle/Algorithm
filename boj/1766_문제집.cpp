#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> quest(n + 1);
	vector<int> deg(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		quest[a].push_back(b);
		deg[b]++;
	}

	// �����ϸ� ���� �������� Ǯ��� �Ѵ�.
	// -> ������ �������� �ʴ� ���� �� ���� ���� ������ �켱������ ó��
	// �켱���� ť + ������������ ����
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0) q.push(i);

	vector<int> result;
	while (!q.empty()) {
		int cur = q.top(); q.pop();
		result.push_back(cur);
		for (int s : quest[cur]) {
			if (--deg[s] == 0) q.push(s);
		}
	}

	for (int r : result)
		cout << r << ' ';

	return 0;
}

