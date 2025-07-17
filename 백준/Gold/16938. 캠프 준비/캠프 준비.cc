#include <iostream>
using namespace std;

int n, l, r, x;
int arr[16];
int result;

void func(int idx, int sum, int mx, int mn) {
	if (sum > r)
		return;

	if (l <= sum && sum <= r && x <= (mx - mn))
		result++;

	for (int i = idx + 1; i < n; i++) {
		int t = mx < arr[i] ? arr[i] : mx;
		int b = arr[i] < mn ? arr[i] : mn;

		func(i, sum + arr[i], t, b);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// L <= rank <= R
	// X <= max - min
	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	func(-1, 0, 0, 1'000'000'000);

	cout << result;

	return 0;
}