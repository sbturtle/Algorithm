#include <iostream>
#include <vector>
using namespace std;

#define LL long long

int n;
vector<LL> vec;

LL s = 160000000000;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vec = vector<LL>(n);

	for (size_t i = 0; i < n; i++)
		cin >> vec[i];

	LL rc = 0, lc = n - 1;
	LL r1 = 0, r2 = n - 1;
	while (rc < lc) {
		LL tmp = vec[rc] + vec[lc];

		if (tmp == 0) {
			r1 = vec[rc];
			r2 = vec[lc];
			break;
		}
		if (s >= abs(tmp)) {
			s = abs(tmp);
			r1 = vec[rc];
			r2 = vec[lc];
		}

		if (tmp > 0)
			lc--;
		else if (tmp < 0)
			rc++;
	}

	cout << r1 << ' ' << r2;

	return 0;
}