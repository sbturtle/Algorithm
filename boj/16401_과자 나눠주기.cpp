#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> vec;
int m, n;
int mx = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	vec = vector<int>(n);

	for (size_t i = 0; i < n; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	int lc = 1, rc = vec[n - 1];
	while (lc <= rc) {
		int md = (lc + rc) / 2;
		
		int s = 0;
		for (int ss : vec) {
			s += ss / md;
		}

		if (s >= m) {
			mx = max(mx, md);
			lc = md + 1;
		}
		else {
			rc = md - 1;
		}
	}

	cout << mx;

	return 0;
}