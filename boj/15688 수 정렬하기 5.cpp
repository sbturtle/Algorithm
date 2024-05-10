#include <bits/stdc++.h>
using namespace std;

int arr[2000001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		arr[tmp + 1000000]++;
	}

	for (int i = 0; i <= 2000000; i++)	
	{
		while (arr[i]--) {
			cout << i - 1000000 << '\n';
		}
	}

	return 0;
}