#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nxt = 0;
	int idx = 0;
	string str;
	string result = "";

	for (int i = 0; i < 3; i++) {
		cin >> str;
		int n = atoi(str.c_str());
		if (n == 0)	continue;
		nxt = n;
		idx = i;
	}
	while (idx != 3)
	{
		nxt++;
		idx++;
	}
	if (nxt % 3 == 0) {
		result += "Fizz";
	}
	if (nxt % 5 == 0) {
		result += "Buzz";
	}

	if (result.length())
		cout << result;
	else
		cout << nxt;

	return 0;
}