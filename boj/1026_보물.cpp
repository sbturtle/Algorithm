#include <iostream>
#include <algorithm>
using namespace std;

int a[50];
int b[50];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int result = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(b, b + n);
	reverse(b, b + n);

	for (int i = 0; i < n; i++)
		result += a[i] * b[i];

	cout << result;

	return 0;
}