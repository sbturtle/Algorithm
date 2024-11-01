#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;

int isvis[101];
int mn = 1600000000;
int result = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	map<int, vector<int>> mp;

	for (int i = 1; i <= m; i++)
	{
		int a, b;	cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		fill(isvis, isvis + n + 1, -1);
		isvis[i] = 0;
		
		queue<int> q;
		q.push(i);

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int num : mp[cur]) {
				if (isvis[num] != -1)
					continue;

				isvis[num] = isvis[cur] + 1;
				q.push(num);
			}
		}
		int sum = 0;
		for (int j = 1; j <= n; j++)
			sum += isvis[j];

		if (mn > sum) {
			result = i;
			mn = min(mn, sum);
		}
		else if (mn == sum) {
			result = min(result, i);
		}
	}

	cout << result;

	return 0;
}