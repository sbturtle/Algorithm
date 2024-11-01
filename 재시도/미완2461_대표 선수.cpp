#include <iostream>
#include <algorithm>
using namespace std;

int map[1001][1001];
int tp[1001][2];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++)
		sort(map[i], map[i] + m);

	

	return 0;
}