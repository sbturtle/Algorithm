#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int n, m;
int num[9];
bool isvis[9];

vector<string> vec;

vector<string> split(string input, string delimiter) 
{ 
	vector<string> ret;
	long long pos = 0;
	string token = "";

	while ((pos = input.find(delimiter)) != string::npos) 
	{ 
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);
	return ret;
}


bool cmp(string s1, string s2) {
	auto sp1 = split(s1, " ");
	auto sp2 = split(s2, " ");

	for (int i = 0; i < sp1.size(); i++)
	{
		if (sp1[i] == sp2[i])
			continue;
		else
			return stoi(sp1[i]) < stoi(sp2[i]);
	}
	return s1 < s2;
}

void func(string str, int cnt) {
	if (cnt == m) {
		vec.push_back(str);
	}

	for (int i = 0; i < n; i++)
	{
		if (isvis[i])
			continue;
		isvis[i] = true;
		func(str + to_string(num[i]) + ' ', cnt + 1);
		isvis[i] = false;
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	func("", 0);

	sort(vec.begin(), vec.end(), cmp);

	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (string str : vec)
		cout << str << '\n';
	return 0;
}