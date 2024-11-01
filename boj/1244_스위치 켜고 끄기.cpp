#include <iostream>
#include <vector>
using namespace std;

int n, s;
vector<bool> sc;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		sc.push_back(tmp);
	}

	cin >> s;
	while (s--) {
		int g, num;
		cin >> g >> num;
		if (--g) {		// 여자
			int l = --num;
			int r = num;
			do {
				l--;
				r++;
				if (l < 0 || r >= n)
					break;
			} while (sc[l] == sc[r]);

			for (int i = l + 1; i < r; i++)
				sc[i] = !sc[i];
		}
		else {		// 남자
			for (int i = num - 1; i < n; i += num)
				sc[i] = !sc[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (i != 0 && i % 20 == 0)
			cout << '\n';
		cout << sc[i] << ' ';
	}

	return 0;
}