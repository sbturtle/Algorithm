#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[1501][1501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (pq.size() == n && pq.top() < a) {
				pq.pop();
				pq.push(a);
			}
			else if(pq.size() < n)
				pq.push(a);
		}
	}
	cout << pq.top();

	return 0;
}