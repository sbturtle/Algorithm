#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

stack<int> st;
queue<int> q;
vector<int> result;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt = i;
		int x;
		cin >> x;

		if (st.empty()) {
			st.push(x);
			result.push_back(0);
			continue;
		}

		if (st.top() > x) {
			st.push(x);
			result.push_back(cnt);
		}
		else {
			while (!st.empty()) {
				cnt--;
				q.push(st.top());
				st.pop();

				if (st.empty()) {
					q.push(x);
					result.push_back(0);
					break;
				}

				if (st.top() > x) {
					st.push(x);
					result.push_back(cnt);
					break;
				}
			}

			while (!q.empty()) {
				st.push(q.front());
				q.pop();
			}
		}

	}

	for (int num : result) {
		cout << num << ' ';
	}

	return 0;
}