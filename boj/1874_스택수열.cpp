#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 1. 1~n까지의 숫자와 배열의 해당하는 숫자보다 클 때까지 push
// 2. 배열의 숫자와 stack의 상위값과 동일한지 확인하여 pop
// 3. 만약 동일하지 않다면 stack으로 만들 수 없는 숫자이기에 종료.

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<char> result;
	int cnt = 1;
	stack<int> st;

	int n;
	cin >> n;

	while (n--)
	{
		int x;
		cin >> x;
		while (cnt <= x)
		{
			st.push(cnt++);
			result.push_back('+');
		}

		if (st.top() == x) {
			st.pop();
			result.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}

	}

	for (char ch : result) {
		cout << ch << '\n';
	}

	return 0;
}
