#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define LL long long

int a[500001];
int n;
vector<bool> isVis(500001, false);
int binarySearch(int t) {
	int st = 0;
	int ed = n - 1;
	while (st <= ed)
	{
		int mid = (st + ed) / 2;
		if (a[mid] == t)
			return mid;
		else if (a[mid] > t)
			ed = mid - 1;
		else
			st = mid + 1;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n2;
	cin >> n >> n2;


	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	int c = 0;
	for (int i = 0; i < n2; i++)
	{
		LL tmp;		cin >> tmp;
		int idx = binarySearch(tmp);
		if (idx == -1)			continue;
		isVis[idx] = true;
		c++;
	}

	int result = n - c;
	cout << result << '\n';

	if (result) {
		for (int i = 0; i < n; i++) {
			if (!isVis[i])
				cout << a[i] << ' ';
		}
	}

	return 0;
}