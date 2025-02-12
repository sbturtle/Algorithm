#include<iostream>
#include <map>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;

	cin>>T;
    map<string, int> m;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int result = 0;
        int n1, n2;
        cin >> n1 >> n2;
        while(n1--) {
            string str;            cin >> str;
            m[str] = test_case;
        }
        while(n2--){
            string str;            cin >> str;
            if(m[str] == test_case)
                result++;
        }
		cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}