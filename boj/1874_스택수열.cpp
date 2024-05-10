#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 1. 1~n������ ���ڿ� �迭�� �ش��ϴ� ���ں��� Ŭ ������ push
// 2. �迭�� ���ڿ� stack�� �������� �������� Ȯ���Ͽ� pop
// 3. ���� �������� �ʴٸ� stack���� ���� �� ���� �����̱⿡ ����.

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
