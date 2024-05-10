#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;
	for (int c = 1; c <= k; c++)
	{
		cout << "Class " << c << '\n';

		int n;
		cin >> n;

		int arr[51] = { 0, };
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		int lGap = 0;
		sort(arr, arr + n);
		for (int i = 1; i < n; i++)
		{
			int gap = arr[i] - arr[i - 1];

			if (lGap < gap) {
				lGap = gap;
			}
		}

		cout << "Max " << arr[n - 1] << ", Min " << arr[0] << ", Largest gap " << lGap << '\n';
	}

	return 0;
}