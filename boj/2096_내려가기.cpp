#include <iostream>
#include <vector>
using namespace std;

int n;
int map[3] = {};

int mx[3];
int mn[3];

int mxt[3] = {};
int mnt[3] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[0] >> map[1] >> map[2];

		mxt[0] = map[0] + max(mx[0], mx[1]);
		mnt[0] = map[0] + min(mn[0], mn[1]);

		mxt[1] = map[1] + max(max(mx[0], mx[1]), mx[2]);
		mnt[1] = map[1] + min(min(mn[0], mn[1]), mn[2]);

		mxt[2] = map[2] + max(mx[1], mx[2]);
		mnt[2] = map[2] + min(mn[1], mn[2]);

		mx[0] = mxt[0];
		mx[1] = mxt[1];
		mx[2] = mxt[2];
		mn[0] = mnt[0];
		mn[1] = mnt[1];
		mn[2] = mnt[2];
	}

	int r1 = max(max(mx[0], mx[1]), mx[2]);
	int r2 = min(min(mn[0], mn[1]), mn[2]);
	cout << r1 << '\n' << r2;

	return 0;
}