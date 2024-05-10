#include <iostream>
#include <algorithm>
using namespace std;
long long a[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		binary_search(a, a + n, num) ? cout << 1 : cout << 0;
		cout << '\n';
		
	}

	return 0;
}