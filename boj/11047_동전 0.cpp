#include <iostream>
using namespace std;

int arr[11];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int result = 0;
	while (n-- >= 0)
	{
		if (k == 0) break;

		if (k >= arr[n]) {
			result += k / arr[n];
			k %= arr[n];
		}
	}

	cout << result;

	return 0;
}
