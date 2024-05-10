#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	queue<int> q;
	queue<int> result;

	for (int i = 1; i <= n; i++)
		q.push(i);

	int c = 0;
	while (!q.empty()) {
		c++;
		int cur = q.front();	q.pop();
		if (c % k == 0) {
			result.push(cur);
			continue;
		}
		q.push(cur);

	}
	cout << '<';
	while (!result.empty()) {
		int cur = result.front(); result.pop();
		cout << cur;

		if (!result.empty())
			cout << ", ";
	}
	cout << '>';

	return 0;
}