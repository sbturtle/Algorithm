#include <iostream>

using namespace std;

int main() {
	int n;
	int cnt = 0;
	bool isGroup;
	string str;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		int size = str.length();
		 isGroup = true;

		for (int j = 0; j < size; j++) {
			for (int k = 0; k < j; k++) {
				if (str[j] != str[j - 1] && str[j] == str[k]) {
					isGroup = false;
					break;
				}
			}
		}
		if (isGroup) cnt++;
	}

	cout << cnt;

	return 0;
}