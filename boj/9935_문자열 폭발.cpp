#include <iostream>
#include <deque>
using namespace std;

#define X first
#define Y second

string str;
string c4;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str >> c4;

	deque<pair<string, int>> st;
	string result = "";

	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];
		if (ch == c4[0]) {
			string tmp = "";	tmp += c4[0];
			st.push_front({ tmp,1 });
		}
		else if (!st.empty()) {
			auto cur = st.front();

			if (ch == c4[cur.Y]) {
				st.pop_front();
				cur.first += ch;
				cur.Y++;

				if (cur.X != c4)
					st.push_front(cur);
			}
			else {
				while (!st.empty()) {
					auto c = st.back(); st.pop_back();
					result += c.X;
				}
				result += ch;
			}
		}
		else
			result += ch;
	}

	while (!st.empty()) {
		auto c = st.back(); st.pop_back();
		result += c.X;
	}

	if (result == "")
		cout << "FRULA";
	else {
		cout << result;
	}

	return 0;
}