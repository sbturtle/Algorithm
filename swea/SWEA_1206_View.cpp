// SWEA_1206_View
#include<iostream>
#include<algorithm>
using namespace std;
int b[1002];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int t = 1; t <= 10; t++)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> b[i];
		int result = 0;
		for (int i = 2; i < n - 2; i++) {
			int lNear = max(b[i - 1], b[i - 2]);
			int rNear = max(b[i + 1], b[i + 2]);
			int near = max(lNear, rNear);
			if (b[i] > near)
				result += b[i] - near;
		}

		cout << '#' << t << ' ' << result << '\n';
		fill(b + 2, b + n, 0);
	}

	return 0;
}