#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n, p;	cin >> n >> p;
        
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += i;
            if(sum == p)
                sum--;
        }

		cout << sum << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}