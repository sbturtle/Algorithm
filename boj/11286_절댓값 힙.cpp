#include<iostream>
#include <queue>
using namespace std;

int n;

struct Cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, Cmp> pq;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		if (a != 0) {
			pq.push(a);
		}
		else {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else {
				cout << 0 << '\n';
			}
		}
	}

	return 0;
}