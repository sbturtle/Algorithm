#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {

		string str;
		cin >> str;
		if (str == "0")
			break;

		int size = str.length();
		bool isP = true;
		for (int i = 0; i < size / 2; i++)
		{
			if (!isP) break;
			if (str[i] != str[(size - 1) - i])
				isP = false;
		}
		cout << (isP ? "yes" : "no") << '\n';
	}

	return 0;
}