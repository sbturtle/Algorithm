#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define LL long long

LL k, n;
vector<LL> lc;

LL mx = 0;

int sum(LL m) {
	LL s = 0;
	for (LL num : lc)
		s += num / m;
	return s;
}

void func(LL st, LL ed) {
	LL md = (ed + st) / 2;

	LL s = sum(md);

	if (st > ed) {
		mx = max(mx, md);
		return;
	}

	if (s >= n) {
		mx = max(mx, md);
		func(md + 1, ed);
	}
	else {
		func(st, md - 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	lc = vector<LL>(k);

	for (size_t i = 0; i < k; i++)	
		cin >> lc[i];
	

	sort(lc.begin(), lc.end());

	func(1, lc[k-1]);

	cout << mx;

	return 0;
}