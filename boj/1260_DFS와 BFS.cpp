#include<iostream>
#include<queue>
#include<stack>

using namespace std;
int map[1001][1001];
int isVis[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	// DFS
	stack<int> st;
	st.push(v);
	while (!st.empty()) {
		auto cur = st.top(); st.pop();
		if (!isVis[cur]) {
			isVis[cur] = true;
			cout << cur << ' ';
			for (int i = n; i >= 1; i--)	//������ ���� �ͺ��� ��ȸ�ؾ��ϹǷ�,
			{								// stack������ ������ ū �ͺ��� push�ؾ� ��.
				if (map[cur][i] == 1) {
					st.push(i);
				}
			}
		}
	}

	// �ʱ�ȭ
	cout << '\n';
	fill(isVis, isVis + n + 1, 0);
	// BFS
	queue<int> q;
	q.push(v);
	isVis[v] = true;
	cout << v << " ";
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (map[cur][i] == 1 && !isVis[i]) {
				isVis[i] = true;
				q.push(i);
				cout << i << ' ';
			}
		}
	}

	return 0;
}