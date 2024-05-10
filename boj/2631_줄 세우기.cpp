#include <iostream>
using namespace std;

int arr[201];
int asc[201];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	fill(asc, asc + n, 1);

	int a = asc[1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && asc[i] <= asc[j]) {
				asc[i] = asc[j] + 1;
				if (a < asc[i])
					a = asc[i];
			}
		}
	}
	cout << n - a;

	return 0;
}