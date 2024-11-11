#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, l;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l;
	vector<vector<int>> vec(n, vector<int>(n));
	vector<vector<bool>> rw(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];
		}
	}

	int result = 0;
	// 가로 판별
	for (int i = 0; i < n; i++) {
		int cur = vec[i][0];
		bool isp = true;
		for (int j = 1; j < n; j++) {
			if (!isp)	break;
			if (cur == vec[i][j])	continue;
			if (abs(cur - vec[i][j]) > 1) {
				isp = false;
				break;
			}
			if (cur > vec[i][j]) {
				int s = vec[i][j];
				rw[i][j] = true;
				for (int k = 1; k < l; k++)
				{
					if (j + k == n || s != vec[i][j + k]) {
						isp = false;
						break;
					}
					rw[i][j + k] = true;
				}
				j += l - 1;
				cur = s;
			}
			else {
				j--;
				if (rw[i][j]) {
					isp = false;
					break;
				}
				rw[i][j] = true;

				for (int k = 1; k < l; k++)
				{
					if (j - k < 0 || cur != vec[i][j - k] || rw[i][j - k]) {
						isp = false;
						break;
					}
					rw[i][j - k] = true;
				}
				j++;
				cur = vec[i][j];
			}
		}
		if (isp)
			result++;
	}

	for (int i = 0; i < n; i++)
		fill(rw[i].begin(), rw[i].end(), false);

	// 세로 판별
	for (int j = 0; j < n; j++) {
		bool isp = true;
		int cur = vec[0][j];
		for (int i = 1; i < n; i++) {
			if (!isp)	break;
			if (cur == vec[i][j])
				continue;
			if (abs(cur - vec[i][j]) > 1) {
				isp = false;
				break;
			}

			if (cur > vec[i][j]) {
				int s = vec[i][j];
				rw[i][j] = true;
				for (int k = 1; k < l; k++)
				{
					if (i + k == n || s != vec[i + k][j]) {
						isp = false;
						break;
					}
					rw[i + k][j] = true;
				}
				i += l - 1;
				cur = s;
			}
			else {
				i--;
				if (rw[i][j]) {
					isp = false;
					break;
				}
				rw[i][j] = true;

				for (int k = 1; k < l; k++)
				{
					if (i - k < 0 || cur != vec[i - k][j] || rw[i - k][j]) {
						isp = false;
						break;
					}
					rw[i - k][j] = true;
				}
				i++;
				cur = vec[i][j];
			}
		}
		if (isp)
			result++;
	}

	cout << result;

	return 0;
}