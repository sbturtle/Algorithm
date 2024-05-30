#include <iostream>
using namespace std;

int arr[100004];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s; cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int result = 100000001;

	int sum = 0;

	int st = 0, ed = 0;
	while (true)
	{
		if (sum < s) {
			if (ed == n)
				break;
			sum += arr[ed++];
		}
		else {
			result = min(result, ed - st);
			sum -= arr[st++];
		}
	}

	if (result == 100000001)
		result = 0;

	cout << result;
	return 0;
}