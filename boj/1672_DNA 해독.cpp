#include <iostream>
#include <stack>
using namespace std;

// 65 A / 68 C / 71 G / 84 T

string map[4] = { "ACAG","CGTA","ATCG","GAGT" };

int converter(char ch) {
	if (ch == 'A')
		return 0;
	else if (ch == 'G')
		return 1;
	else if (ch == 'C')
		return 2;
	else if (ch == 'T')
		return 3;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	stack<int> st;

	string str;
	cin >> str;
	for (int i = 0; i < n; i++)
	{
		int temp = converter(str[i]);

		st.push(temp);
	}

	char result = str[0];
	while (st.size() != 1) {
		int cur = st.top(); st.pop();
		result = map[cur][st.top()];
		int temp = converter(result);
		st.pop();
		st.push(temp);
	}

	cout << result;

	return 0;
}