#include<iostream>
#include<algorithm>
using namespace std;

int n, b;
int arr[21];
bool isvis[21];
int result;

void func(int idx, int sum) {    
    if(sum >= b) {
        if(sum < result)
            result = sum;
        return;
    }        
    
    for(int i = idx; i < n; i++) {
        if(isvis[i])
            continue;
        
        isvis[i] = true;
        func(i, sum + arr[i]);
        isvis[i] = false;
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	
	cin>>T;	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        result = 1'000'000'000;

        cin >> n >> b;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        func(0, 0);

		cout << '#' << test_case << ' ' << result - b << '\n';            
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}