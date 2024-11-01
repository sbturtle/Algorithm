#include <iostream>
using namespace std;

int n, t, p;
// S, M, L, XL, XXL, XXXL
int s[6];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < 6; i++)
		cin >> s[i];

	cin >> t >> p;

	int tc = 0;
	for (int i = 0; i < 6; i++) {
		if (s[i] % t != 0)
			tc++;
		tc += s[i] / t;
	}
	cout << tc << '\n';
	cout << n / p << ' ' << n%p;

	return 0;
}