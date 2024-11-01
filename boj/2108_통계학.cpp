#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> vec;
	map<int, int> m;
	long long sum = 0;


	for (int i = 0; i < n; i++)
	{
		int num;		cin >> num;
		sum += num;
		m[num]++;
		vec.push_back(num);
	}

	vector<pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	sort(vec.begin(), vec.end());
	// ������ : N���� ������ ���� N���� ���� ��
	int tmp = round(sum / (float)n);
	cout << tmp << '\n';
	// �߾Ӱ�: N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
	cout << vec[n / 2] << '\n';

	// �ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��

	int num = v[0].first;
	int cnt = v[0].second;
	for (int i = 1; i < n; i++)
	{
		if (cnt == v[i].second) {
			num = v[i].first;
			break;
		}
		else
			break;
	}
	cout << num << '\n';
	// ���� : N���� ���� �� �ִ񰪰� �ּڰ��� ����
	cout << abs(vec[n - 1] - vec[0]);

	return 0;
}