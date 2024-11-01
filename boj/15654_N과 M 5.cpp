#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> vec;
vector<int> vec1;
vector<bool> isvis(9, false);


void func(int cnt) {
	if (cnt > m)
		return;

	if (cnt == m) {
		for (int i : vec1)
			cout << i << ' ';

		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isvis[i])	continue;

		isvis[i] = true;
		vec1.push_back(vec[i]);
		func(cnt + 1);
		vec1.pop_back();
		isvis[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());

	func(0);

	return 0;
}