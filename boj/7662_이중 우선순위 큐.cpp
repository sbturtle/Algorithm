#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;	cin >> T;
	while (T--) {
		multiset<long long> s;
		int N;	cin >> N;
		while (N--) {
			char ch;	cin >> ch;
			if (ch == 'I') {
				long long n;	cin >> n;
				s.insert(n);
			}
			else {
				int t;	cin >> t;
				if (s.empty())
					continue;

				if (t == 1)
					s.erase(s.find(*s.crbegin()));
				else
					s.erase(s.begin());
			}
		}
		if (s.empty())
			cout << "EMPTY" << '\n';
		else
			cout << *s.crbegin() << ' ' << *s.begin() << '\n';
	}

	return 0;
}