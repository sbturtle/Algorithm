#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> vec(6);

int s[6];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;    cin >> n;

	for (int i = 1; i <= 5; i++)
		cin >> s[i];

	for (int i = 0; i < n; i++) {
		int idx, num;
		cin >> idx >> num;

		vec[idx].push_back(num);
	}

	for (int i = 1; i < 6; i++)
		sort(vec[i].begin(), vec[i].end());
	int result = -60;
	for (int i = 1; i <= 5; i++) {
		int sum = vec[i][0];
		for (int j = 1; j < s[i]; j++) {
			sum += vec[i][j] + (vec[i][j] - vec[i][j - 1]);
		}
		result += sum + 60;
	}

	cout << result;
	return 0;
}