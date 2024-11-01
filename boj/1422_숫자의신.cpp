#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1 <= list[k] <= 1,000,000,000
// 1 <= k <= n <= 50

bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, n;
	cin >> k >> n;
	vector<string> vec;
	for (int i = 0; i < k; i++)
	{
		string str;
		cin >> str;
		vec.push_back(str);
	}

	sort(vec.begin(), vec.end(), cmp);

	int c = n - k;
	int mv = vec[0].length();
	string tmp = "";
	for (string str : vec) {
		if (mv < str.length()) {
			tmp = str;
			mv = str.length();
		}
	}

	if (tmp == "")
		while (c--)
			cout << vec[0];

	bool i = true;
	for (string str : vec) {
		cout << str;
		if (str == tmp && i) {
			while (c--)
				cout << tmp;
			i = false;
		}
	}

	return 0;
}
