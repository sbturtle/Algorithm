#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> vec;
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int h;        cin >> h;
		vec.push_back(h);
	}

	long long result = 0;
	sort(vec.begin(), vec.end());

	long long st = 1, ed = vec.back() - vec.front();
	while (st <= ed) {
		long long md = (st + ed) / 2;
		int cnt = 1;
		int nxt = vec[0];


		for (int i = 1; i < n; i++) {
			if (vec[i] - nxt >= md) {
				cnt++;
				nxt = vec[i];
			}
		}

		if (cnt >= c) {
			result = max(result, md);
			st = md + 1;
		}
		else
			ed = md - 1;
	}

	cout << result;

	return 0;
}