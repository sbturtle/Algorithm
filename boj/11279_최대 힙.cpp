#include <iostream>
#include <queue>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	priority_queue<int> pq;

	while (n--) {
		int num;	cin >> num;
		if (num == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
			continue;
		}
		pq.push(num);
	}

	return 0;
}