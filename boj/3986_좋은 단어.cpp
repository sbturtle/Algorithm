#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int count = 0;
	while (n--) {
		stack<char> st;
		string str; cin >> str;
		bool isGood = true;
		for (char ch : str) {
			int idx = ch - 'A';

			if (st.empty())
				st.push(ch);
			else {
				if (st.top() == ch)
					st.pop();
				else
					st.push(ch);
			}
		}

		if (st.empty())
			count++;
	}
	cout << count;
	return 0;
}