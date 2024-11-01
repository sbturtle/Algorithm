#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LL long long

vector<LL> vec;
LL n, m;
LL mx = 0;

LL cut(LL c) {
	LL s = 0;
	for (LL tr : vec) {
		if (tr < c)
			continue;
		s += tr - c;
	}

	return s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	vec = vector<LL>(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	LL l = 1, r = vec[n - 1];

	while (l <= r) {
		LL md = (l + r) / 2;
		LL s = cut(md);

		if (s < m) {
			r = md - 1;
		}
		else {
			mx = max(mx, md);
			l = md + 1;
		}
	}

	cout << mx;

	return 0;
}
