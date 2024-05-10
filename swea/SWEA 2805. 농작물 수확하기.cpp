#include <iostream>
using namespace std;

string arr[50];
int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> arr[i];	

	int result = 0;

	for (int i = 0; i <= n / 2; i++)	
		for (int j = (n / 2) - i; j <= (n / 2) + i; j++)		
			result+= arr[i][j] - '0';	

	for (int i = (n / 2) + 1; i < n; i++)	
		for (int j = i - (n / 2); j < (n / 2) + (n - i); j++)		
			result += arr[i][j] - '0';

	cout << result;
	
	return 0;
}