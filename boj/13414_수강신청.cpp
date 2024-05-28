#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// map�� second ���� ������ �������� ������ �ؾ��ϱ⿡ compare�Լ� ����
bool compare(const pair<string, int> a, const pair<string, int> b) {
	return a.second < b.second;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	unordered_map<string, int> map;
	vector<pair<string, int>> vec;

	int k, l;
	cin >> k >> l;

	// �տ� �̹� ��ϵǾ��ִ���, index ���� ������ �ļ����� �̵�
	for (int i = 0; i < l; i++)
	{
		string n;	cin >> n;
		map[n] = i;
	}

	// unordered_map�� ������ �Ǿ����� �ʱ⿡, ������ ���� vector �迭�� ������
	for (auto m : map)
		vec.push_back(m);

	sort(vec.begin(), vec.end(), compare);

	// ����, �ִ� �����ο����� ��û�ο��� ���� ��츦 ����Ͽ�,
	// min(k(���� ���� �ο�), (int)vec.size()(��û�ο�))�� �����
	
	// vec.size()�� size_t ���� ��ȯ�ϱ⿡ int ��ȯ���־�� ��
	for (int i = 0; i < min(k, (int)vec.size()); i++)
		cout << vec[i].first << '\n';

	return 0;
}