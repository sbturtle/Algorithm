#include<iostream>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		if (i == 0) {
			result = arr[i];
		}
		else {
			arr[i] = max(arr[i - 1] + arr[i], arr[i]);
			if (result < arr[i]) result = arr[i];
		}
	}
	cout << result;

	return 0;
}
